/* PDS Lab Autumn 2020, Assignment 2, Problem 1.
 * Ishan Manchanda, 15th Dec 2020
 * Input the (int) side length, L, of a square and the radius, R, of a circle.
 * Determine whether one shape can be placed inside the other.
 */

#include <stdio.h>


int main() {
	int side, radius;

	// Input the values from the user
	printf("Enter square's side length: ");
	scanf("%d", &side);

	printf("Enter circle's radius: ");
	scanf("%d", &radius);

	/* A square can be placed inside a circle if its diagonal length is less
	 * than or equal to the circle's diameter: side * sqrt(2) <= radius * 2
	 * or: side^2 <= radius^2 * 2
	 */
	if ((side * side) <= (radius * radius * 2))
		printf("The square can be placed inside the circle!");

	// A circle can be placed inside a square if its diameter is less than
	// or equal to the square's side length.
	else if ((radius * 2) <= side)
		printf("The circle can be placed inside the square!");

	else
		printf("Neither shape can be placed inside the other!");
}
