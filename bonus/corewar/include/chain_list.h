/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** chain_list
*/

#pragma once

typedef struct list_s
{
    struct list_s *next;
    char *name;
    void *data;
    int id;
} list_t;

list_t *create_list(void *data, char *name);
list_t *list_append(list_t *list, void *data, char *name);
void list_remove(list_t **list, int id);
int list_find(list_t *list, char *name);
void free_list(list_t *list);