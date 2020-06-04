/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** game/execution loop
*/

#include "op.h"
#include "vm.h"
#include "console.h"
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

static int champions_alive(vm_t *vm)
{
    list_t *list = vm->champ;
    champion_t *temp = NULL;
    int alive = 0;

    while (list) {
        temp = list->data;
        if (temp->live != DEAD)
            ++alive;
        list = list->next;
    }
    return (alive);
}

static void check_processes(list_t **list_process)
{
    list_t *temp = *list_process;
    list_t *prev = NULL;
    process_t *handler = temp->data;

    if (temp != NULL && handler->live == 0) {
        *list_process = temp->next;
        destroy_process(handler);
        free(temp);
        return;
    }
    while (temp != NULL && handler->live != 0) {
        prev = temp;
        temp = temp->next;
        if (temp != NULL)
            handler = temp->data;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    destroy_process(handler);
    free(temp);
}

static void kill_processes(vm_t *vm, int cycle, int *cycle_to_die)
{
    champion_t *handler = NULL;

    if (cycle == 0)
        return;
    else if (cycle % *cycle_to_die != 0)
        return;
    *cycle_to_die -= CYCLE_DELTA;
    for (list_t *champ = vm->champ; champ != NULL; champ = champ->next) {
        handler = champ->data;
        check_processes(&handler->process);
        if (handler->live != LIVE)
            handler->live = DEAD;
    }
}

static void print_winner(list_t *list)
{
    list_t *temp = list;
    champion_t *handler = NULL;

    while (temp) {
        handler = temp->data;
        if (handler->live == LIVE) {
            my_putstr("The player ");
            my_put_nbr(handler->prog_number);
            my_putstr("(");
            my_putstr(handler->path);
            my_putstr(")has won.\n");
            return;
        }
        temp = temp->next;
    }
    my_putstr("No one made a live, no winner\n");
}

void execution_loop(vm_t *vm)
{
    int cycle = 0;
    int cycles_to_die = CYCLE_TO_DIE;

    while (champions_alive(vm) > 1) {
        kill_processes(vm, cycle, &cycles_to_die);
        update(vm);
        if (vm->dump_cycle != -1 && cycle % vm->dump_cycle == 0)
            dump_memory(vm->mem);
        ++cycle;
        getch();
        print_colorized_mem(vm->color_mem, vm->mem);
        usleep(1000);
    }
    print_winner(vm->champ);
    free_mem(vm);
}