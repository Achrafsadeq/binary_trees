#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * array_to_heap - Builds a Max Binary Heap from an array
 * @array: Pointer to the first element of the array to convert
 * @size: Number of elements in the array
 * 
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        heap_t *new_node = heap_insert(&root, array[i]);
        if (!new_node)
        {
            fprintf(stderr, "Error inserting value %d into the heap\n", array[i]);
            return (NULL);
        }
    }

    return (root);
}
