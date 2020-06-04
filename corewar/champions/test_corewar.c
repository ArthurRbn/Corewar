char *mem = malloc(sizeof(char) * MEM_SIZE);
    process_t *proc = init_process(3);

    if (!mem)
        exit(84);
    for (int i = 0; i < MEM_SIZE; ++i)
        mem[i] = 0;
    mem[0] = 0b00000001;
    mem[1] = 0b00000000;
    mem[2] = 0b00000000;
    mem[3] = 0b00000000;
    mem[4] = 0b00000010;
    mem[5] = 0b00010000;
    mem[6] = 0b01000000;
    mem[7] = 0b00000001;
    get_next_instruction(proc, mem);
    printf("proc pc = %d, cycles = %d, code = %d\n", proc->pc, proc->cycles, proc->instruction->instruction_code);
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        printf("instruction param = %d\n", proc->instruction->params[i]);
    get_next_instruction(proc, mem);
    printf("proc pc = %d, cycles = %d, code = %d\n", proc->pc, proc->cycles, proc->instruction->instruction_code);
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        printf("instruction param = %d\n", proc->instruction->params[i]);
