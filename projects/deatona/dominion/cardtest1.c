/*Test Author: Adam Deaton
 *Test smithy card in dominion.c
 *smithy should increase hand by 3
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>
#include "unittests.h" 

void testSmithy(){
	int i;
	int posthand = 0;
	int prehand = 0;
	int * bonus = 0;
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	gamePtr->numPlayers = 2;
	gamePtr->handCount[1] = 10;
	gamePtr->deckCount[1] = 10;
	gamePtr->discardCount[1] = 10;
	gamePtr->whoseTurn = 1;
	gamePtr->playedCardCount = 5;
	//Test scoreFor hand
	for(i = 0; i < 10; i++){
		gamePtr->hand[1][i] = estate;
		gamePtr->deck[1][i] = smithy;
		gamePtr->discard[1][i] = curse;
	}
	prehand = gamePtr->handCount[1];
	//Call cardEffect to call smithy
	cardEffect(smithy,1,1,1,gamePtr, 10, bonus);
	posthand = gamePtr->handCount[1];
	//Posthand should be 3 more than prehand.
	if(prehand == posthand - 3){
		printf("Smithy functionality PASSED. Hand increased by 3\n");
	}
	else{
		printf("Smithy functionality FAILED. Hand increased by %d\n", posthand - prehand);
	}
}
/*
int main(int argc, char *argv[]){
	printf("cardtest1 Smithy\n");
	testSmithy();
	printf("cardtest1 complete\n");
	return 0;
}*/
