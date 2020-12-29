/* PDS Lab Autumn 2020, Assignment 3, Problem 1.
 * Input positive integer n and real number x, and compute e^x up to n terms.
 * If x is not a positive integer, print a suitable error message and continue
 * until a valid input is received.
 */

#include <stdio.h>


int main() {
	// We'll use an accumulator to hold the series sum
	double x, accumulator, last_term;
	int n;

	printf("Enter real number x (the exponent): ");
	scanf("%lf", &x);

	// We'll loop until user enters a valid n
	while (1) {
		printf("Enter positive integer n (number of terms): ");
		scanf("%d", &n);

		if (n > 0) break;
		printf("n needs to be a positive integer!\n");
	}

	// Initialize accumulator and first term.
	accumulator = last_term = 1;

	// We will iteratively compute the terms of the expansion
	// t(i) = x^i / i!
	// And so, t(i) = t(i - 1) * x / i
	for (int i = 1; i < n; ++i) {
		// Compute current term in terms of the previous one.
		last_term *= x / i;
		accumulator += last_term;
	}

	// Print the computed value
	printf("\ne^x = %lf [Computed to %d term(s)]\n", accumulator, n);
}
