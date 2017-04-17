#include "stack.h"
#include "Player.h"
#include "DriverCard.h"
#include <stdio.h>
#include <stdlib.h>

boolean quit,error;
LISTPLAYER listP;

int main(){
	
	//easy();
	
//	DisplayDeck(Deck);
//	system("pause");
//	
//	displayHandPlayer(P1, 69, 4);
//	updateScore(&P1);
//	printf("%d",P1.score);
	
	//printClosedSideCard(temp,60,60);

	//startGame();
//w	displayHand(P2,10,9);
	
	/*makeCard(&C,1);
	printOpenedCard(C,10,10);*/
	
	/*printOpenedCard(temp,17,1);
	printOpenedCard(temp,25,1);
	allCard(C);
	CreateList(&L1);
	CreateList(&L2);
	CreateList(&L3);
	CreateList(&L4);
	MakeStack(&Deck);
	MakeStack(&Trash1);
	MakeStack(&Trash2);
	MakeStack(&Trash3);
	MakeStack(&Trash4);
	
	printf("Jumlah pemain yang ingin bermain : ");
	scanf("%d",&player);
	printf("Ingin komputer ikut bermain (y/n) : ");
	scanf(" %c",&com);
	
	//randomPlayer(player,com,&jumlah,&giliran);
	PlayerCard(&L1,&L2,&L3,&L4,C,jumlah);
	DeckCard(&Deck,C,jumlah);
	DisplayCard(L1,L2,L3,L4,player,com);
	//PrintDeck(Deck);
	temp.type = cekType(L1);
	printf("%c",temp.type);*/
	
	quit = false;
	error = false;
	while (!quit && !error) {
		startGame();
	}
	return 0;
}

void startGame() {
	int menu,diff;
	LISTPLAYER listP;
	
	header();
	menuGame();
	menu = chooseMenu();
	
	switch(menu) {
		case 1:
//			selectNumbersOfPlayers(&listP);
			printDifficulty();
			diff = selectDifficulty();
	
			switch(diff) {
				case 1:			//easy
					playGame(1);
					break;
				case 2:			//medium
					playGame(2);
					break;
				case 3:			//hard
					playGame(3);
					break;
			}
			break;
		case 2:
			viewScoreboard();
			break;
		case 3:
			howToPlay();
			break;
		case 4:
			exitGame();
			break;
	}
}

void header() {
	gotoxy(35,10); printf(" ________ ________  ________  _________    ___    ___             ________  ________   _______      ");
	gotoxy(35,11); printf("|\\  _____\\\\   __  \\|\\   __  \\|\\___   ___\\ |\\  \\  /  /|           |\\   __  \\|\\   ___  \\|\\  ___ \\     ");
	gotoxy(35,12); printf("\\ \\  \\__/\\ \\  \\|\\  \\ \\  \\|\\  \\|___ \\  \\_| \\ \\  \\/  / /___________\\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\   __/|    ");
	gotoxy(35,13); printf(" \\ \\   __\\\\ \\  \\\\\\  \\ \\   _  _\\   \\ \\  \\   \\ \\    / /\\____________\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\_|/__  ");
	gotoxy(35,14); printf("  \\ \\  \\_| \\ \\  \\\\\\  \\ \\  \\\\  \\|   \\ \\  \\   \\/  /  /\\|____________|\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\ ");
	gotoxy(35,15); printf("   \\ \\__\\   \\ \\_______\\ \\__\\\\ _\\    \\ \\__\\__/  / /                  \\ \\_______\\ \\__\\\\ \\__\\ \\_______\\");
	gotoxy(35,16); printf("    \\|__|    \\|_______|\\|__|\\|__|    \\|__|\\___/ /                    \\|_______|\\|__| \\|__|\\|_______|");
	gotoxy(35,17); printf("                                         \\|___|/                                                    ");
}

void border(){
	int i;
	for(i=0;i<160;i++){
		gotoxy(1+i,1);printf("%c",196);	
	}
	
	for(i=0;i<160;i++){
		gotoxy(1+i,3);printf("%c",196);	
	}
	
	for(i=0;i<43;i++){
		gotoxy(1,i+1);printf("%c",179);
	}
	
	for(i=0;i<43;i++){
		gotoxy(160,i+1);printf("%c",179);
	}	
	
	for(i=0;i<160;i++){
		gotoxy(1+i,43);printf("%c",196);	
	}
}

void menuGame() {
	gotoxy(78,25);
	printf("Play");
	gotoxy(78,26);
	printf("View Scoreboard");
	gotoxy(78,27);
	printf("How To Play");
	gotoxy(78,28);
	printf("Quit Game");
}

int chooseMenu() {
	char inp;
	int x,y;
	
	x=76;
	y=25;
	gotoxy(x,y);
	printf("%c",(char)175);
	gotoxy(x,y);
	while ((inp=_getch())!=13) {
		switch(_getch()) {
			case 72:
				if (y!=25) {
					y--;
					printf(" ");
					gotoxy(x,y);
				}
				break;
			case 80:
				if (y!=28) {
					y++;
					printf(" ");
					gotoxy(x,y);
				}
				break;
		}
		printf("%c",(char)175);
		gotoxy(x,y);
	}
	return y - 24;
}

