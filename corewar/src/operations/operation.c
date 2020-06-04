/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add
*/

#include "vm.h"
#include "op.h"

void op_add(process_t *process, vm_t *vm)
{
    for (int i = 0; i < 3; i++) {
        if (process->instruction->arg_types[i] != 1 && (process->instruction->params[i] > 0 || process->instruction->params[i] < 15))
            process->carry = 0;
        else {
            process->carry = 1;
            process->reg[2] =
            process->reg[0] + process->reg[1];
        }
    }
}

void op_sub(process_t *process, vm_t *vm)
{
    for (int i = 0; i < 3; i++) {
        if (process->instruction->arg_types[i] != 1 && (process->instruction->params[i] > 0 || process->instruction->params[i] < 15))
            process->carry = 0;
        else {
            process->carry = 1;
            process->reg[2] =
            process->reg[0] - process->reg[1];
        }
    }
}

static void op_and_check(process_t *process, vm_t *vm, int *info)
{
    for (int i = 0; i < 2; i++) {
        if (process->instruction->arg_types[i] == 1 && (process->instruction->params[i] > 0 || process->instruction->params[i] < 15)) {
            process->carry = 0;
            return;
        }
    }
    if (process->instruction->arg_types[2] != 1 && (process->instruction->params[2] > 0 || process->instruction->params[2] < 15))
        process->carry = 0;
    else {
        process->carry = 1;
        process->reg[2] = info[0] & info[1];
    }
}

void op_and(process_t *process, vm_t *vm)
{
    int info[] = {0, 0};

    for (int i = 0; i < 2; i++) {
        if (process->instruction->arg_types[i] == 1)
            info[i] = process->reg[i];
        if (process->instruction->arg_types[i] == 2)
            info[i] = process->instruction->params[i];
        if (process->instruction->arg_types[i] == 3)
            info[i] = mem_to_int(vm->mem, process->pc +
            process->instruction->params[i], REG_SIZE);
        op_and_check(process, vm, info);
    }
}