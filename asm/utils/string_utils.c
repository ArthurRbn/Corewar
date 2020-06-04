/*
** EPITECH PROJECT, 2020
** asm
** File description:
** string_utils
*/

#include "string_utils.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return (-1);
    for (; str[len] != 0; ++len);
    return (len);
}

int my_streq(char const *a, char const *b)
{
    int len_a = my_strlen(a);
    int len_b = my_strlen(b);

    if (len_a == -1 && len_b == -1)
        return (1);
    if (len_a != len_b)
        return (0);
    for (int i = 0; i < len_a; i++)
        if (a[i] != b[i])
            return (0);
    return (1);
}

char *my_strdup(char const *str)
{
    char *new;

    if (str == NULL)
        return (NULL);
    new = malloc(my_strlen(str) + 1);
    if (new == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    new[my_strlen(str)] = 0;
    return (new);
}

int is_whitespace(char val)
{
    char *whitespaces = " \t\n";

    for (int i = 0; whitespaces[i]; i++)
        if (whitespaces[i] == val)
            return (1);
    return (0);
}

char *my_strtrim(char const *str)
{
    int start = 0;
    int end = my_strlen(str);
    char *new;

    if (str == NULL || end <= 0)
        return (NULL);
    while (end > 0 && is_whitespace(str[end]))
        end--;
    while (start < end && is_whitespace(str[start]))
        start++;
    new = malloc(end - start + 1);
    if (new == NULL)
        return (NULL);
    for (int i = 0; i < end - start; i++)
        new[i] = str[start + i];
    new[end - start] = 0;
    return (new);
}
