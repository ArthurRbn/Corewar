/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** update champ
*/

#include "op.h"
#include "vm.h"
#include "chain_list.h"
#include <stdlib.h>

static void exec_instruct(process_t *process, vm_t *vm)
{
    void (*instruct[])(process_t *, vm_t *) = {op_live, op_ld, op_st, op_add, op_sub, op_and, op_or, op_xor, op_zjmp, op_ldi, op_sti, op_fork, op_lld, op_lldi, op_lfork, op_aff};

    for (int i = 0; i <= 16; i++) {
        if (i + 1 == process->instruction->instruction_code)
            instruct[i](process, vm);
    }
}

static void update_process(process_t *process, vm_t *vm)
{
    if (process->cycles == 0) {
        exec_instruct(process, vm);
        get_next_instruction(process, vm->mem);
    } else
        process->cycles -= 1;
}

void update(vm_t *vm)
{
    champion_t *champ_temp = NULL;

    for (list_t *champ = vm->champ; champ != NULL; champ = champ->next) {
        champ_temp = champ->data;
        for (list_t *process = champ_temp->process; process != NULL; process = process->next)
            update_process(process->data, vm);
    }
}
