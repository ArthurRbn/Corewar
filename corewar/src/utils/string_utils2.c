/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** string_utils2
*/

#include <stdlib.h>

int arr_len(char **arr)
{
    int total = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        total++;
    }
    return (total);
}