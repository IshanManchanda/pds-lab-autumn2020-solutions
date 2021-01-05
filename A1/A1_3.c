/* PDS Lab Autumn 2020, Assignment 1, Problem 3.
 * Ishan Manchanda, 8th Dec 2020
 * Input the (integral) coefficients of a degree-5 polynomial.
 * Then, print the polynomial and its derivative polynomial.
 */

#include <stdio.h>


int abs(int number) {
	// Helper function to find the absolute (mod) value of an integer.
	if (number >= 0)
		return number;
	return -number;
}

void print_polynomial(int* coefficients, int degree) {
	// When printing, we don't want the first term to be preceded by a + sign.
	// Neither do we want a space between the - sign and the coefficient.
	// We'll use flag_first_term to check if this is the first term.
	// We can do without this if we assume that the leading coefficient is non-0.
	int flag_first_term = 1;

	for (int i = degree; i >= 0; --i) {
		// Don't print anything if the coefficient is 0.
		if (coefficients[i] == 0)
			continue;

		if (flag_first_term) {
			flag_first_term = 0;

			// Print the first term
			if (i == 0)
				printf("%d", coefficients[i]);
			else if (i == 1)
				printf("%d*x", coefficients[i]);
			else
				printf("%d*x^%d", coefficients[i], i);
		}

		else {
			if (coefficients[i] > 0)
				// Positive term
				printf(" + ");
			else
				// Negative term
				printf(" - ");

			// Since we have already accounted for sign, print abs values.
			if (i == 0)
				printf("%d", abs(coefficients[i]));
			else if (i == 1)
				printf("%d*x", abs(coefficients[i]));
			else
				printf("%d*x^%d", abs(coefficients[i]), i);
		}
	}
	printf("\n");
}

int main() {
	int coefficients[6], derivative_coefficients[5];

	// Input the coefficients using a loop.
	for (int i = 0; i < 6; ++i) {
		if (i == 0)
			printf("Enter coefficient of 1: ");
		else if (i == 1)
			printf("Enter coefficient of x: ");
		else
			printf("Enter coefficient of x^%d: ", i);

		scanf("%d", &coefficients[i]);
	}

	// Compute the derivative using the algorithm for polynomials.
	for (int i = 1; i < 6; ++i)
		derivative_coefficients[i - 1] = coefficients[i] * i;

	// Since we have to print 2 polynomials with very similar formatting,
	// we use a function to simplify our code.
	printf("Polynomial: ");
	print_polynomial(coefficients, 5);
	printf("Derivative: ");
	print_polynomial(derivative_coefficients, 4);
}
