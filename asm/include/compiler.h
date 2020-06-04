/*
** EPITECH PROJECT, 2020
** asm
** File description:
** compiler
*/

#pragma once

int compile(char **src, char const *output);

#define NAME_CMD_STRING ".name \""
#define NAME_LEN 128

#define COMMENT_CMD_STRING ".comment \""
#define COMMENT_LEN 2048

#define MAGIC_NUMBER 0xEA83F3

#define REG_CHAR 'r'
#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

typedef char args_type_t;

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

typedef struct
{
    args_type_t type;
    union
    {
        unsigned int ui;
        char *str;
    } val;
} param_t;

#define MAX_ARGS 4

typedef struct
{
    char *mnemonique;
    char code;
    int args_count;
    args_type_t types[MAX_ARGS];
} op_t;

extern op_t op_table[];

typedef struct
{
    int magic;
    char name[NAME_LEN + 1];
    int prog_size;
    char comment[COMMENT_LEN + 1];
} header_t;
