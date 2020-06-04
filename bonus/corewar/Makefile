##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

CFLAGS 	=	-g -Iinclude -Wall
LDFLAGS	+= -lncurses

EXEC 	=	corewar

SRC		=	src/main.c								\
			src/utils/console.c						\
			src/utils/string_utils.c				\
			src/utils/string_utils1.c				\
			src/utils/string_utils2.c				\
			src/utils/chain_list.c					\
			src/utils/string_convert.c				\
			src/utils/str_test.c					\
			src/utils/create_champ.c				\
			src/utils/instruction_utils.c			\
			src/utils/process_utils.c				\
			src/utils/my_put_nbr.c					\
			src/utils/my_putchar.c					\
			src/vm/parsing.c						\
			src/vm/update.c							\
			src/vm/error_handling.c					\
			src/vm/search_prog_number.c				\
			src/vm/search_load_adress.c				\
			src/vm/dump_memory.c					\
			src/vm/load_champions.c					\
			src/vm/execution_loop.c					\
			src/vm/vm_init.c						\
			src/vm/vm_start.c						\
			src/vm/ncurses.c						\
			src/vm/free_vm.c						\
			src/operations/aff.c					\
			src/operations/ld.c						\
			src/operations/ldi.c					\
			src/operations/lld.c					\
			src/operations/lldi.c					\
			src/operations/op_fork.c				\
			src/operations/operation.c				\
			src/operations/operation1.c				\
			src/operations/live.c					\
			src/operations/st.c						\
			src/operations/sti.c					\
			src/operations/zjmp.c					\
			src/disassembler/get_next_instruction.c	\
			src/disassembler/fetch_params.c			\
			src/disassembler/mem_operations.c		\
			src/operations/op.c

OBJ		=	$(SRC:.c=.o)

all:		$(EXEC)

$(EXEC):	$(OBJ)
	gcc -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(EXEC)

re:			fclean all

cdb:
	compiledb make re
