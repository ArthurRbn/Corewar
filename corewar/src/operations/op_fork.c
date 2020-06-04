/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** op_fork
*/

#include "vm.h"
#include "op.h"
#include "chain_list.h"
#include <stdlib.h>

static champion_t *find_champ(list_t *list, process_t *process)
{
    for (list_t *l = list; l != NULL; l = l->next) {
        if (l->id == process->champ_nb)
            return (l->data);
    }
    return (NULL);
}

void op_fork(process_t *process, vm_t *vm)
{
    champion_t *curr = find_champ(vm->champ, process);
    process_t *new = NULL;
    list_t *temp = NULL;

    if (curr == NULL)
        return;
    new = init_process(curr->prog_number, process->pc +
    process->instruction->params[0], curr->prog_number);
    temp = list_append(curr->process, new, "fork");
    temp->next = curr->process;
    curr->process = temp;
    load_prog_to_mem(curr->program, vm->mem, curr->load_adress,
    curr->prog_size);
}

void op_lfork(process_t *process, vm_t *vm)
{
    champion_t *curr = find_champ(vm->champ, process);
    process_t *new = NULL;
    list_t *temp = NULL;

    if (curr == NULL)
        return;
    new = init_process(curr->prog_number, process->pc +
    process->instruction->params[0], curr->prog_number);
    temp = list_append(curr->process, new, "fork");
    temp->next = curr->process;
    curr->process = temp;
    load_prog_to_mem(curr->program, vm->mem, curr->load_adress,
    curr->prog_size);
}