/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** create_champ
*/

#include <stdlib.h>
#include "vm.h"
#include "console.h"

void create_champ_processes(list_t *champions)
{
    list_t *temp = champions;
    champion_t *champ = NULL;
    process_t *new_process = NULL;

    while (temp) {
        champ = temp->data;
        new_process = init_process(champ->prog_number, champ->load_adress,
        champ->prog_number);
        champ->process = create_list(new_process, NULL);
        if (!champ->process) {
            my_puterr("Process initialization failed\n");
            exit(84);
        }
        temp = temp->next;
    }
}

champion_t *create_champ(void)
{
    champion_t *champ = malloc(sizeof(champion_t));

    champ->load_adress = -1;
    champ->path = NULL;
    champ->prog_number = -1;
    champ->prog_size = -1;
    champ->program = NULL;
    champ->process = NULL;
    champ->live = WAITING_LIVE;
    return (champ);
}