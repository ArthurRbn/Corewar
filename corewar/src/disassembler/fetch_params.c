/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fetch params in memory or registers
*/

#include "op.h"
#include "vm.h"

static int fetch_register(process_t *proc, unsigned char *mem)
{
    int reg_number = 0;

    reg_number = mem[proc->pc++ % MEM_SIZE];
    reg_number -= 1;
    return (reg_number);
}

static int fetch_indirect(process_t *proc, unsigned char *mem)
{
    int adress = 0;
    int bitshift_val = 8;

    for (int i = 0; i < IND_SIZE; ++i) {
        adress += mem[proc->pc++ % MEM_SIZE] << bitshift_val;
        bitshift_val -= 8;
    }
    return (adress);
}

static int fetch_direct(process_t *proc, unsigned char *mem)
{
    int arg = 0;
    int bitshift_val = 24;

    for (int i = 0; i < DIR_SIZE; ++i) {
        arg += mem[proc->pc++ % MEM_SIZE] << bitshift_val;
        bitshift_val -= 8;
    }
    return (arg);
}

void fetch_instruction(int *arg_len, process_t *proc, unsigned char *mem)
{
    for (int i = 0; arg_len[i] != 0 && i < MAX_ARGS_NUMBER; ++i) {
        if (arg_len[i] == 1)
            proc->instruction->params[i] = fetch_register(proc, mem);
        else if (arg_len[i] == DIR_SIZE)
            proc->instruction->params[i] = fetch_direct(proc, mem);
        if (arg_len[i] == IND_SIZE)
            proc->instruction->params[i] = fetch_indirect(proc, mem);
    }
}
