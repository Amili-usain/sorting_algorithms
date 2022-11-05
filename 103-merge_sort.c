#include "sort.h"

/**
 * merge_sort - Implementation of merge sort
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	int mid;
	int *tmp_array = NULL;
	size_t i;

	if (size > 1)
	{
		mid = size / 2;
		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);
		tmp_array = merge(array, array + mid, mid, size - mid);
		printf("[Done]: ");
		print_array(tmp_array, size);
		if (tmp_array == NULL)
			return;
		for (i = 0; i < size; i++)
			array[i] = tmp_array[i];
		free(tmp_array);
	}
}

/**
 * merge - merges two sorted arrays
 * @arrayA: first array
 * @arrayB: second array
 * @size_A: size of the first array
 * @size_B: size of the second array
 *
 * Return: the sorted array
 */
int *merge(int *arrayA, int *arrayB, int size_A, int size_B)
{
	int *tmp_array = NULL;
	int i, j, k;

	tmp_array = malloc(sizeof(*tmp_array) * (size_A + size_B));
	if (tmp_array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arrayA, size_A);
	printf("[right]: ");
	print_array(arrayB, size_B);
	while (i < size_A && j < size_B)
	{
		if (arrayA[i] < arrayB[j])
			tmp_array[k++] = arrayA[i++];
		else
			tmp_array[k++] = arrayB[j++];
	}
	for (; i < size_A; i++)
		tmp_array[k++] = arrayA[i];
	for (; j < size_B; j++)
		tmp_array[k++] = arrayB[j];
	return (tmp_array);
}
