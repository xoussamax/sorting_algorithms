#include "deck.h"

/**
 * get_num - Converts a card value represented as a string to an integer.
 * @value: Pointer to a string representing a card value.
 *
 * Return: The numeric value of the card.
 */
int get_num(const char *value)
{
	int i;

	i = 0;
	while (value[i])
		i++;
	if (i == 1)
		return (value[0] - '0');
	else if (value[0] == '1')
		return (10);
	else if (value[0] == 'A')
		return (1);
	else if (value[0] == 'J')
		return (11);
	else if (value[0] == 'Q')
		return (12);
	return (13);
}

/**
 * swap - Swaps two nodes in a doubly linked list.
 * @a: Pointer to the first node to be swapped.
 * @b: Pointer to the second node to be swapped.
 * @list: Pointer to a pointer to the head of the linked list.
 *
 */
void swap(deck_node_t *a, deck_node_t *b, deck_node_t **list)
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
void cocktail_sort_list(deck_node_t **list)
{
	size_t swapped;
	deck_node_t *curr;
	int n1;
	int n2;

	if (!list || !(*list) || !(*list)->next)
		return;
	curr = *list;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (curr->next)
		{
			n1 = get_num(curr->card->value) + (curr->card->kind * 13);
			n2 = get_num(curr->next->card->value) + (curr->next->card->kind * 13);
			if (n1 > n2)
			{
				swap(curr, curr->next, list);
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
			n1 = get_num(curr->card->value) + (curr->card->kind * 13);
			n2 = get_num(curr->prev->card->value) + (curr->prev->card->kind * 13);
			if (n1 < n2)
			{
				swap(curr->prev, curr, list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * using the Cocktail Shaker
 *             (Bidirectional Bubble Sort) algorithm.
 *
 * @deck: Pointer to a pointer to the head of the deck.
 *
 */
void sort_deck(deck_node_t **deck)
{
	cocktail_sort_list(deck);
}
