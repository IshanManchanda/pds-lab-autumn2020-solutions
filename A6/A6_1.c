/* PDS Lab Autumn 2020, Assignment 6, Problem 1.
 * Ishan Manchanda, 19'th Jan 2021
 */

#include <stdio.h>

void wrong_swap(int a, int b) {
	printf("Values of a, b before wrong_swap: %d, %d\n", a, b);
	printf("Address of a, b before wrong_swap: %p, %p\n", &a, &b);

	int temp = a;
	a = b;
	b = temp;

	printf("Values of a, b after wrong_swap: %d, %d\n", a, b);
	printf("Address of a, b after wrong_swap: %p, %p\n\n", &a, &b);
}

void swap(int* a, int* b) {
	printf("Values of a, b before swap: %d, %d\n", *a, *b);
	printf("Address of a, b before swap: %p, %p\n", a, b);

	// Standard pointer swap algorithm.
	int temp = *a;
	*a = *b;
	*b = temp;

	printf("Values of a, b after swap: %d, %d\n", *a, *b);
	printf("Address of a, b after swap: %p, %p\n\n", a, b);
}

int main() {
	int n1 = 10, n2 = 5;

	printf("Values of n1, n2 before wrong_swap: %d, %d\n", n1, n2);
	printf("Address of n1, n2 before wrong_swap: %p, %p\n\n", &n1, &n2);

	wrong_swap(n1, n2);

	printf("Values of n1, n2 after wrong_swap: %d, %d\n", n1, n2);
	printf("Address of n1, n2 after wrong_swap: %p, %p\n\n", &n1, &n2);

	swap(&n1, &n2);

	printf("Values of n1, n2 after swap: %d, %d\n", n1, n2);
	printf("Address of n1, n2 after swap: %p, %p\n", &n1, &n2);
}
