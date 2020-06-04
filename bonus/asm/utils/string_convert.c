/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** string_convert
*/

#include "string_convert.h"
#include "string_utils.h"
#include <stdlib.h>

unsigned int stoi(char const *str)
{
    int nb = 0;
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        } else
            break;
    return (nb);
}
