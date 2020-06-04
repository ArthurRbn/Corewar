/*
** EPITECH PROJECT, 2020
** asm
** File description:
** string_utils1
*/

#include "string_utils.h"
#include <stddef.h>

void my_strendat(char *str, char val)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i++)
        if (str[i] == val) {
            str[i] = 0;
            break;
        }
}

int my_strendswith(char const *str, char const *end)
{
    int len = my_strlen(str);
    int len_end = my_strlen(end);

    if (str == NULL || end == NULL)
        return (-1);
    if (len < len_end)
        return (0);
    for (int i = 0; i < len_end; i++)
        if (str[len - len_end + i] != end[i])
            return (0);
    return (1);
}

int my_strstartswith(char const *str, char const *start)
{
    int len = my_strlen(str);
    int len_start = my_strlen(start);

    if (str == NULL || start == NULL)
        return (-1);
    if (len < len_start)
        return (0);
    for (int i = 0; i < len_start; i++)
        if (str[i] != start[i])
            return (0);
    return (1);
}

static int contains(char const *allowed, char val)
{
    for (int i = 0; allowed[i]; i++)
        if (val == allowed[i])
            return (1);
    return (0);
}

int my_strissub(char const *str, char const *allowed)
{
    if (str == NULL || allowed == NULL)
        return (-1);
    for (int i = 0; str[i]; i++)
        if (contains(allowed, str[i]) == 0)
            return (0);
    return (1);
}
