#include "Player.h"
#include <stdio.h>
#include <string.h>

boolean isListPEmpty(LISTPLAYER L) {
	return (Head(L) == Nil);
}

void makePlayer(PLAYER *p) {
	p->score = 0;
	memset(p->name,'\0',sizeof(char)*20);
	MakeStack(&p->pit);
	CreateList(&p->hand);
	p->win = false;
}

int updateScore(PLAYER player,char type) {
	address p;
	p = First(player.hand);
	int sum1 = 0, sum2 = 0, sum, value;
	
	while(p!=Nil){
		switch(Info(p).number){
			case 10 :
			case 74 :
			case 81 :
			case 75 :
				value = 10;
				break;
			case 65 :
				value = 11;
				break;
			default :
				value = Info(p).number;
				break;
		}
		if(Info(p).type == type){
			sum1 += value;
		}else{
			sum2 += value;
		}
		p = Next(p);
	}
	sum = sum1 - sum2;
	return sum;
}

void setName(PLAYER *p, char name[]) {
	strcpy(p->name,name);
}

void getName(PLAYER p, char name[]) {
	strcpy(name,p.name);
}

int getScore(PLAYER p) {
	return p.score;
}

boolean isWin(PLAYER p) {
	return (p.win==true);
}

boolean isSame(PLAYER p1, PLAYER p2) {
	boolean same = false;
	if (p1.score == p2.score) {
		if (strcmp(p1.name,p2.name) == 0) same = true;
	}
	return same;
}

void makeListPlayer(LISTPLAYER *L) {
	Head(*L) = Nil;
	Tail(*L) = Nil;
}

addr playerAlloc(PLAYER p) {
	addr P;
	P = (addr) malloc(sizeof(nodePlayer));
	if (P == Nil) {
		printf("Alokasi Gagal!");
	}
	else return P;
}

void insertPlayerLast(LISTPLAYER *L, PLAYER player) {
	addr newAddr,p1;
	newAddr = playerAlloc(player);
	if (newAddr != Nil) {
		if (isListPEmpty(*L)) {
			Head(*L) = newAddr;
			Tail(*L) = newAddr;
			NextPlayer(newAddr) = Nil;
		}
		else {
			p1 = Head(*L);
			while (NextPlayer(p1) != Nil) {
				p1 = NextPlayer(p1);
			}
			NextPlayer(p1) = newAddr;
			Next(newAddr) = Head(*L);
			Tail(*L) = newAddr;
		}
	}
}

void deletePlayer(LISTPLAYER *L, PLAYER player) {
	
}

void takeCard(PLAYER *P, Stack *Deck) {
	CARD C;
	Pop(&(*Deck),&C);
	InsVLast(&P->hand,C);
}

void displayHandPlayer(PLAYER player, int x, int y) {
	int i;
	address P=First(player.hand);
	if( P==Nil) 
	{
		printf("Belum dapat kartu!\n");
	} 
	else 
	{
	do 
		{
			printOpenedCard(Info(P),x,y);
    		P=Next(P);
      		x+=8;
      		i++;
      	} while(P!=Nil);
  	}
}

void displayHandBottomComp(PLAYER player, int x, int y) {
	int i;
	address P=First(player.hand);
	if( P==Nil) 
	{
		printf("Belum dapat kartu!\n");
	} 
	else 
	{
	do 
		{
			printClosedCard(Info(P),x,y);
    		P=Next(P);
      		x+=8;
      		i++;
      	} while(P!=Nil);
  	}
}

void displayHandSideComp(PLAYER player, int x, int y) {
	int i;
	address P=First(player.hand);
	if( P==Nil) 
	{
		printf("Belum dapat kartu!\n");
	} 
	else 
	{
	do 
		{
			printClosedSideCard(Info(P),x,y);
    		P=Next(P);
      		y+=5;
      		i++;
      	} while(P!=Nil);
  	}
}

void displayTrashPlayer(PLAYER player, int x,int y){
	address P = Top(player.pit);
	if(P==Nil){
		printf(" ");
	}else{
		printOpenedCard(Info(P),x,y);
	}
}

void displayTrashCom1(PLAYER player, int x,int y){
	address P = Top(player.pit);
	if(P==Nil){
		printf(" ");
	}else{
		printOpenedCard(Info(P),x,y);
	}
}

void displayTrashCom2(PLAYER player, int x,int y){
	address P = Top(player.pit);
	if(P==Nil){
		printf(" ");
	}else{
		printOpenedCard(Info(P),x,y);
	}
}

void displayTrashCom3(PLAYER player, int x,int y){
	address P = Top(player.pit);
	if(P==Nil){
		printf(" ");
	}else{
		printOpenedCard(Info(P),x,y);
	}
}
	
