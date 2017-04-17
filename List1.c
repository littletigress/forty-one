/* File :  list1.c            */
/* Desk :  body list  berkait dgn representasi fisik    */
/*         pointer;           */
/*     Representasi address dgn pointer     */
/*     infotype adalah integer      */
/* Oleh :  ANI RAHMANI / 23501007         */
/* Tgl  :  25/10/01         */

/* body dari List1.h   */
#include "Card.h"
#include "List1.h"
#include <stdio.h>
#include <stdlib.h>

/* ** Prototype   **  */
/* ** Test List Kosong **  */
boolean ListEmpty(List  L)
{  /*  Mengirim true jika List kosong  */

    return(First(L)==Nil);
}

/* Pembuatan  List Kosong  */
void CreateList(List *L)
{  /* I.S  :  Sembarang       */
   /* F.S  :  Terbentuk  List kosong    */
   First(*L)=Nil;
}

/* ********  MANAJEMEN MEMORY  ********* */
address Alokasi(infotype  X)
{/* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Next(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil         */
   address P;
   P=(address)malloc(sizeof(ElmtList));
   if(P!=Nil) 
   { /* Berhasil  */
         Info(P)=X;
         Next(P)=Nil;
         Prev(P)=Nil;
   }
   return P;
}

void Dealokasi(address *P)
{ /* I.S  : P terdefinisi             */
  /* F.S  : P dikembalikan ke  sistem       */
  /*        Melakukan dealokasi, pengembalian address P */
    Next(*P)=Nil;
    Prev(*P)=Nil;
    free(*P);
}

/*   ** PENCARIAN SEBUAH ELEMEN LIST **   */



boolean FSearch(List L, address P)
{ /* Mencari apakah ada elemen List yang beralamat P  */
  /* Mengirimkan true jika ada, false jika tidak ada  */
  /* List Tidak mungkin kosong  */

  address PTemp=First(L);
  boolean found=false;

  while((PTemp!=Nil)&&(!found))
  {
     if(PTemp==P) 
	 {
   		found=true;
     }
     else
     {
   		PTemp=Next(PTemp);
     }

  } /* PTemp==Nil or found / ketemu */
  return found;
}



/* ** PRIMITIF BERDASARKAN NILAI ** */

/* ** Penambahan Elemen ** */
void InsVFirst(List *L, infotype X)
{  /* I.S  : L mungkin kosong          */
   /* F.S  : Melakukan alokasi sebuah elemen dan             */
   /*        menambahkan elemen pertama dengan nilai X jika  */
   /*        Alokasi berhasil              */
   address P=Alokasi(X);
   if(P!=Nil) 
   { /* Alokasi Berhasil */
      InsertFirst(&(*L),P);
   }
}

void InsVLast(List *L, infotype X)
{ /* I.S  : L mungkin kosong          */
  /* F.S  : Melakukan alokasi sebuah elemen dan                */
  /*        menambahkan elemen list di akhir; elemen terakhir  */
  /*        yang baru bernilai X jika alokasi berhasil,        */
  /*      Jika alokasi gagal: I.S = F.S          */

     address P=Alokasi(X);
     if(P!=Nil)
     {  
	 	InsertLast(&(*L),P);
	 }
}

/* *** Penghapusan Elemen  ***  */

