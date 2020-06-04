/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** manage process structure
*/

#include <stdlib.h>
#include "vm.h"
#include "op.h"

process_t *init_process(int pid, int pc, int champ_nb)
{
    process_t *new = malloc(sizeof(process_t));

    if (!new)
        exit(84);
    new->carry = 0;
    new->cycles = 0;
    new->instruction = init_instruction();
    new->live = 0;
    new->pc = pc;
    new->champ_nb = champ_nb;
    new->reg = malloc(sizeof(int) * REG_NUMBER);
    if (!new->reg)
        exit(84);
    for (int i = 0; i < REG_NUMBER; ++i)
        new->reg[i] = 0;
    new->reg[0] = pid;
    return (new);
}

void destroy_process(process_t *process)
{
    if (!process)
        return;
    if (process->reg != NULL)
        free(process->reg);
    destroy_instruction(process->instruction);
    free(process);
}