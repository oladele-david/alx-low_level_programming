#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *list_len - returns amount of elements in a list(array)
 *@h:list
 *Return:amount of elements
 */

size_t list_len(const list_t *h)
{
	int a = 0;

	while (h != NULL)
{
	a++;
	h = h->next;
}
	return (a);
}
