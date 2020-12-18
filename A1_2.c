/* PDS Lab Autumn 2020, Assignment 1, Problem 2.
 * Input an angle x (in radians) from the user.
 * Using the series expansion formulas, compute sin(x), cos(x), sin(2*x)
 * and verify that sin(2*x) = 2 * sin(x) * cos(x)
 */

#include <stdio.h>
#define N_TERMS 4


int main() {
	double x, sinx, cosx, sin2x;
	// We will store each term to efficiently compute the next term.
	double sinx_term, cosx_term, sin2x_term;
	// double sinx_terms[4], cosx_terms[4], sin2x_terms[4];

	// Input the angle x
	printf("Enter angle x (in radians): ");
	scanf("%lf", &x);

	// Initialize accumulators and first terms.
	sinx = sinx_term = x;
	cosx = cosx_term = 1;
	sin2x = sin2x_term = 2 * x;

	// We will iteratively compute the terms of all 3 expansions.
	// This prevents us from having to compute the factorial and power terms
	// over and over again.
	for (int i = 1; i < N_TERMS; ++i) {
		// Compute current term in terms of the previous one.
		cosx_term = -cosx_term * x * x / (2 * i - 1) / (2 * i);
		sinx_term = -sinx_term * x * x / (2 * i + 1) / (2 * i);
		sin2x_term = -4 * sin2x_term * x * x / (2 * i + 1) / (2 * i);

		// Accumulate
		sinx += sinx_term;
		cosx += cosx_term;
		sin2x += sin2x_term;
	}

	// Print all the computed values, along with 2 * sin(x) * cos(x)
	printf("\nsin(x) = %lf\n", sinx);
	printf("cos(x) = %lf\n\n", cosx);
	printf("sin(2*x) = %lf\t(Computed using expansion)\n", sin2x);
	printf("sin(2*x) = 2 * sin(x) * cos(x) = %lf\n", 2 * sinx * cosx);
}
