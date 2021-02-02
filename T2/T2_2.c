/* PDS Lab Autumn 2020, Test 2, Problem 2.
 * Ishan Manchanda, 2nd Feb 2021
 */

#include <stdio.h>
#include <string.h>
#define MAX 100
#define SENTINEL -1
#define TYPE_DEPOSIT 0
#define TYPE_WITHDRAWAL 1

struct customer {
	int account_number;
	char name[51];
	int balance;
};

int add_customer (int account_number, char* name, int balance, struct customer bank[]) {
	int i = 0;
	for (; bank[i].account_number != SENTINEL; ++i)
		if (account_number == bank[i].account_number)
			return 1;

	struct customer new = {
		.account_number = account_number,
		.balance = balance
	};
	strcpy(new.name, name);
	bank[i + 1] = bank[i];
	bank[i] = new;
	return 0;
}

int transaction (int account_number, int request_type, int amount, struct customer bank[]) {
	int i = 0;
	for (; bank[i].account_number != account_number; ++i)
		// We've reached the end, so the account number is invalid.
		if (bank[i].account_number == SENTINEL)
			return 1;

	if (request_type == TYPE_WITHDRAWAL) {
		// Insufficient funds
		if (amount > bank[i].balance)
			return 2;

		// Transaction successful
		bank[i].balance -= amount;
	}
	else if (request_type == TYPE_DEPOSIT)
		bank[i].balance += amount;

	return 0;
}

void print_data(struct customer bank[]) {
	printf("---Begin Data---\n");
	for (int i = 0; bank[i].account_number != SENTINEL; ++i)
		printf(
			"Balance of %s (A/C number %d): %d\n",
			bank[i].name, bank[i].account_number, bank[i].balance
		);
	printf("---End Data---\n\n");
}

int main() {
	// We will use a "sentinel" structure to keep track of current length.
	struct customer bank[MAX + 1];
	struct customer sentinel = {.account_number = SENTINEL};
	bank[0] = sentinel;

	printf("Creating customer Ishan (A/C number 1234) with balance 2000.\n");
	add_customer(1234, "Ishan", 2000, bank);
	printf("Creating customer Vishal (A/C number 1235) with balance 3000.\n");
	add_customer(1235, "Vishal", 3000, bank);
	printf("Creating customer Yatin (A/C number 1236) with balance 1000.\n");
	add_customer(1236, "Yatin", 1000, bank);
	printf("3 customers created.\n");
	print_data(bank);

	printf("Creating customer Himadri (A/C number 1235) with balance 2000.\n");
	int error = add_customer(1235, "Himadri", 2000, bank);
	printf(error ? "A/C number already exists!\n" : "Customer added successfully!\n");
	print_data(bank);

	printf("Withdrawing 500 from A/C 1234.\n");
	error = transaction(1234, TYPE_WITHDRAWAL, 500, bank);
	if (error == 2)
		printf("Insufficient funds for withdrawal!\n");
	else if (error == 1)
		printf("Invalid A/C number!\n");
	else
		printf("Withdrawal successful!\n");
	print_data(bank);

	printf("Withdrawing 1200 from A/C 1236.\n");
	error = transaction(1236, TYPE_WITHDRAWAL, 1200, bank);
	if (error == 2)
		printf("Insufficient funds for withdrawal!\n");
	else if (error == 1)
		printf("Invalid A/C number!\n");
	else
		printf("Withdrawal successful!\n");
	print_data(bank);

	printf("Depositing 1000 to A/C 1235.\n");
	error = transaction(1235, TYPE_DEPOSIT, 1000, bank);
	printf(error ? "Invalid A/C number!\n" : "Deposit successful!\n");
	print_data(bank);

	printf("Depositing 1500 to A/C 123.\n");
	error = transaction(123, TYPE_DEPOSIT, 1500, bank);
	printf(error ? "Invalid A/C number!\n" : "Deposit successful!\n");
	print_data(bank);
}
