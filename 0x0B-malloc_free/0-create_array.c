#include <stdlib.h>

/**
 * *create_array - create an array of chars,
 * and initialize it with a specific char.
 * @size: sizes of the array
 * @c: char to initialize
 * Return: pointer to the array initialized or NULL
 */

char *create_array(unsigned int size, char c)
{
char *s = malloc(size);
if (size == 0 || m == 0)
return (0);

while (size--)
s[size] = c;

return (s);
}
