/*
** EPITECH PROJECT, 2020
** asm
** File description:
** validate_labels
*/

#include "string_utils.h"
#include "tokenizer.h"
#include "console.h"
#include <stdlib.h>

static int validate_label_for_param(param_t *param, char **labels)
{
    if ((param->type & T_LAB) == 0)
        return (0);
    for (int i = 0; labels[i]; i++)
        if (my_streq(labels[i], param->val.str))
            return (0);
    my_puterr("Error: label '");
    my_puterr(param->val.str);
    my_puterr("' used but not defined.\n");
    return (1);
}

static int validate_labels_for_token(token_t *token, char **labels)
{
    int error = 0;

    for (int i = 0; token->params[i]; i++)
        error += validate_label_for_param(token->params[i], labels);
    return (error);
}

int validate_labels(token_t **tokens)
{
    char *labels[256];
    int labels_i = 0;
    int error = 0;

    for (int i = 0; tokens[i]; i++)
        if (tokens[i]->label != NULL)
            labels[labels_i++] = tokens[i]->label;
    labels[labels_i] = 0;
    for (int i = 0; tokens[i]; i++)
        if (tokens[i]->op != NULL)
            error += validate_labels_for_token(tokens[i], labels);
    return (error);
}
