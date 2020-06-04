/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** ld
*/

#include "vm.h"

void op_ld(process_t *process, vm_t *vm)
{
    int registre = process->instruction->params[1];
    int nb = process->instruction->params[0];
    int pc = process->pc;

    if (process->instruction->arg_types[0] == 3)
        nb = mem_to_int(vm->mem, pc + nb % IDX_MOD, 4);
    if (process->instruction->arg_types[0] == 1
    && process->instruction->arg_types[1] != 1
    && (registre > 15 || registre < 0))
        process->carry = 0;
    else {
        process->reg[registre] = nb;
        process->carry = 1;
    }
}
