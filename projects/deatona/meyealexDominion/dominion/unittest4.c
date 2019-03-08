/*Test Author: Adam Deaton
 *Test isGameOver function in dominion.c
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
 

void testIsGameOver(){
	struct gameState myGame;
	struct gameState * gamePtr = &myGame;
	int i, j, count, over;
	srand(time(NULL));
	for(j = 0; j < 10; j++){
		count = 0;
		over = 0;
		for(i = 0; i < 25; i++){
			gamePtr->supplyCount[i] = rand() % 7;
		}
		for(i = 0; i < 25; i++){
			if(gamePtr->supplyCount[i] == 0){
				count++;
			}
		} 
		over = isGameOver(gamePtr);
		printf("isGameOver test %d.\n", j+1);
		if(gamePtr->supplyCount[3] == 0 && over == 1){
			printf("isGameOver PASSED province is zero test\n");
		}
		else if(count >= 3 && over == 1){
			printf("isGameOver PASSED three cards are 0.\n");
		}
		else if(count >= 3 && over == 0){
			printf("isGameOver FAILED three cards are 0.\n");
		}
		else if(gamePtr->supplyCount[3] == 0 && over == 0){
			printf("isGameOver FAILED province is zero test\n");
		}
		else if(over == 0){
			printf("isGameOver PASSED game is not over condition.\n");
		}
		else{
			printf("Unexpected condition in isGameOver.\n");
		}
	}
}
/*
int main(int argc, char * argv[]){
	printf("unittest4 isGameOver().\n");
	testIsGameOver();
	printf("unittest 4 complete.\n");
	return 0;
}
*/
