/* PDS Lab Autumn 2020, Assignment 6, Problem 2.
 * Ishan Manchanda, 19'th Jan 2021
 */

#include <stdio.h>
#include <math.h>
#define PI 3.14159

struct Comp {
	double real, imag;
};

void comp_print(struct Comp a) {
	char sign = (a.imag < 0) ? '-' : '+';
	printf("%.2lf %c i%.2lf\n", a.real, sign, a.imag);
}

struct Comp comp_sum(struct Comp a, struct Comp b) {
	struct Comp sum;

	// Standard complex number sum formula
	sum.real = a.real + b.real;
	sum.imag = a.imag + b.imag;
	return sum;
}

struct Comp comp_product(struct Comp a, struct Comp b) {
	struct Comp product;

	// Standard complex number product formula
	product.real = a.real * b.real - a.imag * b.imag;
	product.imag = a.real * b.imag + a.imag * b.real;
	return product;
}

void comp_print_polar(struct Comp a) {
	// Convert complex number to polar coordinates
	// r is found simply using the Pythagoras Theorem.
	double r = sqrt(a.real * a.real + a.imag * a.imag);

	/* To find the argument, we use the atan2 function of math.h
	 * which takes into account the signs of the numerator and denominator
	 * to give an arctan value as per the sign convention in the Argand plane.
	 * Then, we multiply by 180 / PI to convert from radians to degrees.
	 */
	double theta = atan2(a.imag, a.real) * 180 / PI;
	printf("r = %.2lf, arg = %.2lf degrees\n", r, theta);
}

int main() {
	struct Comp a, b, sum, product;

	printf("Enter the real and imaginary parts as space-separated real numbers.\n");
	printf("Enter parts of complex number a: ");
	scanf("%lf %lf", &a.real, &a.imag);

	printf("Enter parts of complex number b: ");
	scanf("%lf %lf", &b.real, &b.imag);

	printf("\na = ");
	comp_print(a);
	printf("Polar form of a: ");
	comp_print_polar(a);

	printf("\nb = ");
	comp_print(b);
	printf("Polar form of b: ");
	comp_print_polar(b);

	sum = comp_sum(a, b);
	printf("\na + b = ");
	comp_print(sum);
	printf("Polar form of a + b: ");
	comp_print_polar(sum);

	product = comp_product(a, b);
	printf("\na * b = ");
	comp_print(product);
	printf("Polar form of a * b: ");
	comp_print_polar(product);
}
