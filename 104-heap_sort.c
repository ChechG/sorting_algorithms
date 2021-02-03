#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort.
 * @size: size of array.
 */
void heap_sort(int *array, size_t size)
{
	int n = (int)size, end, temp;

	heapify(array, n);
	end = n - 1;
	while (end > 0)
	{
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		end = end - 1;
		print_array(array, n);
		siftDown(array, 0, end, n);
	}
}

/**
 * heapify - sorts an array of integers in ascending order
 * @array: array to sort.
 * @n: size of array.
 */
void heapify(int *array, int n)
{
	int start;

	start = (n - 2) / 2;
	while (start >= 0)
	{
		siftDown(array, start, n - 1, n);
		start = start - 1;
	}
}

/**
 * siftDown - sorts an array of integers in ascending order
 * @array: array to sort.
 * @start: start index of arrray.
 * @end: end index of array.
 * @n: size of array.
 */
void siftDown(int *array, int start, int end, int n)
{
	int root, child, temp = 0;
	(void)n;

	root = start;
	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child = child + 1;
		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			root = child;
			print_array(array, n);
		}
		else
			return;
	}
}