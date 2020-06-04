/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** zjmp
*/

#include "vm.h"

void op_zjmp(process_t *process, vm_t *vm)
{
    int nb = process->instruction->params[0];

    if (process->carry == 1 && process->instruction->arg_types[0] == 2) {
        process->pc = process->pc + nb % IDX_MOD;
    }
}
