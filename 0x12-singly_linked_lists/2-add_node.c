#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: twin pointer to the list_t list
 * @str: string to add in the nodes
 *
 * Return: the address of the  element, or NULL if it fails the program
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *instant;
	unsigned int len = 0;

	while (str[len])
		len++;

	instant = malloc(sizeof(list_t));
	if (!instant)
		return (NULL);

	instant->str = strdup(str);
	instant->len = len;
	instant->next = (*head);
	(*head) = instant;

	return (*head);
}

