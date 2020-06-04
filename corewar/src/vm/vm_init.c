/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_init
*/

#include <stdlib.h>
#include "vm.h"
#include "console.h"

vm_t *vm_init(int ac, char **argv)
{
    vm_t *vm = malloc(sizeof(champion_t));
    unsigned char *memory = malloc(sizeof(char) * MEM_SIZE);

    error_handling(argv, ac, vm);
    if (!vm || !memory) {
        my_puterr("Memory allocation failed\n");
        exit(84);
    }
    for (int i = 0; i < MEM_SIZE; ++i)
        memory[i] = 0;
    vm->mem = memory;
    parsing(ac, argv, vm);
    load_binaries(vm->mem, vm->nb_champ, vm->champ);
    load_champions_to_mem(vm->champ, vm->mem);
    create_champ_processes(vm->champ);
    return (vm);
}