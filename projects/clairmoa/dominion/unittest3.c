#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 13;
    int numPlayer = 2;
	int k[10] = {adventurer, village, mine, smithy, council_room, feast, gardens, remodel, baron, great_hall};
	int supplyCount = 10;
	int victoryCount = 8;
    struct gameState currentState;
    printf ("Unit Testing initializeGame:\n");
	printf("Executing Unit Test 3-1\n");
	int status = initializeGame(2, k, seed, &currentState);
	assert(status == 0);
	assert(currentState.numPlayers == numPlayer);
	assert(currentState.supplyCount[curse] = 10);
	for(i = 0; i < 10; i++){
		if(i == 9 || i == 6){
			assert(currentState.supplyCount[k[i]] == victoryCount);
		}
		else{
			assert(currentState.supplyCount[k[i]] == supplyCount);
		}
	}
	assert(currentState.deckCount[0] == (10 - 5));
	assert(currentState.deckCount[1] == 10);
	assert(currentState.discardCount[i] == 0);
	for (i = 0; i <= treasure_map; i++){
		assert(currentState.embargoTokens[i] == 0);
    }
	assert(currentState.outpostPlayed == 0);
	assert(currentState.phase == 0);
	assert(currentState.numActions == 1);
	assert(currentState.numBuys == 1);
	assert(currentState.playedCardCount == 0);
	assert(currentState.whoseTurn == 0);
	assert(currentState.handCount[currentState.whoseTurn] == 5);
	victoryCount = 12;
	numPlayer = 4;
	printf("Executing Unit Test 3-2\n");
	status = initializeGame(4, k, seed, &currentState);
	assert(status == 0);
	assert(currentState.numPlayers == numPlayer);
	assert(currentState.supplyCount[curse] = 10);
	for(i = 0; i < 10; i++){
		if(i == 9 || i == 6){
			assert(currentState.supplyCount[k[i]] == victoryCount);
		}
		else{
			assert(currentState.supplyCount[k[i]] == supplyCount);
		}
	}
	assert(currentState.deckCount[0] == (10 - 5));
	assert(currentState.deckCount[1] == 10);
	assert(currentState.discardCount[i] == 0);
	for (i = 0; i <= treasure_map; i++){
		assert(currentState.embargoTokens[i] == 0);
    }
	assert(currentState.outpostPlayed == 0);
	assert(currentState.phase == 0);
	assert(currentState.handCount[currentState.whoseTurn] == 5);
	assert(currentState.numActions == 1);
	assert(currentState.numBuys == 1);
	assert(currentState.playedCardCount == 0);
	assert(currentState.whoseTurn == 0);
	numPlayer = 5;
	printf("Executing Unit Test 3-3\n");
	status = initializeGame(5, k, seed, &currentState);
	assert(status != 0);
	assert(currentState.numPlayers != numPlayer);
	assert(currentState.supplyCount[curse] = 10);
	assert(currentState.deckCount[0] == (10 - 5));
	assert(currentState.deckCount[1] == 10);
	assert(currentState.discardCount[i] == 0);
	assert(currentState.numActions == 1);
	assert(currentState.numBuys == 1);
	assert(currentState.playedCardCount == 0);
	assert(currentState.whoseTurn == 0);
	for (i = 0; i <= treasure_map; i++){
		assert(currentState.embargoTokens[i] == 0);
    }
	assert(currentState.outpostPlayed == 0);
	assert(currentState.phase == 0);
	assert(currentState.handCount[currentState.whoseTurn] == 5);
    printf("Passing Tests: 3/3 \n");
    return 0;
}