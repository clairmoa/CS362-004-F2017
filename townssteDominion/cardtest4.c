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
	printf("Performing tests on card: Adventurer:\n");
	printf("Test 4-1: 2 Player Game | Player 1 uses Adventurer\n");
	struct gameState currentState;
	initializeGame(2, k, seed, &currentState);
	currentState.deckCount[0] = 10;
	currentState.deckCount[1] = 10;
	currentState.handCount[0] = 0;
	int returnValue = cardEffect(adventurer, 0, 0, 0, &currentState, 0, 0);
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.coins < 2){
		passingCounter = 1;
		printf("Coins: %d, Expected Count: >= 2\n", currentState.coins);
	}
	if(currentState.deckCount[0] > 8){
		passingCounter = 1;
		printf("Deck Count Player 1: %d, Expected Count: <= 8\n", currentState.deckCount[0]);
	}
	if(currentState.discardCount[0] != (10 - (currentState.deckCount[0] + currentState.handCount[0]))){
		passingCounter = 1;
		printf("Discard count Player 1: %d, Expected Count: %d\n", currentState.discardCount[0], (currentState.deckCount[0] + currentState.handCount[0]));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 4-2: 2 Player Game | Player 2 Plays Adventurer\n");
	passingCounter = 0;
	initializeGame(2, k, seed, &currentState);	
	currentState.handCount[1] = 0;
	currentState.whoseTurn++;
	returnValue = cardEffect(adventurer, 0, 0, 0, &currentState, 0, 0);
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.coins < 2){
		passingCounter = 1;
		printf("Coins: %d, Expected Count: >= 2\n", currentState.coins);
	}
	if(currentState.deckCount[1] > 8){
		passingCounter = 1;
		printf("Deck Count Player 1: %d, Expected Count: <= 8\n", currentState.deckCount[1]);
	}
	if((currentState.discardCount[1] + 6) == (10 - (currentState.deckCount[1] + currentState.handCount[1]))){
		passingCounter = 1;
		printf("Discard count Player 1: %d, Expected Count: %d\n", (currentState.discardCount[1] + 6), (currentState.deckCount[1] + currentState.handCount[1] ));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 4-3: 4 Player Game | Player 4 Plays Adventurer\n");
	passingCounter = 0;
	initializeGame(4, k, seed, &currentState);
	currentState.handCount[3] = 0;
	currentState.whoseTurn = currentState.whoseTurn + 3;
	returnValue = cardEffect(adventurer, 0, 0, 0, &currentState, 0, 0);
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.coins < 2){
		passingCounter = 1;
		printf("Coins: %d, Expected Count: >= 2\n", currentState.coins);
	}
	if(currentState.deckCount[3] > 8){
		passingCounter = 1;
		printf("Deck Count P4: %d, Expected Count: <= 8\n", currentState.deckCount[3]);
	}
	if(currentState.discardCount[3] != (10 - (currentState.deckCount[3] + currentState.handCount[3]))){
		passingCounter = 1;
		printf("Discard count P4: %d, Expected Count: %d\n", currentState.discardCount[3], (currentState.deckCount[3] + currentState.handCount[3]));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Test 4-4: Continues 4-3 Game State | Player 4 Plays Adventurer Again\n");
	passingCounter = 0;
	returnValue = cardEffect(adventurer, 0, 0, 0, &currentState, 0, 0);
	currentState.whoseTurn--;
	if(returnValue != 0){
		passingCounter = 1;
		printf("Card Effect: %d, Expected Count: %d\n", returnValue, 0);
	}
	if(currentState.coins < 2){
		passingCounter = 1;
		printf("Coins: %d, Expected Count: >= 2\n", currentState.coins);
	}
	if(currentState.deckCount[3] > 8){
		passingCounter = 1;
		printf("Deck Count P4: %d, Expected Count: <= 8\n", currentState.deckCount[3]);
	}
	if((currentState.discardCount[3] + 7) == (10 - (currentState.deckCount[3] + currentState.handCount[3]))){
		passingCounter = 1;
		printf("Discard count P4: %d, Expected Count: %d\n", (currentState.discardCount[3] + 7), (currentState.deckCount[3] + currentState.handCount[3]));
	}
	if(passingCounter == 0){
		passedTests++;
	}
	printf("Passing Tests: %d/4\n", passedTests);
	return 0;
}