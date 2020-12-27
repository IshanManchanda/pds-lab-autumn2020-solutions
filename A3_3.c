/* PDS Lab Autumn 2020, Assignment 3, Problem 3.
 * Input integer n between 1 and 9 and print the following pattern (n = 6):
 * 6
 * 55
 * 444
 * 3333
 * 22222
 * 111111
 */

#include <stdio.h>


int main() {
	int n;

	printf("Enter integer n (between 1 and 9): ");
	scanf("%d", &n);

	// Check for validity of input
	if (n < 1 || n > 9) {
		printf("n should be between 1 and 9.");
		return 0;
	}

	// Each iteration will print a single line of the output
	for (int i = 0; i < n; ++i) {

		// Print (n - i); (i + 1) times
		for (int j = 0; j < i + 1; ++j)
			printf("%d", n - i);

		printf("\n");
	}
}
