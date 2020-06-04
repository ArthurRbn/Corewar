/*
** EPITECH PROJECT, 2020
** asm
** File description:
** param_tokenizer
*/

#include "compiler.h"
#include "string_utils.h"
#include "string_convert.h"
#include "tokenizer.h"
#include "console.h"
#include <stdlib.h>

static int reg(param_t *param, char *str)
{
    param->type = T_REG;
    param->val.ui = stoi(str + 1);
    if (my_strissub(str + 1, "0123456789") == 0 ||
    param->val.ui < 1 || param->val.ui > 16) {
        my_puterr("Error: ");
        my_puterr(str);
        my_puterr(" is not a valid register.\n");
        return (1);
    }
    return (0);
}

static int direct(param_t *param, char *str)
{
    param->type = T_DIR;
    if (str[1] == LABEL_CHAR) {
        param->type = T_DIR | T_LAB;
        param->val.str = my_strdup(str + 2);
        return (0);
    }
    param->val.ui = stoi(str + 1);
    if (my_strissub(str + 1, "0123456789") == 0) {
        my_puterr("Error: ");
        my_puterr(str);
        my_puterr(" is not a valid direct value.\n");
        return (1);
    }
    return (0);
}

static int indirect(param_t *param, char *str)
{
    param->type = T_IND;
    if (str[0] == LABEL_CHAR) {
        param->type = T_IND | T_LAB;
        param->val.str = my_strdup(str + 1);
    } else
        param->val.ui = stoi(str);
    if (my_strissub(str + 1, "0123456789") == 0) {
        my_puterr("Error: ");
        my_puterr(str);
        my_puterr(" is not a valid indirect value.\n");
        return (1);
    }
    return (0);
}

static int handle(param_t *param, char *str)
{
    switch (str[0]) {
    case REG_CHAR:
        return (reg(param, str));
    case DIRECT_CHAR:
        return (direct(param, str));
    default:
        return (indirect(param, str));
    }
}

param_t *tokenize_param(char *str, int *error)
{
    param_t *param = malloc(sizeof(param_t));

    if (param == NULL) {
        free(str);
        return (NULL);
    }
    if (str == NULL)
        return (NULL);
    param->type = 0;
    *error -= handle(param, str);
    free(str);
    return (param);
}
