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

char *itos(int val, int digits)
{
    char *res = malloc(20);
    int res_i = 0;
    char *dest_base = "0123456789";
    int dest_base_size = my_strlen(dest_base);

    for (int i = 0; i < digits; i++)
        res[i] = '0';
    res[digits] = 0;
    res[res_i++] = dest_base[val % dest_base_size];
    while (val != 0)
        res[res_i++] = dest_base[(val /= dest_base_size) % dest_base_size];
    if (digits == 0)
        res[res_i - 1] = 0;
    my_revstr(res);
    return res;
}

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);
    char temp;

    for (int i = 0; i < str_len / 2; i++) {
        temp = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = temp;
    }
    return (str);
}
