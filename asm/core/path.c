/*
** EPITECH PROJECT, 2020
** asm
** File description:
** path
*/

#include "path.h"
#include "string_utils.h"
#include <stdlib.h>

char *get_output_path(char const *input_path)
{
    int len = my_strlen(input_path);
    char *new = malloc(len + 4 + 1);
    char const *end = ".cor";
    int i = 0;

    for (; i < len; i++)
        new[i] = input_path[i];
    if (my_strendswith(input_path, ".s"))
        i -= 2;
    for (int j = 0; end[j]; j++)
        new[i++] = end[j];
    new[i] = 0;
    return (new);
}
