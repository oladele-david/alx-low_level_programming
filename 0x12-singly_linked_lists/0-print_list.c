#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *print_list - prints all elements of a list_t list
 *@h:list to print
 *
 *Return:no. of nodes in struct function
 */

size_t print_list(const list_t *h)
{
	size_t a = 0;
	const list_t *cons = h;

	for (a = 0; cons; a++)
	{
		if (cons->str == NULL)
			printf("[0] (nil)\n");
		else
		{
			printf("[%d] %s\n", cons->len, cons->str);
		}
		cons = cons->next;
	}
	return (a);
}
