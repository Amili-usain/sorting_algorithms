#include "sort.h"

/**
 * cocktail_sort_list - cocktail sorting method
 * @list: head of linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int swapped = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		swapped = 0;
		for (tmp = *list; tmp->next != NULL; tmp = tmp->next)
		{
			if ((tmp->n) > ((tmp->next)->n))
			{
				swap_link(tmp, tmp->next, list);
				print_list(*list);
				swapped = 1;
				tmp = tmp->prev;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; tmp->prev != NULL; tmp = tmp->prev)
		{
			if ((tmp->n) < ((tmp->prev)->n))
			{
				swap_link(tmp->prev, tmp, list);
				swapped = 1;
				print_list(*list);
				tmp = tmp->next;
			}
		}
	} while (swapped);
}

/**
 * swap_link - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 * @head: head of list
 *
 */
void swap_link(listint_t *first, listint_t *second, listint_t **head)
{
	listint_t *a = first->prev;
	listint_t *b = second->next;

	if (a != NULL)
		(a)->next = second;
	else
		*head = second;
	first->prev = second;
	first->next = b;
	second->prev = a;
	second->next = first;
	if (b)
		(b)->prev = first;
}
