#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *print_listint_safe - prints a listint_t linked list
 *@head: pointer to the head of the listint_t linked list
 *
 *Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head,
		*fast = head;
	size_t count = 0;
	int loop_detected = 0;

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *) slow, slow->n);
		count++;

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			loop_detected = 1;
			break;
		}
	}

	if (!loop_detected)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			count++;
			head = head->next;
		}
	}
	else
	{
		printf("->[%p] %d\n", (void *) slow, slow->n);
		count++;
	}

	return (count);
}
