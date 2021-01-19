/* PDS Lab Autumn 2020, Assignment 6, Problem 3.
 * Ishan Manchanda, 19'th Jan 2021
 */

#include <stdio.h>
#include <string.h>

// NUM_STUDENT and NUM_FACULTY can be changed as needed.
#define NUM_STUDENT 10
#define NUM_FACULTY 10
#define LENGTH_CODE 15
#define LENGTH_NAME 30

struct Student {
	char roll_num[LENGTH_CODE], name[LENGTH_NAME], facad_code[LENGTH_CODE];
};

struct Faculty {
	char emp_code[LENGTH_CODE], name[LENGTH_NAME];
};

// Arrays to store student and faculty data.
struct Student students[NUM_STUDENT];
struct Faculty faculties[NUM_FACULTY];

void print_facad(char roll_num[]) {
	// Iterate over all students, check if roll number matches.
	for (int i = 0; i < NUM_STUDENT; ++i) {
		if (!strcmp(roll_num, students[i].roll_num)) {
			// Roll number matched, we found the student.

			// Now, iterate over faculty and compare EMP code with FacAd code.
			for (int j = 0; j < NUM_FACULTY; ++j) {
				if (!strcmp(students[i].facad_code, faculties[j].emp_code)) {

					// Found the student's FacAd, print name and return.
					printf(
						"Faculty Advisor of %s (%s): %s\n",
						students[i].name, roll_num, faculties[j].name
					);
					return;
				}
			}

			// No faculty had an EMP code that matched the student's FacAd code.
			printf(
				"Faculty Advisor with EMP Code %s not found!\n",
				students[i].facad_code
			);
			return;
		}
	}

	// No student's roll number matched the given roll number.
	printf("Student with Roll Number %s not found!\n", roll_num);
}

void print_students(char name[]) {
	// We check if we have printed at least 1 student for formatting.
	int FLAG_PRINTED = 0;

	// Iterate over all faculty members, check if name matches given name.
	for (int i = 0; i < NUM_FACULTY; ++i) {
		if (!strcmp(name, faculties[i].name)) {

			// Found the faculty. Now, iterate over students and compare FacAd code.
			for (int j = 0; j < NUM_STUDENT; ++j) {
				if (!strcmp(faculties[i].emp_code, students[j].facad_code)) {
					// Found a student with given faculty as their FacAd.

					// If this is the first student, print a header line.
					if (!FLAG_PRINTED)
						printf("Students with Faculty Advisor %s:\n", name);
					FLAG_PRINTED = 1;

					// Print student details.
					printf("%s (%s)\n", students[j].name, students[j].roll_num);
				}
			}

			// We haven't found a student with matching FacAd code.
			if (!FLAG_PRINTED) {
				printf("No students with Faculty Advisor %s found!\n", name);
			}
			return;
		}
	}
	printf("Faculty with name %s not found!", name);
}

int main() {
	printf("Please enter all values without spaces.\n");

	for (int i = 0; i < NUM_STUDENT; ++i) {
		printf("Enter Name of Student %d: ", i + 1);
		scanf("%s", students[i].name);

		printf("Enter Roll Number of Student %d: ", i + 1);
		scanf("%s", students[i].roll_num);
		printf("Enter Faculty Advisor Code of Student %d: ", i + 1);
		scanf("%s", students[i].facad_code);

		printf("\n");
	}

	for (int i = 0; i < NUM_FACULTY; ++i) {
		printf("Enter Name of Faculty %d: ", i + 1);
		scanf("%s", faculties[i].name);

		printf("Enter EMP Code of Faculty %d: ", i + 1);
		scanf("%s", faculties[i].emp_code);
		printf("\n");
	}

	char roll_no[LENGTH_CODE], name[LENGTH_NAME];
	printf("Enter Student Roll Number to lookup Faculty Advisor: ");
	scanf("%s", roll_no);
	print_facad(roll_no);

	printf("\nEnter Faculty name to get student details: ");
	scanf("%s", name);
	print_students(name);
}
