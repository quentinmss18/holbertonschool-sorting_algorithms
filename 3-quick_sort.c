#include "sort.h"

/**
 * swap_int - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index (pivot)
 * @size: Array size
 *
 * Return: Index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap_int(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively apply quick sort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Array size
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick sort (Lomuto)
 * @array: Array to sort
 * @size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
