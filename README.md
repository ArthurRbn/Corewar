# Corewar

Epitech year-end Project.

ASM part is a compiler which transforms champions asm langage to binary (.cor).

The virtual machine ('corewar' binary) takes between 2 and 4 .cor binaries (champions) and run them.
The champions execute instructions on the same memory block (6144 bytes).
Champions have to execute the live instruction at least one time per CYCLE_TO_DIE or they die.
The Winner is the last one to execute live instuctions.

# ASM

You can find some source code of asm here : ./asm/src

It'll transform those .s in .cor that can be interpreated by the machine.

You can create your own champ to make him fight against others champs.

# VM

The machine will run your champion and the others to make them fight each others.
Champions programs are loaded to memory at the beginning, after this instructions are fetched and executed for each program, each instruction needs a different number of cycles to be executed.

For more precisions have a look at the Corewar_subject.pdf

The bonus file is an unfinished visual interface coded using the ncurses library

Realised with:

FRECHARD Maxime

BIEHLER Axel

SAUNER Alexandre
