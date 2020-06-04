/*
** EPITECH PROJECT, 2020
** asm
** File description:
** output_params
*/

#include "bin_utils.h"
#include "compiler.h"
#include "output.h"
#include "tokenizer.h"
#include "label.h"
#include <unistd.h>

static int get_val(param_t *param, token_t **tokens)
{
    unsigned int val = param->val.ui;

    if (param->type & T_LAB)
        return (get_label_address(tokens, param->val.str));
    return (val);
}

static void out_param(param_t *param, token_t **tokens, int fd)
{
    unsigned int val = get_val(param, tokens);
    unsigned int val_i = swap_endianness(val);
    unsigned short val_s = swap_endianness_short(val);
    unsigned char val_c = val;

    if (param->type & T_IND)
        write(fd, &val_s, 2);
    if (param->type & T_REG)
        write(fd, &val_c, 1);
    if (param->type & T_DIR)
        write(fd, &val_i, 4);
}

void out_params(token_t *token, token_t **tokens, int fd)
{
    for (int i = 0; token->params[i]; i++)
        out_param(token->params[i], tokens, fd);
}
