/* PDS Lab Autumn 2020, Assignment 4, Problem 2.
 */

#include <stdio.h>
#define LENGTH 20
#define SENTINEL 999 // Recommended Sentinel as per question

void receive_input(int arr[LENGTH + 1]) {
	// Variable i will track the number of unique inputs so far
	// We increment it each iteration and decrement it if a value already exists
	int i = 0;
	for (; i < LENGTH; ++i) {
		scanf("%d", &arr[i]);

		// User has entered the sentinel, no more inputs
		if (arr[i] == SENTINEL)
			break;

		// Iterate over entries so far and compare them with current
		for (int j = 0; j < i; ++j) {
			if (arr[j] == arr[i]) {
				--i;
				break;
			}
		}
	}
	// Add a sentinel at the end of the array
	arr[i] = SENTINEL;
}

void print_set(int arr[LENGTH + 1]) {
	// Print nothing if the set is empty.
	if (arr[0] == SENTINEL)
		return;

	// Print the first element (special cased for formatting)
	printf("%d", arr[0]);

	for (int i = 1; i < LENGTH && arr[i] != SENTINEL; ++i)
		printf(", %d", arr[i]);
}

void print_difference(int a1[LENGTH + 1], int a2[LENGTH + 1], int FLAG_FIRST) {
	// We use FLAG_PRINT to check whether a particular element in A
	// needs to be printed (depending on if it's present in B).
	// Further, we use FLAG_FIRST to specially format the first number.
	int FLAG_PRINT;

	for (int i = 0; i < LENGTH && a1[i] != SENTINEL; ++i) {
		FLAG_PRINT = 1;

		// Check if element present in a2
		for (int j = 0; j < LENGTH && a2[j] != SENTINEL; ++j)
			if (a1[i] == a2[j]) {
				FLAG_PRINT = 0;
				break;
			}

		// Conditionally print current element
		if (FLAG_PRINT) {
			if (FLAG_FIRST) {
				FLAG_FIRST = 0;
				printf("%d", a1[i]);
			}
			else
				printf(", %d", a1[i]);
		}
	}
}

void print_intersection(int a1[LENGTH + 1], int a2[LENGTH + 1]) {
	// Essentially the same logic as in print_difference,
	// We just change how FLAG_PRINT is initialized and updated.
	int FLAG_PRINT, FLAG_FIRST = 1;

	for (int i = 0; i < LENGTH && a1[i] != SENTINEL; ++i) {
		FLAG_PRINT = 0;

		// Check if element present in a2
		for (int j = 0; j < LENGTH && a2[j] != SENTINEL; ++j)
			if (a1[i] == a2[j]) {
				FLAG_PRINT = 1;
				break;
			}

		// Conditionally print current element
		if (FLAG_PRINT) {
			if (FLAG_FIRST) {
				FLAG_FIRST = 0;
				printf("%d", a1[i]);
			}
			else
				printf(", %d", a1[i]);
		}
	}
}

void print_union(int a[LENGTH + 1], int b[LENGTH + 1]) {
	// If set A is empty, the union is simply set B.
	if (a[0] == SENTINEL) {
		print_set(b);
		return;
	}

	// The union is a superset of A, so print all elements in A.
	print_set(a);

	// Now, we only need to print the elements in B which are not in A.
	// That is, their difference.
	// As we know A is not empty (and thus we have printed at least 1 element),
	// We pass 0 for FLAG_FIRST.
	print_difference(b, a, 0);
}

int main() {
	// We add 1 to accommodate a sentinel value.
	int a[LENGTH + 1], b[LENGTH + 1];

	printf("Please enter the elements as 20 space-separated values\n");
	printf("To enter fewer than 20 (unique) values, enter %d at the end\n\n", SENTINEL);

	// Input the sets from the user.
	printf("Enter elements of A: ");
	receive_input(a);
	printf("Enter elements of B: ");
	receive_input(b);

	printf("Set A = {");
	print_set(a);
	printf("}\n");

	printf("Set B = {");
	print_set(b);
	printf("}\n");

	printf("Union of A and B = {");
	print_union(a, b);
	printf("}\n");

	printf("Intersection of A and B = {");
	print_intersection(a, b);
	printf("}\n");

	printf("Set Difference A - B = {");
	// As we haven't printed any elements, FLAG_FIRST = 1
	print_difference(a, b, 1);
	printf("}\n");
}
