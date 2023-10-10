#include "main.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
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
