#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"

int main() {
    int seed = 13;
	int k[10] = {adventurer, village, mine, smithy, council_room, feast, gardens, remodel, baron, great_hall};
	struct gameState currentState;
	initializeGame(2, k, seed, &currentState);
	int whoseTurn = currentState.whoseTurn;
	printf("Unit Testing endTurn:\n");
	printf("Executing Unit Test 2-1\n");
	endTurn(&currentState);
	assert(currentState.handCount[whoseTurn] == 0);
	assert(whoseTurn == whoseTurn);
	assert(currentState.numBuys == 1);
	assert(currentState.numActions == 1);
	assert(currentState.playedCardCount == 0);
	assert(currentState.outpostPlayed == 0);
	assert(currentState.phase == 0);
	assert(currentState.handCount[whoseTurn] == 0);
	printf("Executing Unit Test 2-2\n");
	endTurn(&currentState);
	assert(currentState.handCount[whoseTurn + 1] == 0);
	assert(whoseTurn == whoseTurn);
	assert(currentState.outpostPlayed == 0);
	assert(currentState.playedCardCount == 0);
	assert(currentState.phase == 0);
	assert(currentState.numActions == 1);
	assert(currentState.numBuys == 1);
	assert(currentState.handCount[whoseTurn + 1] == 0);
	printf("Executing Unit Test 2-3\n");
	currentState.coins = 10;
	buyCard(1, &currentState);
	endTurn(&currentState);
	assert(currentState.handCount[whoseTurn] == 0);
	assert(whoseTurn == whoseTurn);
	assert(currentState.outpostPlayed == 0);
	assert(currentState.numBuys == 1);
	assert(currentState.phase == 0);
	assert(currentState.numActions == 1);
	assert(currentState.playedCardCount == 0);
	assert(currentState.handCount[whoseTurn] == 0);
	printf("Passing Tests: 3/3 \n");
	return 0;
}