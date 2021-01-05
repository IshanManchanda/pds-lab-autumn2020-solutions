/* PDS Lab Autumn 2020, Assignment 1, Problem 1.
 * Ishan Manchanda, 8th Dec 2020
 * Input the lengths of sides AB, BC, and CA of a triangle ABC from the user.
 * Compute and print (i) The perimeter of the triangle, and
 * (ii) The square of the area of the triangle.
 */

#include <stdio.h>


int main() {
	// Convention: Use lowercase names for variables.
	double ab, bc, ca;

	// Input the side lengths of the triangle using scanf.
	printf("Enter length AB: ");
	scanf("%lf", &ab);
	printf("Enter length BC: ");
	scanf("%lf", &bc);
	printf("Enter length CA: ");
	scanf("%lf", &ca);

	// Check whether the lengths form a valid triangle.
	if ((ab + bc <= ca) || (bc + ca <= ab) || (ca + ab <= bc)) {
		printf("\nThe side lengths do not form a valid triangle!\n");
		return 0;
	}

	// The perimeter of a triangle is the sum of the 3 side lengths.
	double perimeter = ab + bc + ca;
	printf("\nPerimeter of triangle ABC: %.2lf\n", perimeter);

	/* We will use Heron's formula to compute the square of the area:
	 * Area^2 = s(s - AB)(s - BC)(s - CA),
	 * AB, BC, CA are the side lengths, s is the semi-perimeter.
	 */
	double semi_p = perimeter / 2.0;
	double sq_area = semi_p * (semi_p - ab) * (semi_p - bc) * (semi_p - ca);
	printf("Square of the area of triangle ABC: %.2lf\n", sq_area);
}
