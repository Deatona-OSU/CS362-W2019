/*Test Author: Adam Deaton
 *Test scoreFor function in dominion.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <time.h>
#include "unittests.h"
 

void testScoreFor(){
	int i;
	int score = 0;
	int prescore = 0;
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	gamePtr->numPlayers = 2;
	gamePtr->handCount[1] = MAX_HAND;
	gamePtr->deckCount[1] = 0;
	gamePtr->discardCount[1] = 0;
	//Test scoreFor hand
	for(i = 0; i < MAX_HAND; i = i + 5){
		gamePtr->hand[1][i] = curse;
		gamePtr->hand[1][i+1] = estate;
		gamePtr->hand[1][i+2] = duchy;
		gamePtr->hand[1][i+3] = province;
		gamePtr->hand[1][i+4] = great_hall;
		prescore = prescore + 3 + 6 + 1;
	}
	score = scoreFor(1, gamePtr);
	if(score == prescore){
		printf("scoreFor function PASSED hand score test\n");
	}
	else{
		printf("scoreFor function FAILED hand score test\n");
	}
	//Test scoreFor deck clear out discard to nonexistant card
	prescore = 0;
	score = 0;
	gamePtr->handCount[1] = 0;
	gamePtr->deckCount[1] = 0;
	gamePtr->discardCount[1] = MAX_DECK;

	for(i = 0; i < MAX_DECK; i = i + 5){
		gamePtr->deck[1][i] = curse;
		gamePtr->discard[1][i] = 30;
		gamePtr->deck[1][i+1] = estate;
		gamePtr->discard[1][i+1] = 30;
		gamePtr->deck[1][i+2] = duchy;
		gamePtr->discard[1][i+2] = 30;
		gamePtr->deck[1][i+3] = province;
		gamePtr->discard[1][i+3] = 30;
		gamePtr->deck[1][i+4] = great_hall;
		gamePtr->discard[1][i+4] = 30;
		prescore = prescore + 3 + 6 + 1;
	}
	score = scoreFor(1, gamePtr);
	if(score == prescore){
		printf("scoreFor function PASSED deck score test\n");
	}
	else{
		printf("scoreFor function FAILED deck score test %d != %d\n", prescore, score);
	}
	
	//Test scoreFor discard
	prescore = 0;
	score = 0;	
	gamePtr->handCount[1] = 0;
	gamePtr->deckCount[1] = 0;
	gamePtr->discardCount[1] = MAX_DECK;

	for(i = 0; i < MAX_DECK; i = i + 5){
		gamePtr->discard[1][i] = curse;
		gamePtr->deck[1][i] = 30;
		gamePtr->discard[1][i+1] = estate;
		gamePtr->deck[1][i+1] = 30;
		gamePtr->discard[1][i+2] = duchy;
		gamePtr->deck[1][i+2] = 30;
		gamePtr->discard[1][i+3] = province;
		gamePtr->deck[1][i+3] = 30;
		gamePtr->discard[1][i+4] = great_hall;
		gamePtr->deck[1][i+4] = 30;
		prescore = prescore + 3 + 6 + 1;
	}
	score = scoreFor(1, gamePtr);
	if(score == prescore){
		printf("scoreFor function PASSED discard score test\n");
	}
	else{
		printf("scoreFor function FAILED discard score test %d != %d\n", prescore, score);
	}
}
/*
int main(int argc, char * argv[]){
	printf("unittest2 scoreFor().\n");
	testScoreFor();
	printf("unittest 2 complete.\n");
	return 0;
}
*/
