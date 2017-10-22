#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int seed = 13;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int passingCounter = 0;
	int passedTests = 0;
	printf("Performing tests on card: Village:\n");
	printf("Test 2-1: 2 Player Game | Player 1 uses Village\n");
	struct gameState currentState;
	initializeGame(2, k, seed, &currentState);
	struct gameState temp;
	memcpy(&temp, &currentState, sizeof(struct gameState));
	int returnValue = cardEffect(village, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[0] != (temp.deckCount[0] - 1)){
		passingCounter = 1;
		printf("Deck Count Player 1: %d, Expected Count: %d\n", currentState.deckCount[0], (temp.deckCount[0] - 1));
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[0] != (temp.handCount[0])){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], (temp.handCount[0]));
	}	
	if(currentState.numActions != 21){
		passingCounter = 1;
		printf("Action Counter: %d, Expected Count: %d\n", currentState.numActions, 3);
	}
	if(currentState.handCount[1] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 0);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 2-2: 2 Player Game | Player 2 uses Village\n");
	passingCounter = 0;
	initializeGame(2, k, seed, &currentState);
	memcpy(&temp, &currentState, sizeof(struct gameState));
	currentState.whoseTurn++;

	returnValue = cardEffect(village, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[1] != (temp.deckCount[1] - 1)){
		passingCounter = 1;
		printf("Deck Count Player 1: %d, Expected Count: %d\n", currentState.deckCount[1], (temp.deckCount[1] - 1));
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[1] != (temp.handCount[1])){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], (temp.handCount[1]));
	}
	if(currentState.numActions != 21){
		passingCounter = 1;
		printf("Action Counter: %d, Expected Count: %d\n", currentState.numActions, 3);
	}
	if(currentState.handCount[1] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 0);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 2-3: 4 Player Game | Player 3 uses Village\n");
	passingCounter = 0;
	initializeGame(4, k, seed, &currentState);
	memcpy(&temp, &currentState, sizeof(struct gameState));
	currentState.whoseTurn = 0;
	currentState.whoseTurn = currentState.whoseTurn + 2;
	returnValue = cardEffect(village, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[2] != (temp.deckCount[2] - 1)){
		passingCounter = 1;
		printf("Deck Count Player 1: %d, Expected Count: %d\n", currentState.deckCount[2], (temp.deckCount[2] - 1));
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[2] != (temp.handCount[2])){
		passingCounter = 1;
		printf("Hand Counter Player 3: %d, Expected Count: %d\n", currentState.handCount[2], (temp.handCount[2]));
	}
	if(currentState.numActions != 21){
		passingCounter = 1;
		printf("Action Counter: %d, Expected Count: %d\n", currentState.numActions, 3);
	}
	if(currentState.handCount[0] != 5){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], 5);
	}
	if(currentState.handCount[1] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[1], 0);
	}
	if(currentState.handCount[3] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[3], 0);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Passing Tests: %d/3\n", passedTests);
	return 0;
}