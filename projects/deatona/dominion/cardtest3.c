/*Test Author: Adam Deaton
 *Test village card in dominion.c
 *village should increase actions by 2
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>
#include "unittests.h"
 
 

void testVillage(){
	int i;
	int posthand = 0; //zero treasure
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
	
	//Call cardEffect to call smithy
	cardEffect(village,1,1,1,gamePtr, 10, bonus);
	posthand = gamePtr->numActions;
	
	if(posthand == 2){
		printf("Village functionality PASSED. Actions increased by 2.\n");
	}
	else{
		printf("Village functionality FAILED. Actions =  %d\n", posthand);
	}
}
/*
int main(int argc, char *argv[]){
	printf("cardtest3 Village\n");
	testVillage();
	printf("cardtest3 complete.\n");
	return 0;
}*/
