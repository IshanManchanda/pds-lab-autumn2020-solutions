/* PDS Lab Autumn 2020, Assignment 7, Problem 3.
 * Ishan Manchanda, 23rd Feb 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_info {
	int namelen;
	char *name;
} s_info;

int main() {
	// Get number of students
	int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);

	// Allocate memory for n students
	s_info *students = (s_info *) malloc(n * sizeof(s_info));

	// Get student data
	for (int i = 0; i < n; ++i) {
		// Input namelen
		printf("Enter namelen for student %d: ", i + 1);
		scanf("%d", &students[i].namelen);

		// Assign memory for name. We add 1 to account for \0.
		students[i].name = (char *) malloc((students[i].namelen + 1) * sizeof(char));

		printf("Enter name of student %d: ", i + 1);
		// Input name with spaces, %*c consumes \n from input buffer
		scanf("%*c%[^\n]%*c", students[i].name);
	}

	// Perform a selection sort to sort students by name
	int min_index;
	s_info temp;
	for (int i = 0; i < n - 1; ++i) {
		// Find the minimum element in (i -> n - 1)
		min_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (strcmp(students[j].name, students[min_index].name) < 0)
				min_index = j;
		}

		// Swap the minimum element with element at i.
		temp = students[i];
		students[i] = students[min_index];
		students[min_index] = temp;
	}

	printf("\n");
	for (int i = 0; i < n; ++i)
		printf("%s\n", students[i].name);
}
