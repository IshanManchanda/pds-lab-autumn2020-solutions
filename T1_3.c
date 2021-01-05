/* PDS Lab Autumn 2020, Test 1, Problem 3.
 * Ishan Manchanda, 5th Jan 2021
 */

#include <stdio.h>
#define MAX_LENGTH 100  // Max length as per question

void selection_sort(int a[], int len) {
	// Helper function that performs a selection sort on the given int array

	int min_index, temp;
	for (int i = 0; i < len - 1; ++i) {

		// Find the minimum element in (i -> n - 1)
		min_index = i;
		for (int j = i + 1; j < len; ++j) {
			if (a[j] < a[min_index])
				min_index = j;
		}

		// Swap the minimum element with element at i.
		temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;
	}
}

int main() {
	int set[MAX_LENGTH];
	int i, len = 0, answer = 0;

	printf("Please enter the elements as 100 space-separated values\n");
	// We are guaranteed positive integers as inputs, so -1 can be terminator.
	printf("To enter fewer than 100 values, enter -1 at the end\n");

	// Receive input from user
	printf("Elements: ");
	for (i = 0; i < MAX_LENGTH; ++i) {
		scanf("%d", &set[i]);

		// User entered -1, no more inputs
		if (set[i] == -1)
			break;
		++len;
	}

	/* To efficiently compute the required answer, we sort the set.
	 * In a real-world scenario, we would use the qsort function (C stdlib)
	 * Here, however, we can quickly write a simple selection sort.
	 * Especially as the number of elements is very small (100).
	 */
	selection_sort(set, len);

	// As we have sorted the array and are guaranteed distinct inputs,
	// 3 consecutive integers would need to be consecutive in the sorted set.
	for (i = 0; i < len - 2; ++i)
		if ((set[i + 1] == set[i] + 1) && (set[i + 2] == set[i] + 2))
			++answer;

	printf("\nNumber of subsets containing exactly ");
	printf("3 consecutive integers: %d\n", answer);
}
