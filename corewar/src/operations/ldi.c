/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** ldi
*/

#include "vm.h"

static int take_info(process_t *process, vm_t *vm)
{
    int nb = process->instruction->params[0];

    if (process->instruction->arg_types[1] == 1 && (nb >= 16 || nb < 0))
        return (-8484);
    if (process->instruction->arg_types[0] == 1 && nb < 16 && nb >= 0)
        return (process->reg[nb]);
    else if (process->instruction->arg_types[0] == 2)
        return (nb);
    else
        return (mem_to_int(vm->mem, process->pc + nb % IDX_MOD, 2));
    return (-8484);
}

static int add_nb(int x, int y, process_t *process, vm_t *vm)
{
    int nb = process->instruction->params[0];

    if (process->instruction->arg_types[1] == 1 && (nb >= 16 || nb < 0))
        return (-8484);
    if (process->instruction->arg_types[1] != 3) {
        if (process->instruction->arg_types[1] == 1)
            return (x + process->instruction->params[y]);
        else
            return (x + y);
    }
    return (-8484);
}

static int load_to_register(int x, int y, process_t *process, vm_t *vm)
{
    if (process->instruction->arg_types[2] != 1)
        return (-8484);
    else if (process->instruction->arg_types[2] == 1 && (y >= 16 || y < 0))
        return (-8484);
    else {
        process->reg[y] = mem_to_int(vm->mem, process->pc + x % IDX_MOD, 4);
    }
    return (0);
}

void op_ldi(process_t *process, vm_t *vm)
{
    int nb = take_info(process, vm);
    int nb_two = process->instruction->params[1];
    int registre = process->instruction->params[2];
    int check = 0;
    int result = 0;

    if (nb == -8484) {
        process->carry = 0;
        return;
    }
    result = add_nb(nb, nb_two, process, vm);
    if (result == -8484) {
        process->carry = 0;
        return;
    }
    check = load_to_register(result, registre, process, vm);
    if (check == -8484)
        process->carry = 0;
    else
        process->carry = 1;
}
