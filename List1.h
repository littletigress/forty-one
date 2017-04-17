/* File :  list1.h   					*/
/* Desk :  deklarasi list  berkait dgn representasi     */
/* 	   fisik pointer; 				*/
/* 	   Representasi address dgn pointer 		*/
/* Oleh :  ANI RAHMANI / 23501007 	  		*/
/* Tgl  :  25/10/01					*/

/* List :  */

#ifndef List1_h
#define List1_h

#include "boolean.h"
#include "card.h"
#include <stdlib.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)

typedef CARD infotype;
typedef struct tElmtlist *address;		//address menjadi type data pointer yang menunjuk type data tElmtlist / node
typedef struct  tElmtlist   
{
	infotype info;
	address next;
	address prev;
}ElmtList;

/* Definisi  List                   */
/* List Kosong  :  First(L) = Nil   */
/* Setiap elemen dengan address P dapat diacu Info(P),Next(P)       */
/* Elemen terakhir  List :jika addressnya Last, maka next(Last)=Nil */

typedef struct 
{
	address First;
}List;

/* ** Prototype   **  */
/* ** Test List Kosong **  */
boolean ListEmpty(List  L);
/*  Mengirim true jika List kosong  */

/* Pembuatan  List Kosong  */
void CreateList(List *L);
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/

/* Manajeman  memory  			*/
address Alokasi(infotype  X);
 /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */

void Dealokasi(address *P);
/* I.S  :   P  terdefinisi         	*/
/* F.S  :   P dikembalikan ke  sistem 	*/
/*   	    Melakukan  dealokasi, pengembalian address  P */


/*   ** PENCARIAN SEBUAH ELEMEN LIST **   */

address Search1(List L, infotype  X);
/* Mencari apakah  ada elemen list dengan info(P)=X      */
/* Jika ada, mengirimkan  address elemen tersebut	 */
/* Jika  tidak ada, mengirimkan Nil 			 */

boolean FSearch(List L, address P);
/* Mencari apakah  ada elemen List yang  beralamat   P   */
/* Mengirimkan true jika ada, false jika tidak ada  	 */


address SearchPrec(List L, infotype X);
/* mencari apakah ada elemen List  yang beralamat P 	     */
/* Mnegirimkan address elemen sebelum elemen yang nilainya X */
/* Mencari apakah ada elemen List dengan info(P)=X	     */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P   */

/* ** PRIMITIF BERDASARKAN NILAI ** */

/* ** Penambahan Elemen ** */
void InsVFirst(List *L, infotype X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen pertama dengan nilai X jika     */
/*        Alokasi berhasil 				     */

void InsVLast(List *L, infotype X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */
/*	  Jika alokasi gagal: I.S = F.S			     */

/* *** Penghapusan Elemen  ***  */


void DelVFirst(List *L, infotype *X);
  /* I.S    : List tidak kosong  		                 */
  /* F.S    : Elemen pertama List dihapus, nilai info disimpan   */
  /*	      pada X dan alamat elemen pertama  di-dealokasi 	 */


void DelVLast(List *L, infotype *X);
  /* I.S    : List tidak kosong  		                 */
  /* F.S    : Elemen terakhir list dihapus, nilai info disimpan  */
  /*	      pada X dan alamat elemen terakhir di-dealokasi 	 */

/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(List *L, address P);
/* I.S   : Sembarang, P sudah dialokasi			*/
/* F.S   : Menambahkan elemen ber-address P, sebagai    */
/*         elemen pertama				*/

void InsertAfter(List *L, address P, address Prec);
/* I.S   : Prec pastilah elemen list dan bukan elemen terakhir  */
/*         P sudah dialokasi 					*/
/* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/

void InsertLast(List  *L, address P);
/* I.S   : Sembarang, P sudah dialokasi				*/
/* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/

/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst (List *L, address *P);
/* I.S   : List tidak kosong 	*/
/* F.S   : P adalah alamat elemen pertama list sebelum penghapusan */
/*         Elemen List berkurang satu (mungkin menjadi kosong)     */
/* First elemen yang baru adalah suksesor elemen pertama yang lama */

void DelP(List *L, infotype X);
/* I.S   : Sembarang  */
/* F.S   : Jika ada elemen  list beraddress P,dengan info (P)=X    */
/*         Maka P dihapus dari List dan di-dealokasi		   */
/*	   Jika tidak ada elemen List dengan info(P)=X, maka list  */
/*         tetap. List mungkin menjadi kosomg karena penghapusan   */

void DelLast(List *L, address *P);
/* I.S   : List tidak kosong  */
/* F.S   : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	   Elemen list berkurang 1 (mungkin menjadi kosong)	    */
/*         Last elemen baru adalah predessesor elemen pertama yang  */
/*         jika tidak ada					    */

void DelAfter(List *L, address *Pdel, address Prec);
/* I.S   : List tidak kosong, Prec adalah anggota List		*/
/* F.S   : Menghapus Next(Prec) :				*/
/*         Pdel adalah alamat elemen List yang dihapus		*/

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L);
/* I.S   : List mungkin kosong 	*/
/* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
/*         elemen list di-print					 */
/*         Jika list kosong, hanya menuliskan "List Kosong"	 */

int NbElmt(List L);
/* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */

infotype Max(List L);
/* Mengirimkan nilai info(P) yang maksimum */

address AdrMax(List L);
/* mengirimkan address P, dengan info (P) yang maksimum */

infotype Min(List L);
/* mengirimkan nilai info(P), yang minumum    */

address AdrMin(List L);
/* mengirimkan address P, dengan info(P) yang minimum */

float Average(List L);
/* mengirimkan nilai rata-rata info(P)	*/

/******************************************************/
/***   		PROSES TERHADAP LIST		    ***/
/******************************************************/
void DelAll(List *L);
/* Delete semua elemen list, dan alamat elemen di-dealokasi */

void InversList(List *L);
/* I.S   : sembarang  			*/
/* F.S   : elemen list  dibalik		*/
/*	   elemen terakhir menjadi elemen pertama, dst    */
/*	   Membalik elemen list, tanpa alokasi/dealokasi  */

List FInversList(List L);
/* mengirimkan list baru, hasil invers dari L 	*/

void CopyList(List L1, List *L2);
/* I.S   : L1 sembarang 				*/
/* F.S   : L1 dan L2 menunjuk ke list yang sama 	*/
/*         tidak ada alokasi/dealokasi yang elemen	*/

void PlayerCard(List *L1, List *L2, List *L3, List *L4, CARD *C, int jum);
// pembagian kartu untuh pemain

void DisplayCard(List L1, List L2, List L3, List L4, int player, char com);
// menampilkan kartu pemain
#endif
