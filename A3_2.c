/* PDS Lab Autumn 2020, Assignment 3, Problem 2.
 * Input integer n and print all integers in [1, 1000] whose sum of digits
 * is greater than n.
 */

#include <stdio.h>


// Helper function to compute the sum of digits of an integer.
int sum_of_digits(int x) {
	// Initialize with unit's digit
	int sum = x % 10;

	// Throw away the last digit, and check if the new number is > 0
	// If yes, add the new last digit and continue the process
	while ((x /= 10) > 0)
		sum += x % 10;
	return sum;
}

int main() {
	int n;

	printf("Enter integer n: ");
	scanf("%d", &n);

	// We'll use first_term flag to control formatting
	int flag_first_term = 1;
	printf("Output: ");

	for (int i = 1; i <= 1000; ++i) {

		if (sum_of_digits(i) > n) {
			if (!flag_first_term)
				printf(", %d", i);

			else {
				flag_first_term = 0;
				printf("%d", i);
			}
		}
	}
	printf("\n");
}
