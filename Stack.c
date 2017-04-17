#include "Stack.h"
#include "Card.h"
#include "List1.h"
#include "Random.h"
#include <stdio.h>
#include <stdlib.h>

void MakeStack(Stack *S){
// Membuat sebuah stack
	Top(*S) = Nil;
}

void Push(Stack *S, infotype X){
	//Memasukkan sebuah elemen ke stack
	address P;
	P = Alokasi(X);
	if(P != Nil){
		Next(P)=Top(*S);
		Top(*S)=P;
	}
}

void Pop(Stack *S, infotype *X){
	//Mengeluarkan sebuah elemen dari stack, isi dari elemen yang di-pop ditampung //di X
	address P;
	if(isEmpty(*S)){
		printf("underflow\n");
	}else{
		P = Top(*S);
		Top(*S)=Next(P);
		Next(P) = Nil;
		*X = Info(P);
		Dealokasi(&P);
	}
}

 
boolean isEmpty(Stack S){
	//Memeriksa apakah stack kosong
	return (S.Top == Nil);
}

int getStackSize(Stack S) {
	address P;
	int count;
	P = Top(S);
	count = 0;
	while (Next(P) != Nil){
		P = Next(P);
		count++;
	}
	return count;
}

void Display(Stack S){
	//Menampilkan isi stack
	int y=1;
	address P;
	P = Top(S);
	while(P!=Nil){
		printOpenedCard(Info(P),1,y);
		P = Next(P);
		y = y + 8;
	}
}

void DisplayDeck(Stack S) {
	int x=80,size,i,j;
	CARD C;
	size = getStackSize(S);
	if (size == 0) {
		for (i=0;i<8;i++) {
			for (j=0;j<7;j++) {
				gotoxy(x+i,20 + j);
				printf(" ");
			}
		}
	}
	else {
		for (i=0;i<=size/13;i++) {
			printClosedCard(C,x,20);
			x = x + 1;
		}
		for (i=0;i<7;i++) {
			gotoxy(x+7,20+i);
			printf(" ");	
		}	
	}
}

void DeckCard(Stack *S,int jml){
	CARD C;
	int i;
	
	srand (time (NULL));
    i = myRandom (jml);
    while (i >= 0) {
		makeCard(&C,i+1);
		Push(&(*S),C);
        i = myRandom (-1);
    }
}


int cekType(List L){
	// Mengecek berapa banyak kartu yang bertipe sama
	address P = First(L);
	int sumD=0,sumK=0,sumL=0,sumS=0;
	
	while(P!=Nil){
		if(Info(P).type == 3){
			sumL++;
		}else{
			if(Info(P).type == 4){
				sumD++;
			}else{
				if(Info(P).type == 5){
					sumK++;
				}else{
					sumS++;
				}
			}
		}
		P = Next(P);
	}
	if(sumL>sumD && sumL>sumK && sumL>sumS){
		return 3;
	}
	if(sumD>sumK && sumD>sumL && sumD>sumS){
		return 4;
	}
	if(sumK>sumD && sumK>sumL && sumK>sumS){
		return 5;
	}
	if(sumS>sumD && sumS>sumK && sumS>sumL){
		return 6;
	}
}


