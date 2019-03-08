/*Test Author: Adam Deaton
 *Test advemturer card in dominion.c
 *adventurer should increase treasure by 2
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>
#include "unittests.h" 

void testAdventurer(){
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
	//Test scoreFor hand
	for(i = 0; i < 10; i++){
		gamePtr->hand[1][i] = estate;
		gamePtr->deck[1][i] = copper;
		gamePtr->discard[1][i] = curse;
	}
	
	//Call cardEffect to call smithy
	cardEffect(adventurer,1,1,1,gamePtr, 10, bonus);
	//Count how many copper
	for(i = 0; i < gamePtr->handCount[1]; i++){
		if(gamePtr->hand[1][i] == copper){
			posthand = posthand + 1;
		}
	}
	
	if(posthand == 2){
		printf("Adventurer functionality PASSED. Treasure increased by 2.\n");
	}
	else{
		printf("Adventurer functionality FAILED. Treasure =  %d\n", posthand);
	}
}
/*
int main(int argc, char *argv[]){
	printf("cardtest2 Adventurer\n");
	testAdventurer();
	printf("cardtest2 complete\n");
	return 0;
}*/
