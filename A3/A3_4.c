/* PDS Lab Autumn 2020, Assignment 3, Problem 4.
 * Ishan Manchanda, 22nd Dec 2020
 * Input integer n between 1 and 9 and print the following pattern (n = 5):
 * 1        1
 * 22      22
 * 333    333
 * 4444  4444
 * 5555555555
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
	for (int i = 1; i <= n; ++i) {

		// Print i; i times
		for (int j = 0; j < i; ++j)
			printf("%d", i);

		// Print 2(n - i) spaces
		for (int j = 0; j < 2 * (n - i); ++j)
			printf(" ");

		// Print i; i times
		for (int j = 0; j < i; ++j)
			printf("%d", i);

		printf("\n");
	}
}
