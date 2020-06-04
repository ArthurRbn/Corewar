/*
** EPITECH PROJECT, 2020
** asm
** File description:
** output
*/

#include "output.h"
#include "compiler.h"
#include "string_utils.h"
#include <stdlib.h>
#include <unistd.h>

op_t *get_op(char *str)
{
    for (int i = 0; op_table[i].mnemonique; i++)
        if (my_streq(op_table[i].mnemonique, str))
            return (&(op_table[i]));
    return (NULL);
}

static void write_coding_byte(int fd, unsigned char *val, int *current_bit)
{
    if (*current_bit == 0)
        return;
    write(fd, val, 1);
    *val = 0;
    *current_bit = 0;
}

static void write_coding_bytes(token_t *token, int fd)
{
    unsigned char val = 0;
    int current_bit = 0;

    for (int i = 0; token->params[i]; i++) {
        if (token->params[i]->type & T_REG) {
            current_bit++;
            val |= 1 << (7 - current_bit);
            current_bit++;
        } else if (token->params[i]->type & T_DIR) {
            val |= 1 << (7 - current_bit);
            current_bit += 2;
        } else {
            val |= 1 << (7 - current_bit);
            val |= 1 << (7 - (current_bit + 1));
            current_bit += 2;
        }
        if (current_bit == 8)
            write_coding_byte(fd, &val, &current_bit);
    }
    write_coding_byte(fd, &val, &current_bit);
}

static void check_write_coding_bytes(token_t *token, int fd)
{
    char *ignored[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; ignored[i]; i++)
        if (my_streq(token->op, ignored[i]))
                return;
    write_coding_bytes(token, fd);
}

void out_code(token_t **tokens, int fd)
{
    op_t *op;

    for (int i = 0; tokens[i]; i++) {
        if (tokens[i]->op == NULL)
            continue;
        op = get_op(tokens[i]->op);
        write(fd, &(op->code), 1);
        check_write_coding_bytes(tokens[i], fd);
        out_params(tokens[i], tokens, fd);
    }
}
