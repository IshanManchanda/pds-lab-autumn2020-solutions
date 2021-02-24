/* PDS Lab Autumn 2020, Assignment 7, Problem 2.
 * Ishan Manchanda, 23rd Feb 2021
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Get file names
	char s_name[100], d_name[100];
	printf("Enter the source file name: ");
	scanf("%s", s_name);
	printf("Enter the destination file name: ");
	scanf("%s", d_name);

	// Open source file, check for errors
	FILE *source, *dest;
	source = fopen(s_name, "r");
	if (source == NULL) {
		printf("Cannot open file!\n");
		exit(-1);
	}

	// Read in the dimensions
	int n, m;
	fscanf(source, "%d %d", &n, &m);

	// Allocate space for the matrix
	int **a = (int **) malloc(n * sizeof(int *));
	for (int i = 0; i < n; ++i)
		a[i] = (int *) malloc(m * sizeof(int));

	// Read in the matrix elements, close source file
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fscanf(source, "%d", &a[i][j]);
	fclose(source);

	// Open destination file, write out the transposed dimensions
	dest = fopen(d_name, "w");
	fprintf(dest, "%d %d\n", m, n);

	// Write out the transposed elements, close file
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			fprintf(dest, "%d ", a[i][j]);
		}
		fprintf(dest, "\n");
	}
	fclose(dest);

	printf("\nSuccessfully written transpose to %s!\n", d_name);
}
