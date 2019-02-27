/* Author: Adam Deaton
 * Random Tester for Smithy
 * 2-26-2019
 * Smithy should increase cards by 3 
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>

//Random test for Smithy Card
//Test if number of players and number of cards in hand effect results
void randomTestSmithy(){
	int i, j;
	int posthand = 0;
	int prehand = 0;
	int * bonus = 0;
	srand(time(NULL));
	int randomTurn = 0;
	int randomHand = 0;
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	for(j = 0; j < 10; j++){
		randomHand = rand() % MAX_HAND - 3; //MAX HAND - 3 in order to draw 3
		randomTurn = rand() % MAX_PLAYERS; 
		gamePtr->numPlayers = 4;
		gamePtr->handCount[randomTurn] = randomHand;
		gamePtr->deckCount[randomTurn] = 10;
		gamePtr->discardCount[randomTurn] = 10;
		gamePtr->whoseTurn = randomTurn;
		gamePtr->playedCardCount = 5;
		//Preseed hand, deck, discard with any cards
		//Put a random number of card in hand to start
		for(i = 0; i < randomHand; i++){
			gamePtr->hand[randomTurn][i] = estate;
		}
		for(i = 0; i < 10; i++){
			gamePtr->deck[randomTurn][i] = smithy;
			gamePtr->discard[randomTurn][i] = curse;
		}
		prehand = gamePtr->handCount[randomTurn];
		cardEffect(smithy,1,1,1,gamePtr,randomHand,bonus);
		posthand = gamePtr->handCount[randomTurn];
		if(prehand != posthand - 3){
			printf("FAILED for player %d with %d starting handCount, after Smithy post handCount is %d.\n", randomTurn, randomHand, posthand);
		}
	}
}  

int main(){
	printf("##RANDOM CARD 01 TEST SMITH!##\n");
	randomTestSmithy();
	printf("##RANDOM CARD TEST 01 COMPLETE!##\n"); 
	
	return 0;
}

