/* PDS Lab Autumn 2020, Assignment 4, Problem 1.
 */

#include <stdio.h>


int main() {
	// Number of days in each month
	int n_days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Days of the week (for printing output)
	char *days_of_the_week[] = {
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
		"Saturday", "Sunday"
	};
	int month, day, accumulator = 0;

	// We'll loop until user enters a valid month
	while (1) {
		printf("Enter the month number (1 - 12): ");
		scanf("%d", &month);

		if (month <= 12 && month > 0) break;
		printf("Month needs to be between 1 and 12.\n");
	}

	// Switch from 1-based indexing (user input) to 0-based.
	--month;

	// We'll loop until user enters a valid day
	while (1) {
		printf("Enter the day number (1 - %d): ", n_days[month]);
		scanf("%d", &day);

		// Check if the day is valid for the given month
		if (day <= n_days[month] && day > 0) break;
		printf("Day needs to be between 1 and %d.\n", n_days[month]);
	}

	// Accumulate the days in the previous months
	for (int i = 0; i < month; ++i)
		accumulator += n_days[i];

	// Add the current day
	// And an offset of 2 (0-based indexing) since Jan 1 2020 was a Wednesday
	// Also, we need to subtract 1 since Jan 1 2020 is "day 0"
	// Effectively, we just need to add 1.
	accumulator += day + 1;

	printf("\n%d.%d.2020 was / is / will be a ", day, month + 1);
	printf("%s.", days_of_the_week[accumulator % 7]);
}
