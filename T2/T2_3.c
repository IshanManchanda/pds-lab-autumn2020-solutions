/* PDS Lab Autumn 2020, Test 2, Problem 3.
 * Ishan Manchanda, 2nd Feb 2021
 */

#include <stdio.h>
#include <string.h>

void encode (char msg[], char key[], char secret[]) {
	// Store length of key
	int len_key = strlen(key);

	// Iterate over each char in msg
	int i = 0;
	for (; msg[i] != '\0'; ++i) {
		if (msg[i] == ' ') {
			secret[i] = ' ';
			continue;
		}

		// The offset is determined by the char in the 'repeated key',
		// we can find that with a modulo.
		int offset = key[i % len_key] - 'a';

		// We offset the value of the msg char, then get the corresponding char.
		secret[i] = 'a' + ((msg[i] - 'a' + offset) % 26);
	}
	secret[i] = '\0';
}

void decode (char secret[], char key[], char msg[]) {
	int len_key = strlen(key);

	int i = 0;
	for (; secret[i] != '\0'; ++i) {
		if (secret[i] == ' ') {
			msg[i] = ' ';
			continue;
		}
		// Subtract the values, the 'a's cancel out.
		int r = (secret[i] - key[i % len_key]);

		// Add a 26 to the value if negative, and get the corresponding char.
		msg[i] = 'a' + ((r < 0) ? r + 26 : r);
	}
	msg[i] = '\0';
}

void remove_spaces(char str[]) {
	int pos = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] != ' ') {
			str[pos] = str[i];
			pos++;
		}
	}
	str[pos] = '\0';
}

int main() {
	char msg[1000], key[1000], secret[1000];

	printf("Enter msg (lowercase english characters): ");
	scanf("%[^\n]%*c", msg);
	printf("Enter key (lowercase english characters): ");
	scanf("%[^\n]%*c", key);

	remove_spaces(msg);
	remove_spaces(key);

	encode(msg, key, secret);
	printf("Encoded message: %s\n", secret);

	decode(secret, key, msg);
	printf("Decoded message: %s\n", msg);
}
