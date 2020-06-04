/*
** EPITECH PROJECT, 2020
** asm
** File description:
** compiler
*/

#include "compiler.h"
#include "console.h"
#include "prog_size.h"
#include "string_utils.h"
#include "array_utils.h"
#include "bin_utils.h"
#include "tokenizer.h"
#include "output.h"
#include <fcntl.h>
#include <unistd.h>

op_t op_table[] = {
{"live", 0x01, 1, {T_DIR}},
{"ld", 0x2, 2, {T_DIR | T_IND, T_REG}},
{"st", 0x03, 2, {T_REG, T_IND | T_REG}},
{"add", 0x04, 3, {T_REG, T_REG, T_REG}},
{"sub", 0x05, 3, {T_REG, T_REG, T_REG}},
{"and", 0x06, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
{"or", 0x07, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
{"xor", 0x08, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
{"zjmp", 0x09, 1, {T_DIR}},
{"ldi", 0x0a, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
{"sti", 0x0b, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}},
{"fork", 0x0c, 1, {T_DIR}},
{"lld", 0x0d, 2, {T_DIR | T_IND, T_REG}},
{"lldi", 0x0e, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
{"lfork", 0x0f, 1, {T_DIR}},
{"aff", 0x10, 1, {T_REG}},
{0, 0, 0, {0}}
};

static char *handle_name(char *line)
{
    if (!my_strstartswith(line, NAME_CMD_STRING) ||
    !my_strendswith(line, "\"")) {
        my_puterr("Error line 1: not a well formated name.\n");
        return (NULL);
    }
    line += my_strlen(NAME_CMD_STRING);
    line[my_strlen(line) - 1] = 0;
    if (my_strlen(line) > NAME_LEN) {
        my_puterr("Error line 1: name is too long.\n");
        return (NULL);
    }
    if (my_strlen(line) == 0) {
        my_puterr("Error line 1: name is too short.\n");
        return (NULL);
    }
    return (line);
}

static char *handle_comment(char *line)
{
    if (!my_strstartswith(line, COMMENT_CMD_STRING) ||
    !my_strendswith(line, "\"")) {
        my_puterr("Error line 2: not a well formated comment.\n");
        return (NULL);
    }
    line += my_strlen(COMMENT_CMD_STRING);
    line[my_strlen(line) - 1] = 0;
    if (my_strlen(line) > COMMENT_LEN) {
        my_puterr("Error line 2: comment is too long.\n");
        return (NULL);
    }
    if (my_strlen(line) == 0) {
        my_puterr("Error line 2: comment is too short.\n");
        return (NULL);
    }
    return (line);
}

static void out_header(char const *name, char const *comment, token_t ** tokens,
int fd)
{
    header_t header = {};

    for (int i = 0; name[i] != 0; i++)
        header.name[i] = name[i];
    header.name[my_strlen(name)] = 0;
    for (int i = 0; comment[i] != 0; i++)
        header.comment[i] = comment[i];
    header.comment[my_strlen(comment)] = 0;
    header.magic = swap_endianness(MAGIC_NUMBER);
    header.prog_size = swap_endianness(get_prog_size(tokens, NULL));
    write(fd, &header, sizeof(header_t));
}

static int get_name_and_comment(char **src, char **name, char **com)
{
    if (array_len((void **)src) < 2) {
        my_puterr("Error: source file should contain name and comment.\n");
        return (-1);
    }
    *name = handle_name(src[0]);
    *com = handle_comment(src[1]);
    if (*name == NULL || *com == NULL)
        return (-1);
    return (0);
}

int compile(char **src, char const *output)
{
    int fd;
    char *name;
    char *comment;
    token_t **tokens;

    if (get_name_and_comment(src, &name, &comment) < 0)
        return (84);
    tokens = tokenize(src);
    if (tokens == NULL)
        return (84);
    fd = open(output, O_WRONLY | O_CREAT, 0664);
    if (fd < 0) {
        my_puterr("Error: could not open output file.");
        custom_free_array((void **) tokens, free_token);
        return (84);
    }
    out_header(name, comment, tokens, fd);
    out_code(tokens, fd);
    close(fd);
    custom_free_array((void **) tokens, free_token);
    return (0);
}
