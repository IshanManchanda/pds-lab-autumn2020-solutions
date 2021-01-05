/* PDS Lab Autumn 2020, Test 1, Problem 2.
 * Ishan Manchanda, 5th Jan 2021
 */

#include <stdio.h>

int main() {
	// At each point, we will maintain a running maximum as well as
	// a count of how many times it has occurred.
	int input, current_max = 0, counter = 0;

	printf("Enter an infinite number of space-separated positive ");
	printf("integers.\nTo stop entering integers, enter -1.\n");
	printf("Input: ");

	// Loop until user enters -1
	while (1) {
		scanf("%d", &input);

		// User entered -1, print output and exit.
		if (input == -1) {
			// Case: -1 is the first input
			if (!counter) {
				printf("There is no max number!");
				return 0;
			}

			printf("Max number: %d\n", current_max);
			printf("Number of occurrences: %d\n", counter);
			return 0;
		}

		// If this is our current maximum, simply increment the counter.
		if (input == current_max)
			++counter;

		// If entered number is greater than current max, update current max
		// and reset counter to 1.
		else if (input > current_max) {
			current_max = input;
			counter = 1;
		}
	}
}
