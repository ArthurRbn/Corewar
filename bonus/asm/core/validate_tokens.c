/*
** EPITECH PROJECT, 2020
** asm
** File description:
** validate_tokens
*/

#include "tokenizer.h"
#include "string_utils.h"
#include "console.h"
#include "output.h"
#include <stdlib.h>

void validate_label(char const *label, int *error)
{
    if (label != NULL &&
    (my_strissub(label, LABEL_CHARS) == 0 || label[0] == 0)) {
        my_puterr("Error: label '");
        my_puterr(label);
        my_puterr("' is not valid.\n");
        (*error)++;
    }
}

static int validate_args_count(param_t **params, op_t *op, int *error)
{
    int args_count = 0;

    for (; params[args_count]; args_count++);
    if (args_count != op->args_count) {
        my_puterr("Error: parameters count for op '");
        my_puterr(op->mnemonique);
        my_puterr("' is not valid.\n");
        (*error)++;
        return (-1);
    }
    return (0);
}

int validate_token(token_t *token)
{
    int error = 0;
    op_t *op = get_op(token->op);

    validate_label(token->label, &error);
    if (token->op == NULL)
        return (error);
    if (op == NULL) {
        my_puterr("Error: op '");
        my_puterr(token->op);
        my_puterr("' is not valid.\n");
        error++;
        return (error);
    }
    if (validate_args_count(token->params, op, &error) < 0)
        return (error);
    return (error);
}

int validate_tokens(token_t **tokens)
{
    int error = 0;

    for (int i = 0; tokens[i]; i++)
        error -= validate_token(tokens[i]);
    error -= validate_labels(tokens);
    error -= validate_parameters(tokens);
    return (error);
}
