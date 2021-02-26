/* PDS Lab Autumn 2020, Assignment 7, Problem 4.
 * Ishan Manchanda, 23rd Feb 2021
 */

#include <stdio.h>

// Helper function that returns the index of the first element not greater than num
int lower_bound(int *a, int start, int end, int num) {
	// Base case
	if (start > end) return start;

	// Recursive case: Binary search
	int mid = (start + end) / 2;
	if (a[mid] == num) return mid;
	if (a[mid] > num) return lower_bound(a, start, mid - 1, num);
	else return lower_bound(a, mid + 1, end, num);
}

int insert(int *a, int n, int num) {
	// Get lower_bound
	int pos = lower_bound(a, 0, n - 1, num);

	// If element exists, return error code 1
	if (pos < n && a[pos] == num)
		return 1;

	// Else shift all elements after pos, and insert current element
	for (int i = n; i > pos; --i)
		a[i] = a[i - 1];
	a[pos] = num;
	return 0;
}

int delete(int *a, int n, int num) {
	// Get lower bound
	int pos = lower_bound(a, 0, n - 1, num);

	// If element doesn't exist, return error code 1
	if (pos >= n || a[pos] != num)
		return 1;

	// Else shift all elements after pos down by one
	for (int i = pos + 1; i < n; ++i)
		a[i - 1] = a[i];
	return 0;
}

void print_set(int *a, int n) {
	if (n == 0) {
		printf("Set: {}\n\n");
		return;
	}
	printf("{%d", a[0]);
	for (int i = 1; i < n; ++i) {
		printf(", %d", a[i]);
	}
	printf("}\n\n");
}

int main() {
	// Get number of students
	int n = 0, a[101], option = 0, error, temp;

	// Loop until user wants to exit
	while (1) {
		// Get option
		printf("Press 1 to insert numbers, 2 to delete numbers, 3 to display the set, and 0 to exit: ");
		scanf("%d", &option);

		// Quit
		if (option == 0)
			return 0;

			// Insert element
		else if (option == 1) {
			printf("Enter number to insert: ");
			scanf("%d", &temp);

			error = insert(a, n, temp);
			n += 1 - error;  // Increment n iff insertion was successful
			if (error)
				printf("Element already exists in set!\n\n");
			else
				printf("Element successfully inserted in set!\n\n");
		}

			// Delete element
		else if (option == 2) {
			printf("Enter number to delete: ");
			scanf("%d", &temp);

			error = delete(a, n, temp);
			n -= 1 - error;  // Decrement n iff deletion was successful
			if (error)
				printf("Element not found in set!\n\n");
			else
				printf("Element successfully deleted from set!\n\n");
		}

		else if (option == 3)
			print_set(a, n);

		else
			printf("Invalid option!\n\n");
	}
}
