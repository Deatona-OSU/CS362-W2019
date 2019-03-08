/*test author: Adam Deaton
 *Tests that cost of card is returned correctly. Also, test that nonexistant card returns -1.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h> 
#include "unittests.h"

void testGetCard(){
	if(getCost(0) == 0){
		printf("Curse is correct cost.\n");
	
	}
	else{
		printf("Curse is incorrect cost.\n");
	}
	if(getCost(3) == 8){
		printf("Province is correct cost.\n");
	
	}
	else{
		printf("Province is incorrect cost.\n");
	}
	
	if(getCost(11) == 5){
		printf("Mine is correct cost.\n");
	
	}	
	else{
		printf("Mine is incorrect cost.\n");
	}

	if(getCost(20) == 3){
		printf("Ambassador is correct cost.\n");
		
	}
	else{
		printf("Ambassador is incorrect cost.\n");
	}
	
	if(getCost(26) == 4){
		printf("Treasure Map is correct cost.\n");
	}	
	else{
		printf("Treasure is incorrect cost.\n");
	}
	printf("Nonexistant Card Cost Returns %d\n", getCost(30));
	
}

int main(int argc, char * argv[]){
	printf("unittest1 getCost\n");
	testGetCard();
	printf("unnittest1 of getCost complete\n");
	printf("unittest2 scoreFor().\n");
	testScoreFor();
	printf("unittest 2 complete.\n");
	printf("unittest3 getWinners().\n");
	testGetWinners();
	printf("unittest3 complete.\n");
	printf("unittest4 isGameOver().\n");
	testIsGameOver();
	printf("unittest 4 complete.\n");
//Card tests
	printf("cardtest1 Smithy\n");
	testSmithy();
	printf("cardtest1 complete\n");
	printf("cardtest2 Adventurer\n");
	testAdventurer();
	printf("cardtest2 complete\n");
	printf("cardtest3 Village\n");
	testVillage();
	printf("cardtest3 complete.\n");
	printf("cardtest4 Great Hall.\n");
	testGreatHall();
	printf("cardtest4 complete.\n");


	return 0;
}
