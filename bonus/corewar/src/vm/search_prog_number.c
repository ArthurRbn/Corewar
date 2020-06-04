/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** prepare_flag
*/

#include <stdlib.h>
#include "chain_list.h"
#include "string_utils.h"
#include "str_test.h"
#include "console.h"
#include "vm.h"
#include "string_convert.h"

void check_id(list_t *list)
{
    int check = 0;

    for (list_t *l = list; l != NULL; l = l->next) {
        for (list_t *k = list; k != NULL; k = k->next) {
            if (l->id == k->id)
                check++;
        }
        if (check > 1) {
            my_puterr("prog number must be different between champion\n");
            exit(84);
        }
        check = 0;
    }
}

static void err(champion_t *temp)
{
    free(temp);
    my_puterr("champion prog number must have arithmetical type\n");
    exit(84);
}

static void assign(list_t *list, int is_ok, int k, char *argv[])
{
    champion_t *temp = NULL;

    if (!is_number(argv[k]) && is_ok) {
        err(temp);
    } else {
        list->id = stoi(argv[k]);
        temp = list->data;
        temp->prog_number = stoi(argv[k]);
    }
}

static void search_id(list_t *list, char *argv[], int i)
{
    int k = 0;
    int is_ok = 0;

    if (my_streq(argv[i], list->name)) {
        if (i >= 2 && my_streq(argv[i - 2], "-n")) {
            k = i - 1;
            is_ok = 1;
        } else if (i >= 4 && my_streq(argv[i - 4], "-n")) {
            k = i - 3;
            is_ok = 1;
        }
    }
    if (!is_ok)
        return;
    assign(list, is_ok, k, argv);
}

list_t *search_prog_number(list_t *list, char *argv[])
{
    for (list_t *l = list; l != NULL; l = l->next) {
        for (int i = 0; argv[i]; i++) {
            search_id(l, argv, i);
        }
    }
    check_id(list);
    return (list);
}