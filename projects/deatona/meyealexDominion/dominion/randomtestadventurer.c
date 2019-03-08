/* Author: Adam Deaton
 * Test Adventurer
 * 2-26-2019
 * Adventurer shold reveal cards from deck until 2 treasure cards are revealed.
 * Hand should increase by 2. Discarding all other revealed cards.
 */


#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>

//Random test for Adventurer Card
void randomTestAdv(){
	int i, j;
	int posthand = 0;
	int * bonus = 0;
	srand(time(NULL));
	int randomTurn = 0;
	int randomCard = 0;
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	for(j = 0; j < 10; j++){
		randomTurn = rand() % MAX_PLAYERS; 
		gamePtr->numPlayers = 4;
		gamePtr->handCount[randomTurn] = 7;
		gamePtr->deckCount[randomTurn] = MAX_HAND - 10;
		gamePtr->discardCount[randomTurn] = 10;
		gamePtr->whoseTurn = randomTurn;
		gamePtr->playedCardCount = 5;
		//Preseed deck with random cards
		for(i = 0; i < MAX_HAND - 10; i++){
			randomCard = rand() % 27; //random cards		
			gamePtr->deck[randomTurn][i] = randomCard;
		}
		//Preseed hand with no treasure cards
		for(i = 0; i < 10; i++){
			gamePtr->hand[randomTurn][i] = smithy;
			gamePtr->discard[randomTurn][i] = curse;
		}
		
		cardEffect(adventurer,1,1,1,gamePtr,10,bonus);
		//Verify there are now two treasure cards in hand and hand
		for(i = 0; i < gamePtr->handCount[randomTurn]; i++){
			if(gamePtr->hand[randomTurn][i] == copper || gamePtr->hand[randomTurn][i] == silver || gamePtr->hand[randomTurn][i] == gold){
				posthand = posthand + 1; //treasure found in hand
			}

		}
		if(posthand != 2){
			printf("FAILED player %d has %d treasure cards in hand.\n", randomTurn, posthand);
		}
		posthand = 0; //reset
	}
}  

int main(){
	printf("##RANDOM CARD 03 TEST ADVENTURER!##\n");
	randomTestAdv();
	printf("##TEST COMPLETED##\n");
	return 0;
}
