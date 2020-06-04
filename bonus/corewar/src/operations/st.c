/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** st
*/

#include "vm.h"

void op_st(process_t *process, vm_t *vm)
{
    int registre = process->instruction->params[0];
    int nb = process->instruction->params[1];
    int pc = process->pc;

    if (process->instruction->arg_types[1] == 1
    && (nb > 15 || nb < 0)) {
        process->carry = 0;
        return;
    }
    if (process->instruction->arg_types[0] != 1
    && process->instruction->arg_types[1] == 2
    && (registre > 15 || registre < 0))
        process->carry = 0;
    else {
        if (process->instruction->arg_types[1] == 3)
            int_to_mem(vm, process->champ_nb, pc + nb % IDX_MOD,
            process->reg[registre]);
        else if (process->instruction->arg_types[1] == 1)
            process->reg[nb] = process->reg[registre];
        process->carry = 1;
    }
}
