/* PDS Lab Autumn 2020, Assignment 5, Problem 1, Part (a).
 * Ishan Manchanda, 12th Jan 2021
 */

#include <stdio.h>

int DigitSum(int N) {
	int sum = 0;

	// Outer loop - we will iterate if sum is greater than 9.
	while (N > 0) {
		// Set sum to 0, calculate digit sum of current N.
		for (sum = 0; N > 0; sum += N % 10, N /= 10);

		// If sum is > 9, we set N to sum and iterate to compute it's sum.
		if (sum > 9) N = sum;
	}

	// Sum is less than 9, we can return this.
	return sum;
}

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
	ds_a = DigitSum(a);
	ds_b = DigitSum(b);
	ds_sum = DigitSum(a + b);
	ds_dsa_dsb = DigitSum(ds_a + ds_b);

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
