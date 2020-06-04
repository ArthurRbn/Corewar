/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** operations in memory
*/

#include "op.h"
#include "vm.h"

void load_prog_to_mem(unsigned char *program, unsigned char *mem, int adress,
int prog_size)
{
    if (adress < 0)
        adress *= -1;
    for (int i = 0; i < prog_size; ++i)
        mem[(adress + i) % MEM_SIZE] = program[i];
}

int mem_to_int(unsigned char *mem, int adress, int read_size)
{
    int arg = 0;
    int bitshift_val = 8 * (read_size - 1);

    if (adress < 0)
        adress *= -1;
    for (int i = 0; i < read_size; ++i) {
        arg += mem[adress++ % MEM_SIZE] << bitshift_val;
        bitshift_val -= 8;
    }
    return (arg);
}

void int_to_mem(unsigned char *mem, int adress, int value)
{
    int bitshift_val = 24;

    if (adress < 0)
        adress *= -1;
    for (int i = 0; i < 4; ++i) {
        mem[adress++ % MEM_SIZE] = value >> bitshift_val & 0xFF;
        bitshift_val -= 8;
    }
}