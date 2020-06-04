/*
** EPITECH PROJECT, 2020
** asm
** File description:
** line_tokenizer
*/

#include "tokenizer.h"
#include "string_utils.h"
#include "compiler.h"
#include <stdlib.h>

static int handle_label(token_t *token, char *line)
{
    char *tmp = my_strdup(line);

    token->label = NULL;
    if (tmp == NULL)
        return (-1);
    for (int i = 0; tmp[i]; i++)
        if (is_whitespace(tmp[i])) {
            tmp[i] = 0;
            break;
        }
    if (tmp[my_strlen(tmp) - 1] != LABEL_CHAR) {
        free(tmp);
        return (0);
    }
    tmp[my_strlen(tmp) - 1] = 0;
    token->label = tmp;
    return (my_strlen(tmp) + 1);
}

static int handle_op(token_t *token, char *line)
{
    char *op = malloc(my_strlen(line) + 1);
    int i = 0;

    if (op == NULL)
        return (-1);
    while (line[i] && !is_whitespace(line[i])) {
        op[i] = line[i];
        i++;
    }
    op[i] = 0;
    token->op = op;
    return (my_strlen(op));
}

static int handle_params(token_t *token, char *line, int *error)
{
    char new[128];
    int new_i = 0;
    int params_i = 0;

    token->params = malloc(sizeof(param_t *) * 64);
    if (token->params == NULL)
        return (-1);
    for (int i = 0; line[i]; i++) {
        if (line[i] == SEPARATOR_CHAR) {
            new[new_i] = 0;
            new_i = 0;
            token->params[params_i++] = tokenize_param(my_strtrim(new), error);
            i++;
        }
        new[new_i++] = line[i];
    }
    new[new_i] = 0;
    token->params[params_i] = tokenize_param(my_strtrim(new), error);
    token->params[params_i + 1] = 0;
    return (0);
}

static int fill_token(token_t *token, char *line, int *error)
{
    int start = 0;
    int op_len = 0;

    start = handle_label(token, line);
    if (start < 0)
        return (-1);
    while (line[start] && is_whitespace(line[start]))
        start++;
    if (my_strlen(line + start) == 0)
        return (0);
    op_len = handle_op(token, line + start);
    if (op_len == -1)
        return (-1);
    start += op_len;
    while (line[start] && is_whitespace(line[start]))
        start++;
    if (handle_params(token, line + start, error) < 0)
        return (-1);
    return (0);
}

token_t *tokenize_line(char *line)
{
    token_t *token = malloc(sizeof(token_t));
    int error = 0;

    if (token == NULL)
        return (NULL);
    token->label = NULL;
    token->op = NULL;
    token->params = NULL;
    if (fill_token(token, line, &error) < 0 || error != 0) {
        free_token(token);
        return (NULL);
    }
    return (token);
}
