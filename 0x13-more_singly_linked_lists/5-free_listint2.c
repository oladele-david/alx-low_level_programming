#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *free_listint2 - frees a listint_t list and sets the head to NULL
 *@head: pointer to the pointer of the head of the list
 */

void free_listint2(listint_t **head)
{
	listint_t *current;
	listint_t *next_node;

	if (head == NULL || *head == NULL)
		return;

	current = *head;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	*head = NULL;
}
