#include "lists.h"

/**
 *add_node_end - Add a new node at the end of a list in program.
 *@head: Address of the first node in a list.
 *@str: Address of the string to insert into the new node created.
 *Return: Address of the new node.
 **/

list_t* add_node_end(list_t **head, const char *str)
{
	list_t *cond, *cond2;
	unsigned int length = 0;

	if (str == NULL)
		return (NULL);

	cond = malloc(sizeof(list_t));
	if (cond == NULL)
		return (NULL);

	cond->str = strdup(str);
	if (cond->str == NULL)
	{
		free(cond);
		return (NULL);
	}

	while (str[length])
		length++;
	cond->len = length;
	cond->forward = NULL;

	if (*head == NULL)
	{
		*head = cond;
		return (cond);
	}

	cond2 = *head;
	while (cond2->forward)
		cond2 = cond2->forward;
	cond2->forward = cond;
	return (cond);
}
