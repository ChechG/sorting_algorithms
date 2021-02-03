#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
listint_t **swap(listint_t *temp_sort, listint_t *swapper, listint_t **list);
size_t dlistint_len(const listint_t *list);
int partition(int *array, int lo, int hi, size_t size);
void rec_quick_sort(int *array, int lo, int hi, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void TopDownMergeSort(int *array, int *barray, int n);
void TopDownSplitMerge(int *barray, int ini, int end, int *array);
void TopDownMerge(int *array, int ini, int mid, int end, int *barray);
void CopyArray(int *array, int ini, int end, int *barray);
void heap_sort(int *array, size_t size);
void siftDown(int *array, int start, int end, int n);
void heapify(int *array, int n);
void radix_sort(int *array, size_t size);
void switch1(int *original, int *cambio, int size);
int max_int(int *array, int n);

#endif
