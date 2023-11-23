#include "lists.h"

/**
 *free_listint_safe - free a listint safely
 *@h:pointer to listint
 *Return:size of list free'd nodes
 */
size_t free_listint_safe(listint_t **h)
{
	int t_seps;
	size_t i = 0;
	listint_t *temp;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}

	while (*h)
	{
		t_seps = *h - (*h)->next;
		if (t_seps > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			i++;
		}
		else
		{
			free(*h);
			*h = NULL;
			i++;
			break;
		}
	}

	*h = NULL;
	return (i);
}