void playGame(int diff){
	
	switch(diff) {
		case 1:
			easy();
			break;
	}
}

int selectDifficulty(){
	char inp;
	int x,y;
	
	x=1;
	y=2;
	gotoxy(x,y);
	printf("%c",(char)175);
	gotoxy(x,y);
	while ((inp=_getch())!=13) {
		switch(_getch()) {
			case 72:
				if (y!=2) {
					y--;
					printf(" ");
					gotoxy(x,y);
				}
				break;
			case 80:
				if (y!=4) {
					y++;
					printf(" ");
					gotoxy(x,y);
				}
				break;
		}
		printf("%c",(char)175);
		gotoxy(x,y);
	}
	
	return y-1;
}

void printDifficulty(){
	system("cls");
	printf("Select Difficulty");
	gotoxy(2,2);
	printf("Easy");
	gotoxy(2,3);
	printf("Medium");
	gotoxy(2,4);
	printf("Hard");
}

void selectNumbersOfPlayers(LISTPLAYER *listP) {
	char inp;
	int x,y,i;
	
	x=7;
	y=2;
	gotoxy(x,y);
	printf("%c",(char)175);
	gotoxy(x,y);
	while ((inp=_getch())!=13) {
		switch(_getch()) {
			case 72:
				if (y!=2) {
					y--;
					printf(" ");
					gotoxy(x,y);
				}
				break;
			case 80:
				if (y!=4) {
					y++;
					printf(" ");
					gotoxy(x,y);
				}
				break;
		}
		printf("%c",(char)175);
		gotoxy(x,y);
	}
	/*
	PLAYER P;
	addr newPlayer;
	newPlayer = playerAlloc(P);
	for (i=0;i<y-1;i++) {
		makePlayer(P);
		insertPlayerLast(&(*listP),newPlayer);
	}*/
}

void viewScoreboard(){
	
}

void howToPlay(){
	
}

void exitGame() {
	quit = true;
}

void Win(){
	
		system("cls");
		border();
		gotoxy(40,20);printf("     ***     ***  ***    ***    ***     ***       *** *** ***   ***\n");
		gotoxy(40,21);printf("      ***   *** **   **  ***    ***     ***       *** *** ****  ***\n");
		gotoxy(40,22);printf("       *** *** **     ** ***    ***     ***       *** *** ***** ***\n");
		gotoxy(40,23);printf("        *****  **     ** ***    ***     *** ***** *** *** *********\n");
		gotoxy(40,24);printf("         ***   **     ** ***    ***     ****** ****** *** *** *****\n");
		gotoxy(40,25);printf("         ***    **   **   ***  ***      *****   ***** *** ***  ****\n");
		gotoxy(40,26);printf("         ***      ***      ******       ****     **** *** ***   ***\n");
	
	system("pause");
}

void Lose(){

		system("cls");
		border();
		gotoxy(40,20);printf("     ***     ***  ***    ***    ***     ***        ***     ******  *******\n");
		gotoxy(40,21);printf("      ***   *** **   **  ***    ***     ***      **   **  **       *******\n");
		gotoxy(40,22);printf("       *** *** **     ** ***    ***     ***     **     ** **       **     \n");
		gotoxy(40,23);printf("        *****  **     ** ***    ***     ***     **     **  *****   ****   \n");
		gotoxy(40,24);printf("         ***   **     ** ***    ***     ***     **     **       ** **     \n");
		gotoxy(40,25);printf("         ***    **   **   ***  ***      *******  **   **        ** *******\n");
		gotoxy(40,26);printf("         ***      ***      ******       *******    ***     ******  *******\n");

	system("pause");
}

