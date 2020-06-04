/*
** EPITECH PROJECT, 2020
** asm
** File description:
** tokenizer
*/

#pragma once

#include "compiler.h"

typedef struct
{
    char *label;
    char *op;
    param_t **params;
} token_t;

void free_token(void *t);
token_t **tokenize(char **lines);
token_t *tokenize_line(char *line);
param_t *tokenize_param(char *str, int *error);
int validate_tokens(token_t **tokens);
int validate_labels(token_t **tokens);
int validate_parameters(token_t **tokens);
