#include "main.h"

/**
 * print_alphabet - Prints the English alphabet in lowercase.
 *
 * This function prints the English alphabet from 'a' to 'z'.
 *
 * Return: None.
 */

void print_alphabet(void)
{
	char n = 'a';

	while (n <= 'z')
	{
		_putchar(n);
		n++;
	}
	_putchar('\n');
}
