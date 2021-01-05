/* PDS Lab Autumn 2020, Assignment 2, Problem 3.
 * Ishan Manchanda, 15th Dec 2020
 * Input the (int, int) coordinates of 4 points on a 2d plane from the user.
 * Determine if the 4 points form a rectangle.
 */

#include <stdio.h>


// We'll use a Point struct to conveniently handle the coordinate data.
struct Point {
	int x, y;
};

// Helper function to find the squared distance between 2 points.
long sq_dist(struct Point a, struct Point b) {
	int delta_x = a.x - b.x;
	int delta_y = a.y - b.y;
	return delta_x * delta_x + delta_y * delta_y;
}

// Helper function that checks if 4 points form a rectangle
// when taken in cyclic order (abcd).
int is_rectangle(struct Point points[4]) {
	// Check opposite sides are equal
	long ab_sq = sq_dist(points[0], points[1]);
	long cd_sq = sq_dist(points[2], points[3]);
	if (ab_sq != cd_sq)
		return 0;

	// We check one pair at a time to prevent extra computation
	long bc_sq = sq_dist(points[1], points[2]);
	long da_sq = sq_dist(points[3], points[0]);
	if (bc_sq != da_sq)
		return 0;

	// Now check for right angle using Pythagoras Theorem
	long ca_sq = sq_dist(points[2], points[0]);
	if (ab_sq + bc_sq != ca_sq)
		return 0;

	return 1;
}

int main() {
	// Input the coordinates of the points from the user
	struct Point points[4];
	printf("Enter the coordinates in the format: x y\n");

	for (int i = 0; i < 4; ++i) {
		printf("Enter coordinates of Point %d: ", i + 1);
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	// Check if the points form a rectangle when taken in given order (abcd).
	if (is_rectangle(points)) {
		printf("\nThe points form a rectangle!");
		return 0;
	}

	// Check if points form a rectangle when taken in acbd order.
	struct Point temp = points[1];
	points[1] = points[2];
	points[2] = temp;
	if (is_rectangle(points)) {
		printf("\nThe points form a rectangle!");
		return 0;
	}

	// Check if points form a rectangle when taken in acdb order.
	points[2] = points[3];
	points[3] = temp;
	if (is_rectangle(points)) {
		printf("\nThe points form a rectangle!");
		return 0;
	}

	printf("\nThe points do not form a rectangle!");
}
