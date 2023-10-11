#include "main.h"

/**
 * print_alphabet_x10 - Prints the English alphabet in lowercase 10 times.
 *
 * This function prints the English alphabet from 'a' to 'z'.
 *
 * Return: None.
 */

void print_alphabet_x10(void)
{
	int lines;

	for (lines = 0; lines < 10; lines++)
	{
		char n = 'a';

		while (n <= 'z')
		{
			_putchar(n);
			n++;
		}
		_putchar('\n');
	}
}
