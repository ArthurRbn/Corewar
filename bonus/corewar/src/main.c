/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "chain_list.h"
#include "console.h"

int main(int argc, char **argv)
{
    vm_t *vm = vm_init(argc, argv);

    execution_loop(vm);
    return 0;
}
