/* PDS Lab Autumn 2020, Assignment 5, Problem 2.
 * Ishan Manchanda, 12th Jan 2021
 */

#include <stdio.h>

int reverse(int n) {
	// Base case: Single digit
	if (n < 10) return n;

	// Find the power of 10 just less than n: 10 ^ (Number_of_Digits - 1).
	// Note: We attain a number higher than n so this is prone to overflows.
	// Here, however, we can simply use a long long as n is given to be an int.
	// In a real-world scenario we would make a slight modification to the
	// algorithm: Check if the quotient is exactly 1 digit.
	long long exp10 = 10;
	for (; (n / exp10) > 0; exp10 *= 10);
	exp10 /= 10;

	// Find leading digit and the rest of the number.
	int leading_digit = n / exp10, trailing = n % exp10;

	// Recur - We reverse the rest of the number, and then append leading digit.
	return reverse(trailing) * 10 + leading_digit;
}

int main() {
	int n;

	printf("Enter integer n: ");
	scanf("%d", &n);

	// Take the modulus value if negative input.
	if (n < 0) n = -n;

	printf("Reverse of n: %d\n", reverse(n));
}
