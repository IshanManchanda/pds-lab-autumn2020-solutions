/* PDS Lab Autumn 2020, Test 1, Problem 1.
 * Ishan Manchanda, 5th Jan 2021
 */

#include <stdio.h>

void print_asterisks(int n) {
	// Helper function that prints 'n' space-separated asterisks
	for (int i = 1; i < n; ++i)
		printf("* ");
	printf("*");
}

void print_spaces(int n) {
	// Helper function that prints 'n' spaces
	for (int i = 0; i < n; ++i)
		printf(" ");
}

void print_row(int i, int n) {
	/* Helper function that prints the i'th row of the top-half.
	 * The i'th row contains i space-separated asterisks,
	 * followed by a fixed number of spaces (explained below),
	 * and finishes off with another i space-separated asterisks.
	 */

	// First, print i space-separated asterisks
	print_asterisks(i);

	/* Now, notice that on the central lines, we leave a single space
	 * While on the lines just above and below, we leave enough space
	 * to line up the last asterisk with the penultimate asterisk of the
	 * central row.
	 * Clearly, we leave space for 2 asterisks and the 2 spaces between them.
	 * We can extrapolate this as:
	 * We leave 4x + 1 rows, where x is the row distance from the center.
	 * As we iterate from 1 to n, the row distance is simply n - i.
	 */
	int row_distance = n - i;
	print_spaces(4 * row_distance + 1);

	// Finally, print another i space-separated asterisks and a newline
	print_asterisks(i);
	printf("\n");
}


int main() {
	int n;
	printf("Enter positive integer n: ");
	scanf("%d", &n);

	// Check for validity of input
	if (n < 1) {
		printf("n needs to be a positive integer!\n");
		return 0;
	}

	// Print n rows - top half of butterfly (i: 1 -> n)
	for (int i = 1; i <= n; ++i)
		print_row(i, n);

	// Print n rows - bottom half of butterfly (i: n -> 1)
	for (int i = n; i > 0; --i) {
		print_row(i, n);
	}
}
