#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps two nodes in a doubly linked list.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * @list: Pointer to the head of the linked list.
 *
 */

void swap(listint_t *a, listint_t *b, listint_t **list)
{
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->prev = a->prev;
	b->next = a;
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker
 *                     (Bidirectional Bubble Sort) algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 */
void cocktail_sort_list(listint_t **list)
{
	size_t swapped;
	listint_t *curr;

	if (!list || !(*list) || !(*list)->next)
		return;
	curr = *list;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap(curr, curr->next, list);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap(curr->prev, curr, list);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
