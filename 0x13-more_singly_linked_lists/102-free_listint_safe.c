#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 *looped_listint_len - Counts the number of unique nodes
 *                     in a looped listint_t linked list.
 *@head: A pointer to the head of the listint_t to check.
 *
 *Return: If the list is not looped - 0.
 *        Otherwise - the number of unique nodes in the list.
 */
size_t print_listint_safe(const listint_t *head);
size_t looped_listint_len(const listint_t *head);

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 *print_listint_safe - Prints a listint_t list safely.
 *@head: A pointer to the head of the listint_t list.
 *
 *Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;
	ptrs_t *ptrs_head = NULL, *new_node;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *) head, head->n);

			new_node = malloc(sizeof(ptrs_t));
			if (new_node == NULL)
			{
				perror("malloc");
				exit(98);
			}

			new_node->address = head;
			new_node->next = ptrs_head;
			ptrs_head = new_node;

			head = head->next;
		}

		printf("->[%p] %d\n", (void *) head, head->n);
	}

	/*Free the memory allocated for storing addresses */
	while (ptrs_head != NULL)
	{
		new_node = ptrs_head;
		ptrs_head = ptrs_head->next;
		free(new_node);
	}

	return (nodes);
}

/**
 *free_listint_safe - Frees a listint_t list safely.
 *@h: A pointer to the head of the listint_t list.
 *
 *Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0;
	ptrs_t *ptrs_head = NULL, *new_node;

	if (h == NULL || *h == NULL)
		return (nodes);

	while (*h != NULL)
	{
		new_node = malloc(sizeof(ptrs_t));
		if (new_node == NULL)
		{
			perror("malloc");
			exit(98);
		}

		new_node->address = *h;
		new_node->next = ptrs_head;
		ptrs_head = new_node;

		*h = (*h)->next;
		nodes++;
	}

	/*Free the memory allocated for storing addresses */
	while (ptrs_head != NULL)
	{
		new_node = ptrs_head;
		ptrs_head = ptrs_head->next;
		free(new_node);
	}

	return (nodes);
}

