/*
** EPITECH PROJECT, 2020
** asm
** File description:
** console
*/

#include "console.h"
#include "string_utils.h"
#include <unistd.h>

static void write_to_fd(char const *str, int fd)
{
    int len = my_strlen(str);

    if (len < 0 || fd < 0)
        return;
    write(fd, str, len);
}

void my_putstr(char const *str)
{
    write_to_fd(str, 1);
}

void my_puterr(char const *str)
{
    write_to_fd(str, 2);
}
