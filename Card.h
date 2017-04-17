#ifndef Card_h
#define Card_h

typedef struct{
	int number;
	char type; // ASCII code 3 = love, 4 = diamond,5 = keriting ,6 = spade
	//boolean choose;
	int value;
}CARD;

/************************************************************/
/*	Modul		: makeCard()								*/
/*	Description	: merupakan modul contructor membuat kartu	*/
/*	Note		: 											*/
/************************************************************/
void makeCard(CARD *C, int num);

/************************************************************/
/*	Modul		: printOpenedCard()							*/
/*	Description	: merupakan modul untuk menampilkan kartu	*/
/*				  yang terbuka								*/
/*	Note		: 											*/
/************************************************************/
void printOpenedCard(CARD C, int x, int y);

/************************************************************/
/*	Modul		: printOpenedCard()							*/
/*	Description	: merupakan modul untuk menampilkan kartu	*/
/*				  yang tertutup								*/
/*	Note		: 											*/
/************************************************************/
void printClosedCard(CARD C, int x, int y);

void printClosedSideCard(CARD C, int x, int y);

/************************************************************/
/*	Modul		: gotoxy									*/
/*	Description	: merupakan modul untuk mengubah letak		*/ 
/*				  kursor di console							*/
/*	Note		: 											*/
/************************************************************/
void gotoxy(int x, int y);

#endif
