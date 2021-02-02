/* PDS Lab Autumn 2020, Test 2, Problem 1.
 * Ishan Manchanda, 2nd Feb 2021
 */

#include <stdio.h>
#include <string.h>

void censor(char* s, char* w) {
	// Pointer to first character of substrings
	char *pos;
	int i = 0, len = strlen(w);

	// strstr returns a pointer to the first character of substring (if found)
	// We add i so that we don't check the same part of the string multiple times.
	// After we have found an occurrence, we only need to check the str after it.
	while ((pos = strstr(s+i, w)) != NULL)
		// Replace the first 'n' characters from the position
		for (i = 0; i < len; ++i)
			pos[i] = '*';
}

void censor_recursive(char* s, char* w) {
	// Base Case: Empty string.
	if (s[0] == '\0') return;

	size_t len = strlen(w);
	// Check if substring found at position 0
	if (!strncmp(s, w, len)) {
		// If yes, replace first 'n' characters with asterisks
		for (int i = 0; i < len; ++i)
			s[i] = '*';

		// We've already replaced first 'n' characters, we can skip those.
		return censor_recursive(s+len, w);
	}
	// Check next position.
	return censor_recursive(s+1, w);
}

int main() {
	char s[1000], w[100], s1[1000], s2[1000];

	printf("Enter string s: ");
	scanf("%s", s);

	printf("Enter string w: ");
	scanf("%s", w);

	// We create a duplicate string to demonstrate both functions.
	strcpy(s1, s);
	censor(s1, w);
	printf("String censored non-recursively: %s\n", s1);

	censor_recursive(s, w);
	printf("String censored recursively: %s\n", s);
}
