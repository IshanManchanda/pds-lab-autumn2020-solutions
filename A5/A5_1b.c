/* PDS Lab Autumn 2020, Assignment 5, Problem 1, Part (b).
 * Ishan Manchanda, 12th Jan 2021
 */

#include <stdio.h>

int DigitSumRecursive(int N) {
	// Base Case: N is single digit, simply return.
	if (N < 10) return N;

	// In other cases, perform the procedure to find digit sum.
	int sum = 0;
	for (; N > 0; sum += N % 10, N /= 10);

	// Recursive Case: We return the digit sum of the computed sum.
	return DigitSumRecursive(sum);
}

// Same Driver code as in Part (a).
int main() {
	int a, b, ds_a, ds_b, ds_sum, ds_dsa_dsb;

	printf("Enter non-negative integer a: ");
	scanf("%d", &a);

	printf("Enter non-negative integer b: ");
	scanf("%d", &b);

	// Validate inputs - we will terminate rather than give a wrong answer.
	if (a < 0 || b < 0) {
		printf("Inputs should be non-negative!");
		return 0;
	}

	// Compute required DigitSums.
	ds_a = DigitSumRecursive(a);
	ds_b = DigitSumRecursive(b);
	ds_sum = DigitSumRecursive(a + b);
	ds_dsa_dsb = DigitSumRecursive(ds_a + ds_b);

	printf("DigitSum of a: %d\n", ds_a);
	printf("DigitSum of b: %d\n", ds_b);
	printf("DigitSum of a + b: %d\n", ds_sum);
	printf("DigitSum of (DigitSum(a) + DigitSum(b)): %d\n", ds_dsa_dsb);

	if (ds_sum == ds_dsa_dsb) {
		printf("As the computed DigitSums are equal, ");
		printf("the property is verified.\n");
	}
	else {
		printf("As the computed DigitSums are unequal, ");
		printf("the property is disproven by counterexample.\n");
	}
}
