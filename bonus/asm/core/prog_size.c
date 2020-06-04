/*
** EPITECH PROJECT, 2020
** asm
** File description:
** prog_size
*/

#include "prog_size.h"
#include "string_utils.h"
#include <stdlib.h>

static int get_coding_bytes_size(token_t *token)
{
    char *ignored[] = {"live", "zjmp", "fork", "lfork", NULL};
    int param_count = 0;

    for (int i = 0; ignored[i]; i++)
        if (my_streq(ignored[i], token->op))
            return (0);
    for (; token->params[param_count]; param_count++);
    return ((param_count / 4) + (param_count % 4 == 0 ? 0 : 1));
}

static int get_params_size(token_t *token)
{
    int size = 0;

    for (int i = 0; token->params[i]; i++) {
        if (token->params[i]->type & T_IND)
            size += 2;
        if (token->params[i]->type & T_REG)
            size += 1;
        if (token->params[i]->type & T_DIR)
            size += 4;
    }
    return (size);
}

static int get_token_size(token_t *token)
{
    int size = 1;

    if (token->op == NULL)
        return (0);
    size += get_coding_bytes_size(token);
    size += get_params_size(token);
    return (size);
}

int get_prog_size(token_t **tokens, char const *end_label)
{
    int size = 0;

    for (int i = 0; tokens[i]; i++) {
        if (end_label != NULL && my_streq(end_label, tokens[i]->label))
            return (size);
        size += get_token_size(tokens[i]);
    }
    return (size);
}
