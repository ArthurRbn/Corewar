##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

CFLAGS 	=	-Iinclude -Wall
LDFLAGS	+=	

EXEC 	=	asm

SRC		=	main.c						\
			core/compiler.c				\
			core/tokenizer.c			\
			core/line_tokenizer.c		\
			core/param_tokenizer.c		\
			core/validate_tokens.c		\
			core/validate_labels.c		\
			core/validate_parameters.c	\
			core/output.c				\
			core/output_params.c		\
			core/file.c					\
			core/path.c					\
			core/prog_size.c			\
			core/label.c				\
			utils/string_utils.c		\
			utils/string_utils1.c		\
			utils/string_convert.c		\
			utils/array_utils.c			\
			utils/bin_utils.c			\
			utils/console.c

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
