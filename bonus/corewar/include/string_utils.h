/*
** EPITECH PROJECT, 2020
** asm
** File description:
** string_utils
*/

#pragma once

int my_strlen(char const *str);
int my_streq(char const *a, char const *b);
char *my_strdup(char const *str);
int is_whitespace(char val);
char *my_strtrim(char const *str);
void my_strendat(char *str, char val);
int my_strendswith(char const *str, char const *end);
int my_strstartswith(char const *str, char const *start);
int my_strissub(char const *str, char const *allowed);
char *my_revstr(char *str);
int arr_len(char **arr);