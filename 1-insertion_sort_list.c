#include "sort.h"

/**
 * insertion_sort_list - implementation of insertion sort
 * @list: doubly linked list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter = NULL, *iter_2 = NULL;
	int first, second;

	if (list == NULL)
		return;
	if ((*list)->next == NULL)
		return;

	iter = *list;
	while (iter != NULL)
	{
		if (iter->prev != NULL)
		{
			iter_2 = iter;
			iter = iter->next;
			while (iter_2->prev != NULL)
			{
				first = (iter_2->prev)->n;
				second = iter_2->n;
				if (first <= second)
					break;
				swap_nodes(iter_2->prev, iter_2);
				if (iter_2->prev == NULL)
					*list = iter_2;
				print_list(*list);
			}
		}
		else
			iter = iter->next;
	}
}

/**
 * swap_nodes - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 *
 */
void swap_nodes(listint_t *first, listint_t *second)
{
	if (first->prev != NULL)
		(first->prev)->next = second;
	if (second->next != NULL)
		(second->next)->prev = first;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	second->next = first;
}
