#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 13;
	int k[10] = {adventurer, village, mine, smithy, council_room, feast, gardens, remodel, baron, great_hall};
	struct gameState currentState;
	initializeGame(2, k, seed, &currentState);
	printf ("Unit Testing buyCard:\n");
	printf("Executing Unit Test 1-1\n");
	currentState.numBuys--;
	int returnValue = buyCard(1, &currentState);
	assert(returnValue == -1);
	initializeGame(2, k, seed, &currentState);
	printf("Executing Unit Test 1-2\n");
	currentState.coins = 0;
	returnValue = buyCard(1, &currentState);
	assert(returnValue == -1);
	initializeGame(2, k, seed, &currentState);
	printf("Executing Unit Test 1-3\n");
	currentState.supplyCount[1] = 0;
	returnValue = buyCard(1, &currentState);
	assert(returnValue == -1);
	initializeGame(2, k, seed, &currentState);
	printf("Executing Unit Test 1-4\n");
	currentState.coins = 10;
	struct gameState temp;
	memcpy(&temp, &currentState, sizeof(struct gameState));
	returnValue = buyCard(1, &currentState);
	assert(returnValue == 0);
	assert(currentState.numBuys == temp.numBuys - 1);
	assert(currentState.coins == (10 - getCost(1)));
	printf("Passing Tests: 4/4 \n");
    return 0;
}