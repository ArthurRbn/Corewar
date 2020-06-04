/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** load champions binaries
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "console.h"
#include "chain_list.h"
#include "string_utils.h"
#include "vm.h"

void load_champions_to_mem(list_t *champions, vm_t *vm)
{
    list_t *temp = champions;
    champion_t *handler = NULL;

    while (temp) {
        handler = temp->data;
        load_prog_to_mem(handler, vm, handler->load_adress);
        temp = temp->next;
    }
}

void set_default_load_adresses(list_t *champions, int nb_champions)
{
    list_t *temp = champions;
    champion_t *handler = NULL;
    int offset = MEM_SIZE / nb_champions;
    int i = 0;

    while (temp) {
        handler = temp->data;
        handler->load_adress = offset * i;
        ++i;
        temp = temp->next;
    }
}

static void fetch_header(champion_t *champ, int *fd, int *prog_size)
{
    *fd = open(champ->path, O_RDONLY);
    unsigned char *buff = malloc(sizeof(unsigned char *) * sizeof(header_t));
    char *name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));

    if (*fd == -1 || !buff || !name) {
        my_puterr("Something wrong happened while reading champion file\n");
        put_usage();
        exit(84);
    }
    if (read(*fd, buff, sizeof(header_t)) != sizeof(header_t) ||
    mem_to_int(buff, 0, 4) != COREWAR_EXEC_MAGIC) {
        my_puterr("Invalid magic number\n");
        exit(84);
    }
    champ->prog_size = mem_to_int(buff, 136, 4);
    free(champ->path);
    champ->path = name;
    for (int i = 0; i < PROG_NAME_LENGTH; ++i)
        champ->path[i] = buff[i + 4];
    champ->path[PROG_NAME_LENGTH] = 0;
}

static void fetch_program(champion_t *champ, int *fd)
{
    champ->program = malloc(sizeof(unsigned char) * champ->prog_size);
    char check_empty = 0;

    if (!champ->program) {
        my_puterr("Something wrong happened while reading champion file\n");
        exit(84);
    }
    for (int i = 0; i < champ->prog_size; ++i)
        champ->program[i] = 0;
    if (read(*fd, champ->program, champ->prog_size) != champ->prog_size) {
        my_puterr("Invalid program size\n");
        exit(84);
    }
    if (read(*fd, &check_empty, 1) != 0) {
        my_puterr("Invalid champion file, longer program than declared\n");
        exit(84);
    }
    close(*fd);
}

void load_binaries(unsigned char *mem, int nb_champ, list_t *champions)
{
    list_t *temp = champions;
    champion_t *champ_temp = NULL;
    int fd = 0;
    int prog_size = 0;

    while (temp) {
        champ_temp = temp->data;
        if (!champ_temp->path) {
            my_puterr("Missing champion filepath\n");
            put_usage();
            exit(84);
        }
        fetch_header(champ_temp, &fd, &prog_size);
        fetch_program(champ_temp, &fd);
        temp = temp->next;
    }
}