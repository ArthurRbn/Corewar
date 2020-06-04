/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "array_utils.h"
#include "compiler.h"
#include "path.h"
#include "string_utils.h"
#include "console.h"
#include "file.h"
#include <stdlib.h>

static int usage(void (*put)(char const *), char const *program, int ret)
{
    put("USAGE\n\t");
    put(program);
    put(" file_name[.s]\n\n"
    "DESCRIPTION\n"
    "\tfile_name"
    "\tfile in assembly language to be converted into file_name.cor, an\n"
    "\t\t\texecutable in the Virtual Machine.\n");
    return (ret);
}

static int error(char const *msg)
{
    my_puterr(msg);
    my_puterr("\n");
    return (84);
}

int main(int ac, char **av)
{
    char **lines;
    char *output;
    int res;

    if (ac != 2)
        return (usage(my_puterr, av[0], 84));
    if (my_streq(av[1], "-h"))
        return (usage(my_putstr, av[0], 0));
    lines = read_file(av[1]);
    if (lines == NULL)
        return (error("Error: could not read input file."));
    output = get_output_path(av[1]);
    res = compile(lines, output);
    free_array((void **) lines);
    free(output);
    return (res);
}
