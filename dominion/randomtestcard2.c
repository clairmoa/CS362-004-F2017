#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int main() {
	int randomSeed = 37, passingTests = 0, cumulativePassingTests = 0, i, j, handCount, numPlayers, thisPlayer, handState;
	int k[10] = {mine, cutpurse, sea_hag, tribute, smithy, adventurer, gardens, embargo, village, minion};
	char * passedTestCounter = (char *) malloc(sizeof(char) * 20); // Allocate Memory for the Passed Test Counter
	char * failedTestCounter = (char *) malloc(sizeof(char) * 16000); // Allocate Memory for the failing Counter
	memset(passedTestCounter, '\0', sizeof(char) * 20); // Fill Block of Memory 
	memset(failedTestCounter, '\0', sizeof(char) * 16000); // Fill Block of Memory 
	time_t currentTime = time(NULL); // Get Current System Time
	srand(currentTime); // random number generator
	for(j = 0; j < 10000; j++){ // Performing 10,000 iterations
		passingTests = 0; // initializing passingTests each run
		printf("Card: villageCard - Current Iteration %d...\n", j);
		numPlayers = rand() % 4 + 1; //Random Number of Players between 1-4
		struct gameState state; // create a Gamestate
		initializeGame(numPlayers, k, randomSeed, &state); // Initialize Game
		for(i = 0; i < numPlayers; i++){
			state.deckCount[i] = 10; // Starting Deck Count 10
		}
		handCount = rand() % 5 + 1; // Random Hand Size
		for(i = 0; i < numPlayers; i++){
			state.handCount[i] = handCount; // Hand Count
		}
		handState = rand() % handCount + 1;
		thisPlayer = rand() % numPlayers; // Random Player
		state.whoseTurn = thisPlayer; // Set new Turn
		struct gameState newGameState; // Create New Gamestate
		memcpy(&newGameState, &state, sizeof(struct gameState)); // Copy Gamestate to the new Gamestate
		int cardEffectTest = cardEffect(village, 0, 0, 0, &state, handState, 0); // Test the Village Card
		if(state.deckCount[thisPlayer] != (newGameState.deckCount[thisPlayer]) - 1){
			passingTests = 1; // Condition Met
			printf("Testing Deck Count P1: %d, Expected: %d\n", state.deckCount[thisPlayer], (newGameState.deckCount[thisPlayer]) - 1);
		}
		if(cardEffectTest != 0){
			passingTests = 1; // Condition Met
			printf("Testing Card Effect Returned: %d, Expected: %d\n", cardEffectTest, 0);
		}
		if(state.handCount[thisPlayer] != (newGameState.handCount[thisPlayer])){ // current hand couner is != hand count
			passingTests = 1; // Condition Met
			printf("Testing Hand Count P1: %d, Expected: %d\n", state.handCount[thisPlayer], (newGameState.handCount[thisPlayer]));
		}
		if(state.numActions != 3){ // Gaining 2 actions
			passingTests = 1; // Condition Met
			printf("Testing Num Actions: %d, Expected: %d\n", state.numActions, 3);
		}
		if(passingTests == 0){
			cumulativePassingTests++;
		}
		else{
			sprintf(passedTestCounter, "%d; ", j + 1);
			strcat(failedTestCounter, passedTestCounter);
			memset(passedTestCounter, '\0', sizeof(char) * 20);
		}
	}
	printf("Test failed: %s\n", failedTestCounter);		 // Print Message for Tests that Failed
	printf("Passing Tests: %d/10000\n", cumulativePassingTests); // Print Message for Tests that Passed
	printf("Running Time::: %ld\n", (long)currentTime);// Print Running Time
	return 0; // Quit Success
}