/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_handling
*/

#include "chain_list.h"
#include "vm.h"
#include "string_utils.h"
#include "console.h"
#include <stdlib.h>

void put_usage(void)
{
    my_putstr("USAGE\n./corewar");
    my_putstr(" [-dump nbr_cycle] [[-n prog_number] [-a load_address]");
    my_putstr("prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps the memory");
    my_putstr("after the number_cycle execution  (if the round isn't\nalready");
    my_putstr("over) with the following format 32bytes/line\nin hexadecimal");
    my_putstr("AOBCDEFE1DD3...)\n-n prog_number sets the next program's");
    my_putstr("number. By default, the first , the first free number in the");
    my_putstr("parameter order\n-a load_address sets the next program's");
    my_putstr("loading address. When no adress is specified,\n optimize the");
    my_putstr("adresses so that the processes are as far away\nfrom each");
    my_putstr("other as possible. the adresses are MEM_SIZE modulo.\n");
}

static void check_flags(char *argv[])
{
    char *triggers[] = {"-dump", "-a", "-n"};

    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '-') {
            if (my_streq(triggers[0], argv[i]) || my_streq(triggers[1], argv[i]) || my_streq(triggers[2], argv[i]))
                continue;
            else {
                my_puterr("Invalid Flags\n\n");
                put_usage();
                exit(84);
            }
        }
    }
}

void error_handling(char *argv[], int ac, vm_t *vm)
{
    if (ac > 23) {
        my_puterr("Too much arguments on binairie call\n\n");
        put_usage();
        exit(84);
    }
    if (ac == 2 && my_streq(argv[1], "-h")) {
        put_usage();
        exit(0);
    }
    check_flags(argv);
}