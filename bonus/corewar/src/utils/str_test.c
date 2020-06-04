/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** str_test
*/

int is_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}