/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** sti
*/

#include "vm.h"

static int take_info_register(process_t *process, vm_t *vm)
{
    int nb = process->instruction->params[0];

    if (process->instruction->arg_types[0] == 1 && nb < 16 && nb >= 0)
        return (process->reg[nb]);
    return (-8484);
}

static int take_info(process_t *process, vm_t *vm)
{
    int nb = process->instruction->params[1];

    if (process->instruction->arg_types[1] == 1 && (nb >= 16 || nb < 0))
        return (-8484);
    if (process->instruction->arg_types[1] == 1 && nb < 16 && nb >= 0)
        return (process->reg[nb]);
    else if (process->instruction->arg_types[1] == 2)
        return (nb);
    else
        return (mem_to_int(vm->mem, process->pc + nb % IDX_MOD, 4));
    return (-8484);
}

static int take_info_two(process_t *process, vm_t *vm)
{
    int nb = process->instruction->params[2];

    if (process->instruction->arg_types[1] == 1 && nb < 16 && nb >= 0)
        return (process->reg[nb]);
    else if (process->instruction->arg_types[1] == 2)
        return (nb);
    else
        return (-8484);
    return (-8484);
}

void op_sti(process_t *process, vm_t *vm)
{
    int registre = take_info_register(process, vm);
    int nb = take_info(process, vm);
    int nb_two = take_info_two(process, vm);

    if (registre == -8484 || nb == -8484 || nb_two == -8484)
        return;
    int_to_mem(vm, process->champ_nb, process->pc + (nb + nb_two) % IDX_MOD, 4);
}
