#ifndef stack_h
#define stack_h

#include "List1.h"
#define Top(S) (S).Top
 
typedef struct Stack
{	
	address Top;
}Stack;
 
/* KELOMPOK KONSTRUKTOR */

void MakeStack(Stack *S);
// Membuat sebuah stack

void Push(Stack *S, infotype X);
//Memasukkan sebuah elemen ke stack
 
void Pop(Stack *S, infotype *X);
//Mengeluarkan sebuah elemen dari stack, isi dari elemen yang di-pop ditampung //di X
 
boolean isEmpty(Stack S);
//Memeriksa apakah stack kosong

int getStackSize(Stack S);
 
void Display(Stack S);
//Menampilkan isi stack

void DisplayDeck(Stack S);

void RandomDeck(Stack *D, int jml);
//Merandom kartu di deck
//jum = jumlah pemain

void PrintDeck(Stack D);
//	Mengambil kartu dari deck

int cekType(List L);
// Mengecek berapa banyak kartu yang bertipe sama


#endif

