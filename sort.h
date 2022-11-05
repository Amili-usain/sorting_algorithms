#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

#define LEFT(i) ((2 * i) + 1)
#define RIGHT(i) ((2 * i) + 2)
#define PARENT(i) ((i - 1) / 2)
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


/*printing funcs*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*sorting algos*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*helpers*/
void back(int *array, int a, int b, size_t size);
void swap_nodes(listint_t *first, listint_t *second);
void swap_link(listint_t *first, listint_t *second, listint_t **head);
void swaper(int a, int b, int *array);
void back(int *array, int a, int b, size_t size);
int partition(int *array, size_t low, size_t hi, size_t size);
void heapify(int *array, size_t size, size_t original_s);
int *merge(int *arrayA, int *arrayB, int size_A, int size_B);

#endif /*SORT*/
