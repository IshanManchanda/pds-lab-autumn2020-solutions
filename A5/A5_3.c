/* PDS Lab Autumn 2020, Assignment 5, Problem 3.
 * Ishan Manchanda, 12th Jan 2021
 */

#include <stdio.h>
#define MAXLENGTH 10

// Helper function to swap characters at given positions of a string.
void swap(char str[], int x, int y) {
	if (x == y) return;

	char temp = str[x];
	str[x] = str[y];
	str[y] = temp;
}

// Helper function that copies characters of a string between given positions.
void shallow_copy(char from[], char to[], int start, int end) {
	for (int i = start; i <= end; ++i)
		to[i] = from[i];
}

/* Recursive function to print all permutations of a given string.
 * Approach: We fix a prefix and then recursively generate permutations
 * for the remainder (length reduced by 1) of the string.
 * Each character is iteratively taken to be part of the prefix.
 */
void print_permutations(char str[], int prefix_length, int length) {

	// Base case: We have fixed the entire string; Print this permutation.
	// This happens if we have fixed either (a) all characters
	// Or (b) all characters except the last one.
	if (length - prefix_length <= 1) {
		printf("%s\n", str);
		return;
	}

	// Create a duplicate of the string so that we can undo changes made
	// in recursive calls for further iterations.
	char copy[MAXLENGTH + 1];
	shallow_copy(str, copy, 0, length);

	// Iterate over all characters not part of the current prefix.
	for (int i = prefix_length; i < length; ++i) {
		// Swap them to the end of the prefix,
		// and increment the prefix_length for recursive calls.
		swap(copy, prefix_length, i);
		print_permutations(copy, prefix_length + 1, length);

		// We only make changes after prefix_length, so resetting from
		// this position is sufficient.
		shallow_copy(str, copy, prefix_length, length);
	}
}

int main() {
	// Extra space for '\0'
	char str[MAXLENGTH + 1];

	// Input the string, force termination at MAXLENGTH position.
	// That is, we will take the first MAXLENGTH characters only.
	printf("Enter string (distinct chars, max length %d): ", MAXLENGTH);
	scanf("%s", str);
	str[MAXLENGTH] = '\0';

	// Find out true length of the string.
	int length = 0;
	for (; str[length] != '\0'; ++length);

	// We start with a prefix_length of 0 as we have fixed nothing yet.
	printf("Permutations of %s:\n", str);
	print_permutations(str, 0, length);
}
