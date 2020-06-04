/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** aff
*/

#include "vm.h"
#include "string_convert.h"
#include "console.h"
#include <stdlib.h>

void op_aff(process_t *process, vm_t *vm)
{
    int reg = process->instruction->params[0];
    char *nb = NULL;

    if (process->instruction->arg_types[0] != 1 || (reg > 15 && reg < 0))
        return;
    nb = itos(process->reg[reg], 0);
    my_putstr(nb);
}
