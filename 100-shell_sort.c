#include "sort.h"

/**
 * shell_sort -  sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 0, i, j;
	int temp;

	if (size < 2)
		return;
	while (n <= size)
		n = n * 3 + 1;
	while (n > 1)
	{
		for (i = 0; i < (size - n); i++)
		{
			n = (n - 1) / 3;
			for (j = i + n; j > 0 && j >= n; j = j - n)
			{
				if (array[j] < array[j - n])
				{
					temp = array[j];
					array[j] = array[j - n];
					array[j - n] = temp;
				}
			}
		}
		print_array(array, size);
	}
}
