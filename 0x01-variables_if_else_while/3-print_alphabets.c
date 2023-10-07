#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Returns the Aplhabets
 */
int main(void)
{
	char lowercase_letter = 'a';
	char uppercase_letter = 'A';

	while (lowercase_letter <= 'z')
	{
		putchar(lowercase_letter);
		lowercase_letter++;
	}

	while (uppercase_letter <= 'Z')
	{
		putchar(uppercase_letter);
		uppercase_letter++;
	}
	putchar('\n');
	return (0);
}
