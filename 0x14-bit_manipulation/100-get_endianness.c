#include "main.h"

/**
 *get_endianness - Checks the endianness of the system.
 *
 *Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int test_endian = 1;
	char *byte_ptr = (char*) &test_endian;

	/*If the least significant byte is at the lowest address, it's little endian */
	return (*byte_ptr);
}
