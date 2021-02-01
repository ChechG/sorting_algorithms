#include "sort.h"

/**
 * insertion_sort_list -  sorts an array of integers in ascending order
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp_n, *temp_sort, *swapper;
	int len = dlistint_len(*list);

	if (len < 2 || list == NULL || *list == NULL)
		return;
	temp_n = *list;
	if (len == 2)
	{
		temp_n = temp_n->next;
		if (temp_n->n < (temp_n->prev)->n)
		{
			swap(temp_n, temp_n->prev, list);
			print_list(*list);
		}
		return;
	}
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
	if (dlistint_len(*list) == 2)
	{
		temp_sort->next = temp_sort->prev;
		temp_sort->prev = NULL;
		swapper->prev = swapper->next;
		swapper->next = NULL;
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

/**
 * dlistint_len - returns length of array
 * @list: doubly linked list
 * Return: size of list
 */
size_t dlistint_len(const listint_t *list)
{
	int n = 0;

	if (list->next == NULL)
	{
		return (0);
	}
	while (list != NULL)
	{
		n++;
		list = list->next;
	}
	return (n);
}
