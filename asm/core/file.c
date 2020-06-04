/*
** EPITECH PROJECT, 2020
** asm
** File description:
** file
*/

#include "file.h"
#include "compiler.h"
#include "console.h"
#include "string_utils.h"
#include <stdlib.h>
#include <stdio.h>

static void handle_line(char *line, char **res, int *i)
{
    char *trim;

    my_strendat(line, COMMENT_CHAR);
    my_strendat(line, '\n');
    trim = my_strtrim(line);
    if (trim == NULL)
        return;
    if (my_strlen(trim) < 1) {
        free(trim);
        return;
    }
    res[*i] = trim;
    (*i)++;
}

char **read_file(char const *path)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    char **res;
    int i = 0;

    if (file == NULL)
        return (NULL);
    res = malloc(sizeof(char *) * 1024);
    if (res == NULL) {
        fclose(file);
        return (NULL);
    }
    while (getline(&line, &len, file) != -1)
        handle_line(line, res, &i);
    res[i] = NULL;
    if (line != NULL)
        free(line);
    fclose(file);
    return (res);
}
