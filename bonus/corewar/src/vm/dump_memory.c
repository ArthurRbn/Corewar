/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** functions to dump memory each dump_cycle if defined as params
*/

#include "vm.h"
#include "console.h"
#include <stdio.h>

void dump_memory(unsigned char *mem)
{
    char *hexa = "0123456789ABCDEF";
    char byte[3] = {0, 0, 0};

    for (int i = 0; i < MEM_SIZE; ++i) {
        if (i % 32 == 0)
            my_putstr("\n");
        byte[0] = hexa[(mem[i] >> 4)];
        byte[1] = hexa[(mem[i] & 0xF)];
        my_putstr(byte);
        if ((i + 1) % 32 != 0)
            my_putstr(" ");
    }
    my_putstr("\n");
}