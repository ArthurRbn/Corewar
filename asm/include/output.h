/*
** EPITECH PROJECT, 2020
** asm
** File description:
** output
*/

#pragma once

#include "tokenizer.h"

op_t *get_op(char *str);
void out_params(token_t *token, token_t **tokens, int fd);
void out_code(token_t **tokens, int fd);
