#include "sort.h"

/**
 * shell_sort - implementation of shell_sort
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int tmp;

	while (interval < size)
		interval = interval * 3 + 1;

	while (interval)
	{
		for (i = interval; i < size; i += 1)
		{
			tmp = array[i];
			for (j = i; j >= interval && array[j - interval] > tmp; j -= interval)
				array[j] = array[j - interval];
			array[j] = tmp;
		}
		if (interval < size)
			print_array(array, size);
		interval /= 3;
	}
}
