#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 * @a: Pointer to the first node to be swapped.
 * @b: Pointer to the second node to be swapped.
 *
 */
void swap(listint_t **list, listint_t *a, listint_t *b)
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
 * insertion_sort_list - Sorts a doubly linked list using
 * the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i;
	listint_t *j;
	listint_t *prev;

	if (!list || !(*list) || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		prev = j->prev;
		while (prev != NULL && prev->n > j->n)
		{
			swap(list, prev, j);
			prev = j->prev;
			print_list(*list);
		}
		i = i->next;
	}
}
