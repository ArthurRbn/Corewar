/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** live
*/

#include "vm.h"
#include "string_convert.h"
#include "console.h"
#include <stdlib.h>

void op_live(process_t *process, vm_t *vm)
{
    int id = process->instruction->params[0];
    champion_t *tmp = NULL;

    for (list_t *l = vm->champ; l != NULL; l = l->next) {
        tmp = l->data;
        if (l->id == id && tmp->live != DEAD) {
            tmp->live = 1;
            my_putstr("Le joueur ");
            my_putstr(itos(id, 0));
            my_putstr(" est en vie\n");
        }
    }
    process->live = 1;
}
