/* Author: Adam Deaton
 * Random Tester for Village
 * Village should increase action by 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>

//Random test for Village Card
//Village should increase hand by one and acctions by two
void randomTestVillage(){
	int i, j;
	int posthand = 0;
	int prehand = 0;
	int posthandAction = 0;
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
		gamePtr->numActions = 0;
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
		cardEffect(village,1,1,1,gamePtr,randomHand,bonus);
		posthand = gamePtr->handCount[randomTurn];
		if(prehand != posthand){
			printf("FAILED Draw +1 for player %d with %d starting handCount, after Village post handCount is %d.\n", randomTurn, randomHand, posthand);
		}
		//Reset actions to insure that drawCard did not effect it.
		gamePtr->numActions = 0;	
		cardEffect(village,1,1,1,gamePtr,randomHand,bonus);
		posthandAction = gamePtr->numActions;
		if(posthandAction != 2){
			printf("FAILED Action +2 for player %d with %d starting handCount. numActions = %d.\n", randomTurn, randomHand, gamePtr->numActions);
			
		}
	}
}  

int main(){
	printf("##RANDOM CARD 02 TEST Village##\n");
	randomTestVillage();
	printf("##RANDOM CARD TEST 02 COMPLETE!##\n"); 
	
	return 0;
}

