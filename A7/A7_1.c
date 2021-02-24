/* PDS Lab Autumn 2020, Assignment 7, Problem 1.
 * Ishan Manchanda, 23rd Feb 2021
 */

#include <stdio.h>
#define MAX_N 10

void minmax(int **matrix, int n, int *max, int *min) {
	// Initialize min and max values
	*max = matrix[0][0];
	*min = matrix[0][n - 1];

	// Iterate over both diagonals together
	for (int i = 1; i < n; ++i) {
		// Check primary diagonal
		if (matrix[i][i] > *max)
			*max = matrix[i][i];

		// Check secondary diagonal
		if (matrix[i][n - i - 1] < *min)
			*min = matrix[i][n - i - 1];
	}
}

int main() {
	int n, max, min;
	int a[MAX_N][MAX_N];

	// Get dimensions from user
	printf("Enter the dimension of the square matrix (N): ");
	scanf("%d", &n);

	// Input elements of square matrix
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("Enter the value of element [%d][%d]: ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}

	// Call function with pointers for the outputs, print result
	func(a, n, &max, &min);
	printf("Max = %d. Min = %d\n", max, min);
}
