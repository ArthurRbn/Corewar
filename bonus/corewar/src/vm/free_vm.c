/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free memory
*/

#include <unistd.h>
#include <stdlib.h>
#include "chain_list.h"
#include "vm.h"

static void free_champ(champion_t *champ)
{
    list_t *prev;

    while (champ->process != NULL) {
        prev = champ->process;
        champ->process = champ->process->next;
        destroy_process(prev->data);
        free(prev);
    }
    free(champ->program);
    free(champ->path);
    free(champ);
}

void free_mem(vm_t *vm)
{
    list_t *prev;

    free(vm->mem);
    while (vm->champ != NULL) {
        prev = vm->champ;
        vm->champ = vm->champ->next;
        free_champ(prev->data);
        free(prev);
    }
    free(vm);
}