void PlayerAddCardDeck(PLAYER *p, Stack *Deck){
	CARD temp;
	printf("ambil dari deck\n");
	Pop(&(*Deck),&temp);
	InsVLast(&(*p).hand,temp);
}

void PlayerAddCardTrash(PLAYER *p, Stack *Trash){
	CARD temp;
	printf("ambil dari sampah\n");
	Pop(&(*Trash),&temp);
	InsVLast(&(*p).hand,temp);
}

void ThrowCard(PLAYER *P, Stack *Trash, int urutan){
	address p,q;
	CARD temp;
	p = First((*P).hand);
	switch(urutan){
		case 1 :
			DelVFirst(&(*P).hand,&temp);
			Push(&(*Trash),temp);
			break;
		case 2 :
			p = Next(p);
			temp.number = Info(p).number;
			temp.type = Info(p).type;
			DelP(&(*P).hand,temp);
			Push(&(*Trash),temp);
			break;
		case 3 :
			p = Next(Next(p));
			temp.number = Info(p).number;
			temp.type = Info(p).type;
			DelP(&(*P).hand,temp);
			Push(&(*Trash),temp);
			break;
		case 4 :
			p = Next(Next(p));
			q = Next(p);
			temp.number = Info(q).number;
			temp.type = Info(q).type;
			DelP(&(*P).hand,temp);
			Push(&(*Trash),temp);
			break;
		case 5 :
			DelVLast(&(*P).hand,&temp);
			Push(&(*Trash),temp);
			break;
	}	
}

/* aritifical inteligence*/

void ComAddCardDeck(PLAYER *P, Stack *Deck,int urutan){
	CARD temp;
	gotoxy(30,44);printf("Komputer %d ambil dari Deck\n",urutan);
	Pop(&(*Deck),&temp);
	InsVLast(&(*P).hand,temp);
}

void ComAddCardTrash(PLAYER *P, int urutan){
	CARD temp;
	gotoxy(30,44);printf("Komputer %d ambil dari Trash\n",urutan);
	Pop(&(*P).pit,&temp);
	InsVLast(&(*P).hand,temp);
}

void ComThrowCard(PLAYER *P, Stack *Deck, PLAYER *P2, char type,int urutan){
	address p;
	CARD temp;
	p = First((*P).hand);
	if(Info(p).type != type){
		gotoxy(30,45);printf("Komputer %d buang kartu pertama\n",urutan);
		DelVFirst(&(*P).hand,&temp);
		Push(&(*P2).pit,temp);
	}else{
		p = Next(p);
		if(Info(p).type != type){
			gotoxy(30,45);printf("Komputer %d buang kartu kedua\n",urutan);
			temp.number = Info(p).number;
			temp.type = Info(p).type;
			DelP(&(*P).hand,temp);
			Push(&(*P2).pit,temp);
		}else{
			p = Next(p);
			if(Info(p).type != type){
				gotoxy(30,45);printf("Komputer %d buang kartu ketiga\n",urutan);
				temp.number = Info(p).number;
				temp.type = Info(p).type;
				DelP(&(*P).hand,temp);
				Push(&(*P2).pit,temp);
			}else{
				p = Next(p);
				if(Info(p).type != type){
					gotoxy(30,45);printf("Komputer %d buang kartu keempat\n",urutan);
					temp.number = Info(p).number;
					temp.type = Info(p).type;
					DelP(&(*P).hand,temp);
					Push(&(*P2).pit,temp);
				}else{
					p = Next(p);
					gotoxy(30,45);printf("Komputer %d buang kartu kelima\n",urutan);
					DelVLast(&(*P).hand,&temp);
					Push(&(*P2).pit,temp);
				}
			}
		}
	}
}

void ComEasy(PLAYER *P1,PLAYER *P2, Stack *Deck,int urutan){
	CARD temp;
	sleep(1);
	ComAddCardDeck(&(*P1),&(*Deck),urutan);
	gotoxy(30,44);printf("Komputer %d ambil dari deck",urutan);
	sleep(3);
	DelVFirst(&(*P1).hand,&temp);
	Push(&(*P2).pit,temp);
	gotoxy(30,45);printf("Komputer %d buang kartu pertama\n",urutan);
	sleep(3);
}

void ComMedium(PLAYER *P1, PLAYER *P2, Stack *Deck,int urutan,char type){
	
	address P;
	P = Top((*P1).pit);
	if(isEmpty((*P1).pit)){
		ComAddCardDeck(&(*P1),&(*Deck),urutan);
		sleep(2);
	}else{
		if(Info(P).type == type){
			ComAddCardTrash(&(*P1),urutan);
			sleep(2);
		}else{
			ComAddCardDeck(&(*P1),&(*Deck),urutan);
			sleep(2);
		}	
	}
	ComThrowCard(&(*P1), &(*Deck), &(*P2), type,urutan);
	sleep(3);
}
