#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int main() {
	int randomSeed = 66, passingTests = 0, cumulativePassingTests = 0, i, j, thisPlayer, handCount, numPlayers, handState; // Integer Variables
	int k[10] = {mine, cutpurse, sea_hag, tribute, smithy, adventurer, gardens, embargo, village, minion}; // 
	char * passedTestCounter = (char *) malloc(sizeof(char) * 20); // Allocate Memory for the Passed Test Counter
	char * failedTestCounter = (char *) malloc(sizeof(char) * 16000);  // Allocate Memory for the failing Counter
	memset(passedTestCounter, '\0', sizeof(char) * 20); // Fill Block of Memory 
	memset(failedTestCounter, '\0', sizeof(char) * 16000); // Fill Block of Memory 
	time_t currentTime = time(NULL); // Get Current System Time
	srand(currentTime); // random number generator
	for(j = 0; j < 10000; j++){ // Performing 10,000 iterations
		passingTests = 0;  // initializing passingTests each run
		printf("Card: countcilRoom - Current Iteration %d...\n", j); // Print an iteration counter 
		numPlayers = rand() % 4 + 1; //Random Number of Players between 1-4
		struct gameState state; // create a Gamestate
		initializeGame(numPlayers, k, randomSeed, &state); // Initialize Game
		for(i = 0; i < numPlayers; i++){
			state.deckCount[i] = 10; // Starting Deck
		}
		handCount = rand() % 5 + 1; // Hand Count (Random between 1-5)
		for(i = 0; i < numPlayers; i++){
			state.handCount[i] = handCount; // Hand Count
		}
		handState = rand() % handCount + 1; // Hand Position
		thisPlayer = rand() % numPlayers; //Randomized who player the card out of playercount
		state.whoseTurn = thisPlayer; // Set this players Turn
		struct gameState newGameState; // Create a Temporary Game
		memcpy(&newGameState, &state, sizeof(struct gameState)); // Copy the current Game into the Temporary Game
		int cardEffectTest = cardEffect(council_room, 0, 0, 0, &state, handState, 0);
		if(state.numBuys != (newGameState.numBuys + 1)){ //check plus one buy for current player
			passingTests = 1; // Condition Met
			printf("Num Buys: %d, Expected: %d\n", state.numBuys, (newGameState.numBuys + 1));
		}
		if(cardEffectTest != 0){
			passingTests = 1; // Condition Met
			printf("Card Effect Returned: %d, Expected: %d\n", cardEffectTest, 0);
		}
		for(i = 0; i < numPlayers; i++){
			if(i == thisPlayer){ //check card count for every player newGameState card count for each player plus 1 unless current player
				if(state.handCount[thisPlayer] != (newGameState.handCount[thisPlayer] + 3)){
					passingTests = 1; // Condition Met
					printf("Hand Size for P%d: %d, Expected: %d\n", thisPlayer + 1, state.handCount[thisPlayer], (newGameState.handCount[thisPlayer] + 3));
				}
			}
			else{
				if(state.handCount[i] != (newGameState.handCount[i] + 1)){
					passingTests = 1; // Condition Met
					printf("Hand Size for P%d: %d, Expected: %d\n", i + 1, state.handCount[i], (newGameState.handCount[i] + 1));
				}
			}
		}
		if(passingTests == 0){
			cumulativePassingTests++;
		}
		else{
			sprintf(passedTestCounter, "%d; ", j + 1); // Print String Counter
			strcat(failedTestCounter, passedTestCounter);
			memset(passedTestCounter, '\0', sizeof(char) * 20); // 0 Fill
		}
	}
	printf("Test failed: %s\n", failedTestCounter);		 // Print Message for Tests that Failed
	printf("Passing Tests: %d/10000\n", cumulativePassingTests); // Print Message for Tests that Passed
	printf("Running Time::: %ld\n", (long)currentTime);// Print Running Time
	return 0; // Quit Success
}