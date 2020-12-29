/* PDS Lab Autumn 2020, Assignment 4, Problem 3.
 */

#include <stdio.h>
#include <string.h>

// We use a high max length as modern systems have enough RAM to not be
// affected by even millions of characters (a few MB).
#define MAXLENGTH 10000

int main() {
	int n, len, part_len;
	char str[MAXLENGTH];

	printf("Enter the string (upto %d characters): ", MAXLENGTH);
	// We don't need & as str is already a pointer to the first char
	scanf("%s", str);

	printf("Enter positive integer n: ");
	scanf("%d", &n);

	// Check if n is valid
	if (n < 1) {
		printf("n needs to be a positive integer!");
		return 0;
	}

	// The length needs to be an integral multiple of n
	len = strlen(str);
	if (len % n != 0) {
		printf("String cannot be divided into %d equal parts.\n", n);
		return 0;
	}

	// We don't need to employ strcmp on substrings or other such methods,
	// we simply check char-wise if the string repeats after every part_len.
	part_len = len / n;
	for (int i = 0; i < len; ++i) {
		if (str[i] != str[i % part_len]) {
			printf("String cannot be divided into %d equal parts.\n", n);
			return 0;
		}
	}

	// We use the precision specifier to print the first 'part_len' chars.
	printf("%.*s\n", part_len, str);
}
