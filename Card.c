#include "Card.h"
#include <stdio.h>
#include <windows.h>

/************************************************************/
/*	Modul		: makeCard()								*/
/*	Description	: merupakan modul contructor membuat kartu	*/
/*	Note		: 											*/
/************************************************************/
void makeCard(CARD *C, int num){
	if (num%13 == 1) (*C).number = 65;							// ASCII untuk 'A'
	else if (num%13 == 11) (*C).number = 74;					// ASCII untuk 'J'
	else if (num%13 == 12) (*C).number = 81;					// ASCII untuk 'Q'
	else if (num%13 == 0) (*C).number = 75;						// ASCII untuk 'K'
	else if (num%13 <= 10) (*C).number = num%13;
	
	(*C).type = (num-1)/13 + 3;
	
	//(*C).choose = choose;
	
	if (num%13 == 1) (*C).value = 11;
	else if (num%13 < 10) (*C).value = num%13;
	else (*C).value = 10;
}

/************************************************************/
/*	Modul		: printCard()								*/
/*	Description	: merupakan modul untuk menampilkan kartu	*/
/*	Note		: 											*/
/************************************************************/
void printOpenedCard(CARD C, int x, int y){
	gotoxy(x,y);
	printf("%c%c%c%c%c%c%c%c\n",201,196,196,196,196,196,196,187);
	gotoxy(x,y+1);
	printf("%c%c     %c\n",179,C.type,179);
	gotoxy(x,y+2);
	printf("%c      %c\n",179,179);
	gotoxy(x,y+3);
	printf("%c      %c\n",179,179);
	gotoxy(x+3,y+3);
	if (C.number > 10) printf("%c",C.number);
	else printf("%d",C.number);
	gotoxy(x,y+4);
	printf("%c      %c\n",179,179);
	gotoxy(x,y+5);
	printf("%c     %c%c\n",179,C.type,179);
	gotoxy(x,y+6);
	printf("%c%c%c%c%c%c%c%c",200,196,196,196,196,196,196,188);
}

void printClosedCard(CARD C, int x, int y){
	gotoxy(x,y);
	printf("%c%c%c%c%c%c%c%c\n",201,196,196,196,196,196,196,187);
	gotoxy(x,y+1);
	printf("%c%c%c%c%c%c%c%c\n",179,177,177,177,177,177,177,179);
	gotoxy(x,y+2);
	printf("%c%c%c%c%c%c%c%c\n",179,177,177,177,177,177,177,179);
	gotoxy(x,y+3);
	printf("%c%c%c%c%c%c%c%c\n",179,177,177,177,177,177,177,179);
	gotoxy(x,y+4);
	printf("%c%c%c%c%c%c%c%c\n",179,177,177,177,177,177,177,179);
	gotoxy(x,y+5);
	printf("%c%c%c%c%c%c%c%c\n",179,177,177,177,177,177,177,179);
	gotoxy(x,y+6);
	printf("%c%c%c%c%c%c%c%c",200,196,196,196,196,196,196,188);
}

void printClosedSideCard(CARD C, int x, int y) {
	gotoxy(x,y);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,196,196,196,196,196,196,196,196,196,196,196,187);
	gotoxy(x,y+1);
	printf("%c %c%c%c%c%c%c%c%c%c %c\n",179,177,177,177,177,177,177,177,177,177,179);
	gotoxy(x,y+2);
	printf("%c %c%c%c%c%c%c%c%c%c %c\n",179,177,177,177,177,177,177,177,177,177,179);
	gotoxy(x,y+3);
	printf("%c %c%c%c%c%c%c%c%c%c %c\n",179,177,177,177,177,177,177,177,177,177,179);
	gotoxy(x,y+4);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",200,196,196,196,196,196,196,196,196,196,196,196,188);
}

void gotoxy(int x, int y) {
	static HANDLE h = NULL;  
	if(!h)
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };  
	SetConsoleCursorPosition(h,c);
}
