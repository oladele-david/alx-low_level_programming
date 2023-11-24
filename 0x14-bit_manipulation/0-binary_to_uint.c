#include "main.h"

/**
 *binary_to_uint - Converts a binary number to an unsigned int.
 *@b: A string containing the binary number.
 *
 *Return: The converted number, or 0 if there is an invalid character
 *or if the input string is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b == '0' || *b == '1')
		{
			result = result * 2 + (*b - '0');
			b++;
		}
		else
		{
			return (0); /*Invalid character in the binary string */
		}
	}

	return (result);
}
