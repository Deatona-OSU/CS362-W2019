/*Test Author: Adam Deaton
 *Test getWinners function in dominion.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include "unittests.h"
 

void testGetWinners(){
	int i;
	int players[MAX_PLAYERS];
	//Plater scores
	int playerA = 0;
	int playerB = 0;
	int playerC = 0;
	//int playerD = 0;
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	gamePtr->numPlayers = 4;
	
	//Player 1
	gamePtr->handCount[0] = MAX_HAND;
	gamePtr->deckCount[0] = MAX_DECK;
	gamePtr->discardCount[0] = MAX_DECK;
	for(i = 0; i < MAX_HAND; i = i + 5){
		gamePtr->hand[0][i] = curse;
		gamePtr->deck[0][i] = curse;
		gamePtr->discard[0][i] = curse;
		gamePtr->hand[0][i+1] = estate;
		gamePtr->deck[0][i+1] = estate;
		gamePtr->discard[0][i+1] = estate;
		gamePtr->hand[0][i+2] = duchy;
		gamePtr->deck[0][i+2] = duchy;
		gamePtr->discard[0][i+2] = duchy;
		gamePtr->hand[0][i+3] = province;
		gamePtr->deck[0][i+3] = province;
		gamePtr->discard[0][i+3] = province;
		gamePtr->hand[0][i+4] = great_hall;
		gamePtr->deck[0][i+4] = great_hall;
		gamePtr->discard[0][i+4] = great_hall;
		playerA = playerA + ((3 + 6 + 1) * 3);
	}
	printf("Player 1 score = %d\n", scoreFor(0,gamePtr));
	//Player 2
	gamePtr->handCount[1] = MAX_HAND;
	gamePtr->deckCount[1] = MAX_DECK;
	gamePtr->discardCount[1] = MAX_DECK;
	//Test scoreFor hand
	for(i = 0; i < MAX_HAND; i = i + 5){
		gamePtr->hand[1][i] = estate;
		gamePtr->deck[1][i] = estate;
		gamePtr->discard[1][i] = estate;
		gamePtr->hand[1][i+1] = estate;
		gamePtr->deck[1][i+1] = estate;
		gamePtr->discard[1][i+1] = estate;
		gamePtr->hand[1][i+2] = duchy;
		gamePtr->deck[1][i+2] = duchy;
		gamePtr->discard[1][i+2] = duchy;
		gamePtr->hand[1][i+3] = province;
		gamePtr->deck[1][i+3] = province;
		gamePtr->discard[1][i+3] = province;
		gamePtr->hand[1][i+4] = great_hall;
		gamePtr->deck[1][i+4] = great_hall;
		gamePtr->discard[1][i+4] = great_hall;
		playerB = playerB + ((1+ 1 + 3 + 6 + 1) * 3);
	}
	printf("Player 2 score = %d\n", scoreFor(1, gamePtr));
	//Player 3
	gamePtr->handCount[2] = MAX_HAND;
	gamePtr->deckCount[2] = MAX_DECK;
	gamePtr->discardCount[2] = MAX_DECK;
	//Test scoreFor hand
	for(i = 0; i < MAX_HAND; i = i + 5){
		gamePtr->hand[2][i] = estate;
		gamePtr->deck[2][i] = estate;
		gamePtr->discard[2][i] = estate;
		gamePtr->hand[2][i+1] = estate;
		gamePtr->deck[2][i+1] = estate;
		gamePtr->discard[2][i+1] = estate;
		gamePtr->hand[2][i+2] = estate;
		gamePtr->deck[2][i+2] = estate;
		gamePtr->discard[2][i+2] = estate;
		gamePtr->hand[2][i+3] = estate;
		gamePtr->deck[2][i+3] = estate;
		gamePtr->discard[2][i+3] = estate;
		gamePtr->hand[2][i+4] = estate;
		gamePtr->deck[2][i+4] = estate;
		gamePtr->discard[2][i+4] = estate;
		playerC = playerC + ((1 + 1+ 1 + 1 + 1) * 3);
	}
	printf("Player 3 score = %d\n", scoreFor(2, gamePtr));

	//Player 4
	gamePtr->handCount[3] = MAX_HAND;
	gamePtr->deckCount[3] = MAX_DECK;
	gamePtr->discardCount[3] = MAX_DECK;
	gamePtr->whoseTurn = 3;
	//Test scoreFor hand
	for(i = 0; i < MAX_HAND; i = i + 5){
		gamePtr->hand[3][i] = curse;
		gamePtr->deck[3][i] = curse;
		gamePtr->discard[3][i] = curse;
		gamePtr->hand[3][i+1] = curse;
		gamePtr->deck[3][i+1] = curse;
		gamePtr->discard[3][i+1] = curse;
		gamePtr->hand[3][i+2] = curse;
		gamePtr->deck[3][i+2] = curse;
		gamePtr->discard[3][i+2] = curse;
		gamePtr->hand[3][i+3] = duchy;
		gamePtr->deck[3][i+3] = duchy;
		gamePtr->discard[3][i+3] = province;
		gamePtr->hand[3][i+4] = curse;
		gamePtr->deck[3][i+4] = curse;
		gamePtr->discard[3][i+4] = curse;
	//	playerD = 0;
	}
	printf("Player 4 score = %d\n", scoreFor(3, gamePtr));
	getWinners(players, gamePtr);
	for(i = 0; i < 4; i++){
		if(players[i] == 1){
			printf("Player %d won.\n", i+1); 
		}
	}
	
}
/*
int main(int argc, char * argv[]){
	printf("unittest3 getWinners().\n");
	testGetWinners();
	printf("unittest3 complete.\n");
	return 0;
}
*/
