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

static void err(champion_t *temp)
{
    my_puterr("champion load adress must have arithmetical type\n");
    exit(84);
}

static void search_adress(list_t *list, champion_t *temp, char *argv[], int i)
{
    int k = 0;
    int is_ok = 0;

    if (my_streq(argv[i], list->name)) {
        if (i >= 2 && my_streq(argv[i - 2], "-a")) {
            k = i - 1;
            is_ok = 1;
        } else if (i >= 4 && my_streq(argv[i - 4], "-a")) {
            k = i - 3;
            is_ok = 1;
        }
    }
    if (!is_ok)
        return;
    if (!is_number(argv[k]) && is_ok) {
        err(temp);
    } else {
        temp->load_adress = stoi(argv[k]) % MEM_SIZE;
    }
}

list_t *search_load_adress(list_t *list, char *argv[])
{
    champion_t *temp;

    for (list_t *l = list; l != NULL; l = l->next) {
        for (int i = 0; argv[i]; i++) {
            temp = l->data;
            search_adress(l, temp, argv, i);
        }
    }
    return (list);
}