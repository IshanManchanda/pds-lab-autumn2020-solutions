/* PDS Lab Autumn 2020, Test 1, Problem 4.
 * Ishan Manchanda, 5th Jan 2021
 */

#include <stdio.h>

// We use a high max length as modern systems have enough RAM to not be
// affected by even millions of characters (a few MB).
#define MAXLENGTH 1000

int main() {
	int a, b;
	char temp, str[MAXLENGTH];

	printf("Enter the string (upto %d characters): ", MAXLENGTH);
	// We don't need & as str is already a pointer to the first char
	scanf("%s", str);

	printf("Enter position a: ");
	scanf("%d", &a);
	printf("Enter position b: ");
	scanf("%d", &b);

	// If a and b are the same index, we need not do anything

	// If a is less than b, we need to rotate the substring to the left
	if (a < b) {
		// Store the char at a in temp
		temp = str[a];

		// Move all elements in [a + 1 -> b] one space to the left
		for (int i = a; i < b; ++i)
			str[i] = str[i + 1];

		// Finally, update position b to have the value in temp
		str[b] = temp;
	}

	// If a is greater than b, we need to rotate the substring to the right
	else if (a > b) {
		// Store the char at a in temp
		temp = str[a];

		// Move all elements in [b -> a - 1] one space to the right
		for (int i = a; i > b; --i)
			str[i] = str[i - 1];

		// Finally, update position b to have the value in temp
		str[b] = temp;
	}

	printf("Output: %s\n", str);
}
