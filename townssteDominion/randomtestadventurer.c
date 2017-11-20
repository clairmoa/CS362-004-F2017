#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int main() {
    int randomSeed = 66, passingTests = 0, cumulativePassingTests = 0, i, j, n, numPlayers, thisPlayer, handState, handCount;
	int k[10] = {mine, cutpurse, sea_hag, tribute, smithy, adventurer, gardens, embargo, village, minion};
	int deckCards[4] = {adventurer, silver, copper, gold,};
	char * passedTestCounter = (char *) malloc(sizeof(char) * 20); // Allocate Memory for the Passed Test Counter
	char * failedTestCounter = (char *) malloc(sizeof(char) * 16000);  // Allocate Memory for the failing Counter
	memset(passedTestCounter, '\0', sizeof(char) * 20); // Fill Block of Memory 
	memset(failedTestCounter, '\0', sizeof(char) * 16000); // Fill Block of Memory 
	time_t currentTime = time(NULL); // Get Current System Time
	srand(currentTime); // random number generator
	for(n = 0; n < 10000; n++){ // Performing 10,000 iterations
		passingTests = 0; // initializing passingTests each run
		printf("Card: adventurer - Current Iteration %d...\n", n); // Print Statement
		numPlayers = rand() % 4 + 1; //Random Number of Players between 1-4
		struct gameState state; // create a Gamestate
		initializeGame(numPlayers, k, randomSeed, &state); // Initialize Game
		for(i = 0; i < numPlayers; i++){ // For each Player 
			state.deckCount[i] = 10; // // Set Starting Deck Count to 10
			for(j = 0; j < 10; j++){
				state.deck[i][j] = deckCards[rand() % 4]; // Fill with copper, silver, and gold
			}
		}
		handCount = rand() % 5 + 1; // Random hand size
		for(i = 0; i < numPlayers; i++){
			state.handCount[i] = handCount; // Hand Size
		}
		handState = rand() % handCount + 1; // Get a Random Hand state
		thisPlayer = rand() % numPlayers; // Randomized current Player
		state.whoseTurn = thisPlayer; // Set this players Turn
		struct gameState newGameState; // Create a Temporary gameState
		memcpy(&newGameState, &state, sizeof(struct gameState)); // copy the current gameState to a new gameState
		int cardEffectTest = cardEffect(adventurer, 0, 0, 0, &state, handState, 0); // Test adventurer
		if(state.discardCount[thisPlayer] != ((10 + newGameState.handCount[thisPlayer]) - (state.deckCount[thisPlayer] + state.handCount[thisPlayer]))){
			passingTests = 1; // Condition Met
			printf("Testing Discard count P%d: %d, Expected: %d\n", thisPlayer + 1, state.discardCount[thisPlayer], ((12 + newGameState.handCount[thisPlayer]) - (state.deckCount[thisPlayer] + state.handCount[thisPlayer])));
		}
		if(cardEffectTest != 0){
			passingTests = 1; // Condition Met
			printf("Testing Card Effect Returned: %d, Expected Card Effect: %d\n", cardEffectTest, 0);
		}
		if(state.deckCount[thisPlayer] > (newGameState.deckCount[thisPlayer] - 2)){ //at least two cards were drawn
			passingTests = 1; // Condition Met
			printf("Testing Deck Count P1: %d, Expected Deck Count: <= %d\n", state.deckCount[0], (newGameState.deckCount[thisPlayer] - 2));
		}
		if(state.coins < 2){ //at least two coins/treasures were drawn from the deck
			passingTests = 1; // Condition Met
			printf("Testing Coins: %d, Expected Coins: >= 2\n", state.coins);
		}
		if(passingTests == 0){
			cumulativePassingTests++;
		}
		else{
			sprintf(passedTestCounter, "%d; ", n); // Print String Counter
			strcat(failedTestCounter, passedTestCounter);
		}
	}
	printf("Test failed: %s\n", failedTestCounter);		 // Print Message for Tests that Failed
	printf("Passing Tests: %d/10000\n", cumulativePassingTests); // Print Message for Tests that Passed
	printf("Running Time::: %ld\n", (long)currentTime);// Print Running Time
	return 0; // Quit Success
}