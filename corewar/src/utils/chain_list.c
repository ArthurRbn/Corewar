/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** chai_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "chain_list.h"
#include "string_utils.h"

list_t *create_list(void *data, char *name)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return (NULL);
    list->id = 0;
    list->data = data;
    list->name = name;
    list->next = NULL;
    return (list);
}

list_t *list_append(list_t *list, void *data, char *name)
{
    list_t *new = malloc(sizeof(list_t));

    if (new == NULL)
        return (NULL);

    new->data = data;
    new->next = list;
    new->name = name;
    new->id = list->id + 1;
    return (new);
}

void list_remove(list_t **list, int id)
{
    list_t *prev = NULL;
    list_t *temp = *list;

    if (temp->id == id) {
        *list = temp->next;
        free(temp->data);
        free(temp);
        return;
    }
    for (list_t *l = *list; l != NULL; l = l->next) {
        if (l->id == id) {
            prev->next = l->next;
            temp = l;
            free(temp->data);
            free(temp);
            return;
        }
        prev = l;
    }
}

int list_find(list_t *list, char *name)
{
    list_t *new;

    for (list_t *l = list; l != NULL; l = l->next) {
        if (my_streq(name, l->name)) {
            new = l;
        }
    }
    return (new->id);
}

void free_list(list_t *list)
{
    list_t *temp;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp->data);
        free(temp);
    }
}