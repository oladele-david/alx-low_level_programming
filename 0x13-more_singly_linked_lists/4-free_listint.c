#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *free_listint - frees a listint_t list
 *@head: pointer to the head of the list
 */

void free_listint(listint_t *head)
{
	listint_t *current;
	listint_t *next_node;

	current = head;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
