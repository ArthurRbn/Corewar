/*
** EPITECH PROJECT, 2020
** asm
** File description:
** tokenizer
*/

#include "tokenizer.h"
#include "array_utils.h"
#include <stdlib.h>

void free_param(void *p)
{
    param_t *param = p;

    if ((param->type & T_LAB))
        free(param->val.str);
    free(param);
}

void free_token(void *t)
{
    token_t *token = t;

    if (token->label != NULL)
        free(token->label);
    if (token->op != NULL)
        free(token->op);
    custom_free_array((void **) token->params, free_param);
    free(token);
}

token_t **tokenize(char **lines)
{
    token_t **tokens = malloc(sizeof(token_t *) * 1024);
    int i = 0;

    if (tokens == NULL)
        return (NULL);
    for (int j = 2; lines[j]; j++)
        tokens[i++] = tokenize_line(lines[j]);
    tokens[i] = 0;
    for (int j = 0; j < i; j++)
        if (tokens[j] == 0) {
            custom_free_array((void **) tokens, free_token);
            return (NULL);
        }
    if (validate_tokens(tokens) != 0) {
        custom_free_array((void **) tokens, free_token);
        return (NULL);
    }
    return (tokens);
}
