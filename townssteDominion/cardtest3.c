#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 13;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int passedTests = 0;
	int passingCounter = 0;
	printf("Performing tests on card: Smithy:\n");
	printf("Test 3-1: 2 Player Game | Player 1 Plays Smithy\n");
	struct gameState currentState;
	initializeGame(2, k, seed, &currentState);
	currentState.deckCount[0] = 10;
	currentState.deckCount[1] = 10;
	currentState.handCount[0] = 1;
	currentState.handCount[1] = 1;
	int returnValue = cardEffect(smithy, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[0] != 9){
		passingCounter = 1;
		printf("Deck Count Player 1: %d, Expected Count: %d\n", currentState.deckCount[0], 7);
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[0] != -1){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], 3);
	}
	if(currentState.handCount[1] != 1){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 1);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 3-2: 2 Player Game | Player 2 Plays Smithy\n");
	passingCounter = 0;
	initializeGame(2, k, seed, &currentState);
	currentState.handCount[0] = 1;
	currentState.handCount[1] = 1;
	currentState.whoseTurn++;
	returnValue = cardEffect(smithy, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[1] != 9){
		passingCounter = 1;
		printf("Deck Count Player 2: %d, Expected Count: %d\n", currentState.deckCount[1], 7);
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[1] != -1){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 3);
	}
	if(currentState.handCount[0] != 1){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], 1);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 3-3: Continues 3-2 Game State | Player 1 uses Smithy\n");
	passingCounter = 0;
	currentState.handCount[0] = 2;
	currentState.handCount[1] = 2;
	returnValue = cardEffect(smithy, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[1] != 8){
		passingCounter = 1;
		printf("Deck Count Player 2: %d, Expected Count: %d\n", currentState.deckCount[1], 8);
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[1] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 0);
	}
	if(currentState.handCount[0] != 2){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], 2);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 3-4: Continues 3-2 Game State | Player 2 uses Smithy\n");
	passingCounter = 0;
	currentState.handCount[0] = 2;
	currentState.handCount[1] = 2;
	returnValue = cardEffect(smithy, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[1] != 7){
		passingCounter = 1;
		printf("Deck Count Player 2: %d, Expected Count: %d\n", currentState.deckCount[1], 7);
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[1] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 0);
	}
	if(currentState.handCount[0] != 2){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], 2);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 3-5: Continues 3-2 Game State | Player 1 uses Smithy\n");
	passingCounter = 0;
	currentState.handCount[0] = 2;
	currentState.handCount[1] = 2;
	returnValue = cardEffect(smithy, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[1] != 6){
		passingCounter = 1;
		printf("Deck Count Player 2: %d, Expected Count: %d\n", currentState.deckCount[1], 6);
	}
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.handCount[1] != 0){
		passingCounter = 1;
		printf("Hand Counter Player 2: %d, Expected Count: %d\n", currentState.handCount[1], 0);
	}
	if(currentState.handCount[0] != 2){
		passingCounter = 1;
		printf("Hand Counter Player 1: %d, Expected Count: %d\n", currentState.handCount[0], 2);
	}
	returnValue = cardEffect(smithy, 0, 0, 0, &currentState, 0, 0);
	if(currentState.deckCount[1] != 5){
		passingCounter = 1;
		printf("Deck Count Player 2: %d, Expected Count: %d\n", currentState.deckCount[1], 5);
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Passing Tests: %d/5\n", passedTests);
	return 0;
}