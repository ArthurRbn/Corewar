/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm
*/

#pragma once

#include "op.h"
#include "chain_list.h"

#define INVALID_INSTRUCTION 84
#define WAITING_LIVE 0
#define LIVE 1
#define DEAD 2

typedef struct vm_s
{
    int dump_cycle;
    int nb_champ;
    list_t *champ;
    unsigned char *mem;
} vm_t;

typedef struct champion_s
{
    char *path;
    unsigned char *program;
    int prog_size;
    int prog_number;
    int load_adress;
    int live;
    list_t *process;
} champion_t;

typedef struct instruction_s
{
    char instruction_code;
    int params[MAX_ARGS_NUMBER];
    int *arg_types;
} instruction_t;

typedef struct process_s
{
    int *reg;
    int pc;
    int carry;
    int live;
    int cycles;
    int champ_nb;
    instruction_t *instruction;
} process_t;

//error handling
void error_handling(char *argv[], int ac, vm_t *vm);
void put_usage(void);

//parsing
vm_t *parsing(int argc, char *argv[], vm_t *vm);
champion_t *create_champ(void);
list_t *search_prog_number(list_t *list, char *argv[]);
void set_default_load_adresses(list_t *champions, int nb_champions);
list_t *search_load_adress(list_t *list, char *argv[]);
void load_binaries(unsigned char *mem, int nb_champ, list_t *champions);
void load_champions_to_mem(list_t *champions, unsigned char *mem);
void load_prog_to_mem(unsigned char *program, unsigned char *mem, int adress,
int prog_size);
void create_champ_processes(list_t *champions);

//vm
vm_t *vm_init(int ac, char **argv);
int vm_start(vm_t *vm);
void update(vm_t *vm);
void execution_loop(vm_t *vm);
void free_mem(vm_t *vm);

//process
process_t *init_process(int pid, int pc, int champ_nb);
void destroy_process(process_t *process);

//instruction
instruction_t *init_instruction(void);
void reset_instruction(instruction_t *instruction);
void destroy_instruction(instruction_t *instruction);
void fetch_instruction(int *arg_len, process_t *proc, unsigned char *mem);
void get_next_instruction(process_t *proc, unsigned char *mem);

//mem_op
void load_prog_to_mem(unsigned char *program, unsigned char *mem, int adress,
int prog_size);
int mem_to_int(unsigned char *mem, int adress, int read_size);
void int_to_mem(unsigned char *mem, int adress, int value);
void dump_memory(unsigned char *mem);

//operations
void op_live(process_t *, vm_t *);
void op_ld(process_t *, vm_t *);
void op_st(process_t *, vm_t *);
void op_add(process_t *, vm_t *);
void op_sub(process_t *, vm_t *);
void op_and(process_t *, vm_t *);
void op_or(process_t *, vm_t *);
void op_xor(process_t *, vm_t *);
void op_zjmp(process_t *, vm_t *);
void op_ldi(process_t *, vm_t *);
void op_sti(process_t *, vm_t *);
void op_fork(process_t *, vm_t *);
void op_lld(process_t *, vm_t *);
void op_lldi(process_t *, vm_t *);
void op_lfork(process_t *, vm_t *);
void op_aff(process_t *, vm_t *);
