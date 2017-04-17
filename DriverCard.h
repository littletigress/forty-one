#ifndef DriverCard_h
#define DriverCard_h

#include "boolean.h"

extern boolean error,quit;

void header();

void border();

void menuGame();

void startGame();

void playGame(int diff);

void viewScoreboard();

void howToPlay();

void exitGame();

void Win();

void Lose();

int chooseMenu();

int selectDifficulty();

void printDifficulty();

void selectNumbersOfPlayers(LISTPLAYER *listP);

void easy();

#endif
