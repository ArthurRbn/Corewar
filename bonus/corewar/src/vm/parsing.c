/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parsing
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "str_test.h"
#include "string_utils.h"
#include "string_convert.h"
#include "chain_list.h"
#include "console.h"

static list_t *create_list_champ(char **name)
{
    list_t *list = create_list(create_champ(), name[0]);
    champion_t *temp = NULL;

    for (int i = 1; name[i] != NULL; i++) {
        list = list_append(list, create_champ(), name[i]);
    }
    for (list_t *l = list; l != NULL; l = l->next) {
        temp = l->data;
        temp->path = my_strdup(l->name);
        temp->prog_number = l->id;
    }
    return (list);
}

static char **champ_name(char *argv[])
{
    char **prog_name = malloc(sizeof(char*) * 5);
    int nb = 0;

    prog_name[4] = NULL;
    for (int i = 1; argv[i] != NULL; i++) {
        if ((argv[i][0] != '-' && !my_streq(argv[i - 1], "-dump")) &&
        (!my_streq(argv[i - 1], "-a") && argv[i][0] != '-') &&
        (!my_streq(argv[i - 1], "-n") && argv[i][0] != '-')) {
            prog_name[nb] = argv[i];
            nb++;
        }
        prog_name[nb] = NULL;
    }
    return (prog_name);
}

static list_t *search_champ_info(char *argv[], vm_t *vm)
{
    char **name = champ_name(argv);
    list_t *list_champ = create_list_champ(name);

    vm->nb_champ = arr_len(name);
    list_champ = search_prog_number(list_champ, argv);
    free(name);
    return (list_champ);
}

static int search_dump_cycle(char *argv[])
{
    for (int i = 0; argv[i] != NULL; i++) {
        if (my_streq("-dump", argv[i])) {
            if (is_number(argv[i + 1]))
                return (stoi(argv[i + 1]));
            else {
                my_puterr("The dumb nbr_cyle must have arithmetical type\n");
                exit(84);
            }
        }
    }
    return (-1);
}

vm_t *parsing(int argc, char *argv[], vm_t *vm)
{
    list_t *list_champ = search_champ_info(argv, vm);

    vm->dump_cycle = search_dump_cycle(argv);
    set_default_load_adresses(list_champ, vm->nb_champ);
    list_champ = search_load_adress(list_champ, argv);
    vm->champ = list_champ;
    return (vm);
}