void easy(){
	List L1, L2, L3, L4;
	Stack Deck, Trash1, Trash2, Trash3, Trash4;
	CARD C, temp;
	LISTPLAYER listP;
	PLAYER P1,P2,P3,P4;
	int player,giliran,jumlah,score, collect;
	int point1,point2,add,Throws;
	char com;
	
	system("cls");
	MakeStack(&Deck);
	DeckCard(&Deck,52);
	
	makePlayer(&P1);
	makePlayer(&P2);
	makePlayer(&P3);
	makePlayer(&P4);
	takeCard(&P1,&Deck);
	takeCard(&P2,&Deck);
	takeCard(&P3,&Deck);
	takeCard(&P4,&Deck);
	takeCard(&P1,&Deck);
	takeCard(&P2,&Deck);
	takeCard(&P3,&Deck);
	takeCard(&P4,&Deck);
	takeCard(&P1,&Deck);
	takeCard(&P2,&Deck);
	takeCard(&P3,&Deck);
	takeCard(&P4,&Deck);
	takeCard(&P1,&Deck);
	takeCard(&P2,&Deck);
	takeCard(&P3,&Deck);
	takeCard(&P4,&Deck);
	
	P1.score = 0; P3.score = 0;
	P2.score = 0; P4.score = 0;
	P1.win = false; P3.win = false;
	P2.win = false; P4.win = false;
	while(!isEmpty(Deck) && 
		P1.score != 41 && P2.score != 41 && P3.score != 41 && P4.score != 41 
		&& P1.win==false && P2.win == false && P3.win == false && P4.win == false){
		//	Player 1
		system("cls");
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		//printf("\n");
		gotoxy(30,44);printf("Ingin collect apa : ");
		gotoxy(30,45);printf("1. %c	3. %c",3,5);
		gotoxy(30,46);printf("2. %c	4. %c",4,6);
		gotoxy(30,47);printf("Pilihan : ");scanf("%d",&collect);
		system("cls");
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		gotoxy(30,44);printf("Ambil Kartu : ");
		gotoxy(30,45);printf("1. Deck");
		gotoxy(30,46);printf("2. Trash");
		gotoxy(30,47);printf("Pilihan : ");scanf("%d",&add);
		
		if(add == 1){
			if(isEmpty(Deck)){
				break;
			}else{
				PlayerAddCardDeck(&P1, &Deck);
			}
			
		}else{
			if(isEmpty(P1.pit)){
				printf("Trash masih kosong!\n");
				do{
					gotoxy(30,44);printf("Ambil Kartu : ");
					gotoxy(30,45);printf("1. Deck");
					gotoxy(30,46);printf("2. Trash");
					gotoxy(30,47);printf("Pilihan : ");scanf("%d",&add);
					if(add == 2){
						printf("Trash masih kosong!\n");
					}else{
						PlayerAddCardDeck(&P1, &Deck);
					}
				}while(add == 2);
			}else{
				PlayerAddCardTrash(&P1,&P1.pit);
			}
		}
		system("cls");
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
				
		gotoxy(30,44);printf("Urutan buang kartu : ");
		gotoxy(30,45);printf("Pilihan : ");scanf("%d",&Throws);
		ThrowCard(&P1,&P2.pit,Throws);
		system("cls");
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
				
		switch(collect){
			case 1 :
				point1 = updateScore(P1,3);break;
			case 2 :
				point1 = updateScore(P1,4);break;
			case 3 :
				point1 = updateScore(P1,5);break;
			case 4 :
				point1 = updateScore(P1,6);break;
		}
		P1.score = point1;
		gotoxy(30,44);printf("Score Anda : %d\n",P1.score);
		if(P1.score == 41){
			P1.win = true;
			break;
		}
		system("pause");
		
		system("cls");
		// Giliran komputer 1
		temp.type = cekType(P2.hand);
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		ComMedium(&P2, &P3, &Deck, 1, temp.type);
		system("pause");
		system("cls");
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		P2.score = updateScore(P2,temp.type);
		gotoxy(30,44);printf("Score Komputer 1 : %d \n",P2.score);
		if(P2.score == 41){
			P2.win = true;
			break;
		}
		system("pause");
		
		system("cls");
		// Giliran Komputer 2
		temp.type = cekType(P3.hand);
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		ComMedium(&P3, &P4, &Deck, 2, temp.type);
		system("pause");
		system("cls");
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		P3.score = updateScore(P3,temp.type);
		gotoxy(30,44);printf("Score Komputer 2 : %d \n",P3.score);
		if(P3.score == 41){
			P3.win = true;
			break;
		}
		system("pause");
		
		system("cls");
		// Giliran Komputer 3
		temp.type = cekType(P4.hand);
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		ComMedium(&P4, &P1, &Deck, 3, temp.type);
		system("pause");
		system("cls");
		
		border();
		gotoxy(2,2);printf("Score Pemain 1 : %d ",P1.score);
		gotoxy(24,2);printf("Score Komputer 1 : %d ",P2.score);
		gotoxy(48,2);printf("Score Komputer 2 : %d ",P3.score);
		gotoxy(72,2);printf("Score Komputer 3 : %d ",P4.score);
		gotoxy(140,2);printf("Dificulty : Easy");
		DisplayDeck(Deck);
		displayHandPlayer(P1,69,4);
		displayHandBottomComp(P3,69,35);
		displayHandSideComp(P4, 30, 15);
		displayHandSideComp(P2, 125, 15);
		displayTrashPlayer(P1,81,11);
		displayTrashCom1(P2,116,21);
		displayTrashCom2(P3, 81,28);
		displayTrashCom3(P4, 44,21);
		
		P4.score = updateScore(P4,temp.type);
		gotoxy(30,44);printf("Score Komputer 3 : %d \n",P4.score);
		if(P4.score == 41){
			P4.win = true;
			break;
		}
		system("pause");
	}
	if(isEmpty(Deck)){
		gotoxy(30,44);printf("Deck Habis!\n");
		
		if(P1.score > P2.score && P1.score > P3.score && P1.score > P4.score){
			Win();
		}else{
			Lose();
		}
	}else{
		if(P1.score == 41){
			Win();
		}else{
			Lose();
		}
	}
}
