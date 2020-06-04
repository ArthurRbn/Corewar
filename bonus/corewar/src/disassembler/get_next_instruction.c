/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get binary arguments
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

static int *get_args_type(char bytecode, int *args_len)
{
    int default_config[MAX_ARGS_NUMBER] = {DIR_SIZE, 0, 0, 0};
    char bitshift_val = 6;
    char val = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        args_len[i] = default_config[i];
    if (bytecode == 0)
        return (args_len);
    for (int i = 0; bitshift_val > 0; ++i) {
        val = (bytecode >> bitshift_val);
        bitshift_val -= 2;
        if (val == 0x01)
            args_len[i] = 1;
        else if (val == 0x02)
            args_len[i] = DIR_SIZE;
        if (val == 0x03)
            args_len[i] = IND_SIZE;
    }
    return (args_len);
}

static int set_instruction_exec_time(process_t *proc, char code)
{
    proc->instruction->instruction_code = code;
    for (int i = 0; op_tab[i].code != 0; ++i) {
        if (code == op_tab[i].code) {
            proc->cycles = op_tab[i].nbr_cycles;
            return (0);
        }
    }
    proc->cycles = 1;
    proc->instruction->instruction_code = INVALID_INSTRUCTION;
    return (1);
}

void get_next_instruction(process_t *proc, unsigned char *mem)
{
    char code = mem[proc->pc++ % MEM_SIZE];
    int no_bytecode[4] = {1, 9, 15, 12};
    char bytecode = 0;
    int i = 0;

    proc->pc = proc->pc % MEM_SIZE;
    reset_instruction(proc->instruction);
    if (set_instruction_exec_time(proc, code) == 1)
        return;
    for (i = 0; i < 4; ++i)
        if (code == no_bytecode[i])
            break;
    if (i == 4)
        bytecode = mem[(proc->pc++) % MEM_SIZE];
    get_args_type(bytecode, proc->instruction->arg_types);
    fetch_instruction(proc->instruction->arg_types, proc, mem);
}
