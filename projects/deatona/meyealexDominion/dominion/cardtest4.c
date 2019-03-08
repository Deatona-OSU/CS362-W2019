
/*Test Author: Adam Deaton
 *Test Great Hall card in dominion.c
 *Great Hall should increase actions by 1 and cards by 1
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>
#include "unittests.h" 

void testGreatHall(){
	int i;
	int posthandCard = 0;
	int posthandAct = 0;
	int prehandCard = 0;
	int * bonus = 0;
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	gamePtr->numPlayers = 2;
	gamePtr->handCount[1] = 10;
	gamePtr->deckCount[1] = 10;
	gamePtr->discardCount[1] = 10;
	gamePtr->whoseTurn = 1;
	gamePtr->playedCardCount = 5;
	gamePtr->numActions = 0; //set actions to 0 zero to test village
	//Test nonsense deck and hand
	for(i = 0; i < 10; i++){
		gamePtr->hand[1][i] = estate;
		gamePtr->deck[1][i] = copper;
		gamePtr->discard[1][i] = curse;
	}
	prehandCard = gamePtr->handCount[1];
	//Call cardEffect to call smithy
	cardEffect(great_hall,1,1,1,gamePtr, 10, bonus);
	posthandAct = gamePtr->numActions;
	posthandCard = gamePtr->handCount[1] - prehandCard;
	//Result should be actions = 1 and posthandCard = 0 because a card was drawn and discarded
	if(posthandAct == 1 && posthandCard == 0){
		printf("Great Hall functionality PASSED. Actions increased by 1 and cards by 1.\n");
	}
	else{
		printf("Great Hall functionality FAILED. Actions =  %d; Cards Increased = %d\n", posthandAct, posthandCard - 1);
	}
}
/*
int main(int argc, char *argv[]){
	printf("cardtest4 Great Hall.\n");
	testGreatHall();
	printf("cardtest4 complete.\n");
	return 0;
}*/
