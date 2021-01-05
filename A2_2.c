/* PDS Lab Autumn 2020, Assignment 2, Problem 2.
 * Ishan Manchanda, 15th Dec 2020
 * Input an integer between 1 and 100 and print its value in words.
 */

#include <stdio.h>


int main() {
	char *ones[9] = {
		"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
	};
	char *teens[10] = {
		"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
		"Seventeen", "Eighteen", "Nineteen"
	};
	char *tens[9] = {
		"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
		"Ninety", "Hundred"
	};

	// Take input from user
	int number;
	printf("Enter an integer between 1 and 100: ");
	scanf("%d", &number);

	// Validate the input - we don't want to give a wrong answer!
	if (number < 1 || number > 100) {
		printf("Number should be between 1 and 100.");
		return 0;
	}

	// If the number is within our hardcoded range, we simply print the value.
	if (10 <= number && number <= 19)
		printf("%s", teens[number - 10]);

	else {
		// Print the ten's digit
		if (number >= 20)
			printf("%s ", tens[(number / 10) - 2]);

		// Print the one's digit
		// Notice that if the number is between 1 and 9, we are only printing
		// a one's digit so our output is valid.
		if (number % 10 != 0)
			printf("%s", ones[(number % 10) - 1]);
	}
	printf("\n");
}