void DelVFirst(List *L, infotype *X)
{ /* I.S    : List tidak kosong                      */
  /* F.S    : Elemen pertama List dihapus, nilai info disimpan   */
  /*        pada X dan alamat elemen pertama  di-dealokasi   */
  /* Kamus */
  address  P;

  DelFirst(&(*L),&P); /* Hapus elemem pertama, blm didealokasi */
  *X=Info(P);     /* info dari First disimpan di X       */
  Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{  /* I.S    : List tidak kosong                       */
   /* F.S    : Elemen terakhir list dihapus, nilai info disimpan */
   /*       pada X dan alamat elemen terakhir di-dealokasi   */
   address P;
   DelLast(&(*L),&P);
        /* Hapus Elemen Terakhir, addressnya disimpan di P, */
        /* Belum diDealokasi, masih bisa dibaca isinya      */
   *X=Info(P);  /* Info dari address P, ditampung  */
   Dealokasi(&P);
}


/* *******  PRIMITIF BERDASARKAN ALAMAT ********  */
/* Penambahan Elemen Berdasarkan Alamat     */

void InsertFirst(List *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi   */
  /* F.S   : Menambahkan elemen ber-address P, sebagai  */
  /*         elemen pertama       */
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter(List *L, address P, address Prec)
{ /* I.S   : Prec pastilah elemen  dan bukan elemen terakhir  */
  /*         P sudah dialokasi            */
  /* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/
  Next(P)=Next(Prec);
  Prev(P)=Prec;
  Next(Prec)=P;
  Prev(Next(Prec))=P;
}

void InsertLast(List  *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi     */
  /* F.S   : P ditambahkan  sebagai elemen terakhir yang baru */

      address Last;
      if(ListEmpty(*L)) 
	  { /* Jika kosong, Insert elemen pertama */
     		InsertFirst(&(*L),P);
      }
      else 
	  { /* tdk kosong */
      		Last=First(*L);
            while(Next(Last)!=Nil)  
			{ /* menuju ke last */
            Last=Next(Last);
		    } /* Next(Last)==Nil */

		    Next(Last)=P;
		    Prev(P)=Last;
      }
}

/* ****** PENGHAPUSAN SEBUAH ELEMEN *********   */
void DelFirst (List *L, address *P)
{ /* I.S   : List tidak kosong  */
  /* F.S   : P adalah alamat elemen pertama list sebelum penghapusan */
  /*         Elemen List berkurang satu (mungkin menjadi kosong)     */
  /* First elemen yang baru adalah suksesor elemen pertama yang lama */

      *P=First(*L);
      First(*L)=Next(First(*L));
      Next(*P)=Nil;
 }

void DelP(List *L, infotype X)
{ /* I.S   : Sembarang  */
  /* F.S   : Jika ada elemen  list beraddress P,dengan info (P)=X    */
  /*         Maka P dihapus dari List dan di-dealokasi         */
  /*       Jika tidak ada elemen List dengan info(P)=X, maka list  */
  /*         tetap. List mungkin menjadi kosomg karena penghapusan   */
    address  P=First(*L);
    address prev;

    while((Next(P)!=Nil) && (Info(P).number!=X.number))
	{
		prev=P;
        P=Next(P);
    } /*Next(P)=Nil or Info(P)= X */

    if(Info(P).number==X.number) 
	{
		Next(prev) = Next(P);
		Next(P)=Nil;
    }
}

void DelLast(List *L, address *P)
{ /* I.S   : List tidak kosong  */
  /* F.S   : P adalah alamat elemen terakhir list sebelum penghapusan */
  /*       Elemen list berkurang 1 (mungkin menjadi kosong)       */
  /*         Last elemen baru adalah predessesor elemen pertama yang  */
  /*         lama, jika  ada                */

  /* Kamus */
  address Last,PrecLast;

  Last=First(*L);
  /* dari catatan di kelas */
  if(Next(Last)==Nil)  
  { /* hanya 1 elemen */
    DelFirst(&(*L),&(Last));
  }
  else 
  { /* Lebih dr 1 elemen */
    PrecLast=Nil;
    while(Next(Last)!=Nil)
	{   /* Maju sampai elemen terakhir */
      PrecLast=Last;
      Last=Next(Last);
    } /* Next(Last)=Nil */
    *P=Last;
    Next(PrecLast)=Nil;
  }
}


void DelAfter(List *L, address *Pdel, address Prec)
{  /* I.S   : List tidak kosong, Prec adalah anggota List */
   /* F.S   : Menghapus Next(Prec) :        */
   /*         Pdel adalah alamat elemen List yang dihapus */
  *Pdel=Next(Prec);
  Next(Prec)=Next(*Pdel);
}


/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L)
{ /* I.S   : List mungkin kosong  */
  /* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
  /*         elemen list di-print            */
  /*         Jika list kosong, hanya menuliskan "List Kosong"    */
  int i,x=1;
  address P=First(L);
  if( P==Nil) 
  {
      printf("List Kosong !\n");
  } 
  else 
  { /* List tidak kosong */
      do 
	  {
      	//printOpenedCard(Info(P),x,y);
      	P=Next(P);
      	x+=5;
      	i++;
      } while(P!=Nil);
  }
  printf("\n");
}

int NbElmt(List L)
{ /* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */
  address P;
  int NbEl=0;
  if(ListEmpty(L))
  {
  	return 0;
  } 
  else 
  { /* Tidak kosong */
    P=First(L);
    do 
	{
    	NbEl++;
        P=Next(P);
    }while(P!=Nil);
  }
  return NbEl;
}



/******************************************************/
/***      PROSES TERHADAP LIST        ***/
/******************************************************/
void DelAll(List *L)
{ /* Delete semua elemen list, dan alamat elemen di-dealokasi */
   infotype X;
   while(!ListEmpty(*L)) 
   {
    DelVFirst(&(*L),&X);
   } /* kosong */
}

void InversList(List *L)
{ /* I.S   : sembarang        */
  /* F.S   : elemen list  dibalik   */
  /*     elemen terakhir menjadi elemen pertama, dst    */
  /*     Membalik elemen list, tanpa alokasi/dealokasi  */

  /* Kamus */
  List LTemp;
  address P;

  /* Algoritma */
  CreateList(&LTemp);
  while(First(*L)!=Nil)
  {
    DelFirst(&(*L),&P);
    Next(P)=Nil;
    InsertFirst(&LTemp,P);
  }
  First(*L)=First(LTemp);
}

List FInversList(List L)
{ /* mengirimkan list baru (LB), hasil invers dari L  */
  /* dengan Alokasi           */

  /* List L tidak kosong ; min 1 elemen       */

  /* Update: Bugfix, mulanya baris setelah if(PB!=Nil) statement yg dieksekusi
  bukan InsertFirst, tapi InsertLast, sehingga List yang dihasilkan tidak
  jadi invers.

  24-03-2015 @saifulwebid - JTK 2014 :) */

  /* Kamus */
  List LB;
  address P,PB;
  infotype X;

  /* Algoritma */
  P=First(L);
  CreateList(&LB);
  do 
  {
    X=Info(P);
    PB=Alokasi(X);
    if(PB!=Nil) 
	{ /* berhasil alokasi */
        InsertFirst(&LB,PB);
        P=Next(P);
    } 
	else 
	{ /* alokasi gagal */
        DelAll(&LB);
        First(LB)=Nil;
    }
  } while (P!= Nil);
   return LB;
}

void CopyList(List L1, List *L2)
{ /* I.S   : L1 sembarang         */
  /* F.S   : L1 dan L2 menunjuk ke list yang sama   */
  /*         tidak ada alokasi/dealokasi    */
   *L2=L1;
}

/*void DisplayCard(List L1, List L2, List L3, List L4, int player, char com){
	// menampilkan kartu pemain
	switch(player){
		case 1 : 
		
			//system("cls");
			printf("\n~~Pembagian Kartu~~");
			
			// Menampilkan Kartu pemain pertama
			printf("\n\nKartu pemain 1 : ");
			PrintInfo(L1);
			
			// Menampilkan Kartu pemain kedua
			printf("\n\nKartu pemain 2 : ");
			PrintInfo(L2);
			break;
		case 2 :
			if(tolower(com)=='y'){
				//system("cls");
				printf("\n~~Pembagian Kartu~~");
				
				// Menampilkan Kartu pemain pertama
				printf("\n\nKartu pemain 1 : ");
				PrintInfo(L1);
				
				// Menampilkan Kartu pemain kedua
				printf("\n\nKartu pemain 2 : ");
				PrintInfo(L2);
				
				// Menampilkan Kartu pemain kedua
				printf("\n\nKartu pemain 3 : ");
				PrintInfo(L3);
			}else{
				//system("cls");
				printf("\n~~Pembagian Kartu~~");
				
				// Menampilkan Kartu pemain pertama
				printf("\n\nKartu pemain 1 : ");
				PrintInfo(L1);
				
				// Menampilkan Kartu pemain kedua
				printf("\n\nKartu pemain 2 : ");
				PrintInfo(L2);
			}
			break;
	}
}*/
