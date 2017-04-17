#ifndef Player_h
#define Player_h

#include "List1.h"
#include "Stack.h"

#define Head(L) (L).Head
#define Tail(L) (L).Tail
#define NextPlayer(L) L->next

typedef struct {
	int score;
	char name[20];
	Stack pit;
	List hand;
	boolean win;
}PLAYER;

typedef struct node *addr;

typedef struct node {
	PLAYER player;
	addr next;
}nodePlayer;

typedef struct {
	addr Head;
	addr Tail;
}LISTPLAYER;

boolean isListPEmpty(LISTPLAYER L);

void makePlayer(PLAYER *p);

int updateScore(PLAYER player,char type);

void setName(PLAYER *p, char name[]);

void getName(PLAYER p, char name[]);

int getScore(PLAYER p);

boolean isWin(PLAYER p);

boolean isSame(PLAYER p1, PLAYER p2);

void makeListPlayer(LISTPLAYER *L);

addr playerAlloc(PLAYER p);

void insertPlayerLast(LISTPLAYER *L, PLAYER player);

void insertPlayer(LISTPLAYER *L, PLAYER player);

void deletePlayer(LISTPLAYER *L, PLAYER player);

void printInfoPlayer(PLAYER p);

void sortListPlayer(LISTPLAYER *L);

void takeCard(PLAYER *P, Stack *Deck);

void displayHandPlayer(PLAYER P, int x, int y);

void displayHandBottomComp(PLAYER player, int x, int y);

void displayHandSideComp(PLAYER player, int x, int y);

void displayTrashPlayer(PLAYER player, int x,int y);

void displayTrashCom1(PLAYER player, int x,int y);

void displayTrashCom2(PLAYER player, int x,int y);

void displayTrashCom3(PLAYER player, int x,int y);

void PlayerAddCardDeck(PLAYER *p, Stack *Deck);

void PlayerAddCardTrash(PLAYER *p, Stack *Trash);
// Mengambil kartu dari sampah

void ThrowCard(PLAYER *P, Stack *Trash, int urutan);
//membuang kartu ke tempat sampah lawan


/* aritifical inteligence*/

void ComAddCardDeck(PLAYER *P, Stack *Deck,int urutan);

void ComAddCardTrash(PLAYER *P, int urutan);

void ComThrowCard(PLAYER *P, Stack *Deck, PLAYER *P2, char type,int urutan);

void ComEasy(PLAYER *P1,PLAYER *P2, Stack *Deck,int urutan);

void ComMedium(PLAYER *P1, PLAYER *P2, Stack *Deck,int urutan,char type);

#endif
