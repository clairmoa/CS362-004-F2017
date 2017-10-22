#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <time.h>
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

int main() {
	struct gameState currentState;
	int i, j;
	int k[10] = {adventurer, village, mine, smithy, council_room, feast, gardens, remodel, baron, great_hall};
	int seed = 1000;
	initializeGame(2, k, seed, &currentState);
	srand(time(NULL));
    printf ("Unit Testing isGameOver:\n");
	int seedValues[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, -1, 2, 10};
	printf("Executing Unit Test 4-1\n");
	for(i = 0; i < 12; i++){
		currentState.supplyCount[province] = seedValues[i];
		int value = isGameOver(&currentState);
		if (currentState.supplyCount[province] == 0){
			assert(value == 1);
			printf("Test 1 Passed \n");
		}
	}
	initializeGame(2, k, seed, &currentState);
	printf("Executing Unit Test 4-2\n");
	for(i = 0; i < 100; i++){
		for(j = 0; j < 10; j++){
			currentState.supplyCount[j] = seedValues[rand() % 11];
		}
		int value = isGameOver(&currentState);
		int m = 0;
		for (j = 0; j < 10; j++){
			if (currentState.supplyCount[k[j]] == 0){
				m++;
			}
		}
		if (m >= 3){
			assert(value == 1);
			printf("Test 2 Passed\n");
		}
		m = 0;
	}
	initializeGame(2, k, seed, &currentState);
	printf("Executing Unit Test 4-3\n");
	for(i = 0; i < 11; i++){
		for(j = 0; j < 10; j++){
			currentState.supplyCount[j] = seedValues[i];
		}
		int value = isGameOver(&currentState);
		int m = 0;
		for (j = 0; j < 10; j++){
			if (currentState.supplyCount[j] == 0){
				m++;
			}
		}
		if (m >= 3){
			assert(value == 1);
			printf("Test 3 Passed\n");
		}
	}
    printf("Passing Tests: 3/3 \n");
    return 0;
}