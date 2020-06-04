/*
** EPITECH PROJECT, 2020
** asm
** File description:
** array_utils
*/

#include "array_utils.h"
#include <stdlib.h>

int array_len(void **arr)
{
    int len = 0;

    if (arr == NULL)
        return (-1);
    for (; arr[len] != NULL; len++);
    return (len);
}

void custom_free_array(void **arr, void (*func)(void *))
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i]; i++)
        if (arr[i] != NULL)
            func(arr[i]);
    free(arr);
}

void free_array(void **arr)
{
    custom_free_array(arr, free);
}
