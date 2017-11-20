#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	int seed = 13;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int passingCounter = 0;
	int passedTests = 0;
	printf("Performing tests on card: Council Room:\n");
	printf("Test 1-1: 2 Players | Player 1 uses Council Room\n");
	struct gameState currentState;
	initializeGame(2, k, seed, &currentState);
	struct gameState temp;
	memcpy(&temp, &currentState, sizeof(struct gameState));
	int returnValue = cardEffect(council_room, 0, 0, 0, &currentState, 0, 0);
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[0] != (temp.handCount[0] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], (temp.handCount[0] + 1));
	}
	if(currentState.numBuys != (temp.numBuys + 1)){
		passingCounter = 1;
		printf("Number of Buys: %d, Expected Count: %d\n", currentState.numBuys, (temp.numBuys + 1));
	}
	if(currentState.handCount[1] != (temp.handCount[1] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], (temp.handCount[1] + 1));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 1-2: 4 Players | Player 1 uses Council Room\n");
	passingCounter = 0;
	initializeGame(4, k, seed, &currentState);
	memcpy(&temp, &currentState, sizeof(struct gameState));
	returnValue = cardEffect(council_room, 0, 0, 0, &currentState, 0, 0);
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[0] != (temp.handCount[0] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], (temp.handCount[0] + 1));
	}
	if(currentState.numBuys != (temp.numBuys + 1)){
		passingCounter = 1;
		printf("Number of Buys: %d, Expected Count: %d\n", currentState.numBuys, (temp.numBuys + 1));
	}
	if(currentState.handCount[1] != (temp.handCount[1] )){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], (temp.handCount[1] ));
	}
	if(currentState.handCount[2] != (temp.handCount[2] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 3: %d, Expected Count: %d\n", currentState.handCount[2], (temp.handCount[2] + 1));
	}
	if(currentState.handCount[3] != (temp.handCount[3] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 4: %d, Expected Count: %d\n", currentState.handCount[3], (temp.handCount[3] + 1));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 1-3: Continues from Test 1-2. | Player 2 uses Council Room\n");
	passingCounter = 0;
	memcpy(&temp, &currentState, sizeof(struct gameState));
	currentState.whoseTurn = 1;
	returnValue = cardEffect(council_room, 0, 0, 0, &currentState, 0, 0);
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[1] != (temp.handCount[1] + 0)){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], (temp.handCount[1] + 0));
	}
	if(currentState.handCount[0] != (temp.handCount[0] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], (temp.handCount[0] + 1));
	}
	if((currentState.handCount[2] + 4) != (temp.handCount[2] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 3: %d, Expected Count: %d\n", (currentState.handCount[2] + 4), (temp.handCount[2] + 1));
	}
	if(currentState.handCount[3] != (temp.handCount[3] + 1)){
		passingCounter = 1;
		printf("Hand Counter Player 4: %d, Expected Count: %d\n", currentState.handCount[3], (temp.handCount[3] + 1));
	}
	if(currentState.numBuys != (temp.numBuys + 1)){
		passingCounter = 1;
		printf("Number of Buys: %d, Expected Count: %d\n", currentState.numBuys, (temp.numBuys + 1));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("passingCounter Tests: %d/3\n", passedTests);
	return 0;
}