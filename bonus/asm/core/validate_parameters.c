/*
** EPITECH PROJECT, 2020
** asm
** File description:
** validate_parameters
*/

#include "tokenizer.h"
#include "output.h"
#include "console.h"
#include <stdlib.h>

static int validate_token_parameters(token_t *token)
{
    op_t *op = get_op(token->op);
    args_type_t type = 0;
    int error = 0;

    for (int i = 0; token->params[i]; i++) {
        type = token->params[i]->type & ~T_LAB;
        if ((op->types[i] & type) == 0)
            error++;
    }
    if (error != 0) {
        my_puterr("Error: invalid arguments for op '");
        my_puterr(op->mnemonique);
        my_puterr("'.\n");
    }
    return (error);
}

int validate_parameters(token_t **tokens)
{
    int error = 0;

    for (int i = 0; tokens[i]; i++)
        if (tokens[i]->op != NULL)
            error -= validate_token_parameters(tokens[i]);
    return (error);
}
