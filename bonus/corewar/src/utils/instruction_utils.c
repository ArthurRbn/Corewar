/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** manage instruction structure
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"
#include "console.h"

instruction_t *init_instruction(void)
{
    instruction_t *new = malloc(sizeof(instruction_t));

    if (!new) {
        my_puterr("Memory allocation failed\n");
        exit(84);
    }
    new->instruction_code = 0;
    new->arg_types = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; ++i)
        new->arg_types[i] = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        new->params[i] = 0;
    return (new);
}

void reset_instruction(instruction_t *instruction)
{
    for (int i = 0; i < 4; ++i)
        instruction->arg_types[i] = 0;
    instruction->instruction_code = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        instruction->params[i] = 0;
}

void destroy_instruction(instruction_t *instruction)
{
    if (instruction != NULL)
        free(instruction);
}