#include "sort.h"

/**
 * insertion_sort_list -  sorts an array of integers in ascending order
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp_n, *temp_sort, *swapper;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;
	temp_n = *list;
	while (temp_n != NULL)
	{
		temp_sort = temp_n;
		if (temp_sort->prev != NULL)
		{
			while (temp_sort->n < (temp_sort->prev)->n && temp_sort->prev != NULL)
			{
				swapper = temp_sort->prev;
				if (swapper->prev == NULL)
				{
					swap(temp_sort, swapper, list);
					print_list(*list);
					break;
				}
				swap(temp_sort, swapper, list);
				print_list(*list);
			}
		}
		temp_n = temp_n->next;
	}
}

/**
 * swap - sorts an array of integers in ascending order
 * @temp_sort: temporaary node
 * @swapper: node to swap
 * @list: doubly linked list
 * Return: doubly linked list
 */
listint_t **swap(listint_t *temp_sort, listint_t *swapper, listint_t **list)
{
	listint_t *aux_prev, *aux_next = temp_sort->next;

	swapper = temp_sort->prev;
	if (temp_sort->next == NULL && swapper->prev == NULL)
	{
		temp_sort->prev = NULL;
		temp_sort->next = swapper;
		temp_sort->next->next = NULL;
		swapper->prev = temp_sort;
		*list = temp_sort;
	}
	else if (swapper->prev == NULL)
	{
		temp_sort->prev = NULL;
		temp_sort->next = swapper;
		swapper->prev = temp_sort;
		swapper->next = aux_next;
		aux_next->prev = swapper;
		*list = temp_sort;
	}
	else if (temp_sort->next == NULL)
	{
		aux_prev = swapper->prev;
		aux_prev->next = temp_sort;
		temp_sort->prev = aux_prev;
		temp_sort->next = swapper;
		swapper->prev = temp_sort;
		swapper->next = NULL;
	}
	else
	{
		aux_prev = swapper->prev;
		aux_prev->next = temp_sort;
		temp_sort->prev = aux_prev;
		temp_sort->next = swapper;
		swapper->next = aux_next;
		swapper->prev = temp_sort;
		aux_next->prev = swapper;
	}
	return (list);
}