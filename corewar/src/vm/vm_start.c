/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_update
*/

#include "vm.h"
#include <stdlib.h>

static int check_alive(vm_t *vm)
{
    champion_t *champ = NULL;
    list_t *temp = vm->champ;
    int nb_alive = 0;

    while (temp) {
        champ = temp->data;
        if (champ->live == 1)
            nb_alive++;
    }
    return (nb_alive);
}

int vm_start(vm_t *vm)
{
    int nb_alive = vm->nb_champ;

    while (nb_alive) {
        nb_alive = check_alive(vm);
        update(vm);
    }
    return 0;
}