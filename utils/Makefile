NAME = utils.a

C = cc

FLAG = -Wall -Wextra -Werror

RM = rm -f

SRC =	printf.c print_numbers.c print_string.c print_hexa.c decrypt.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rsc $(NAME) $(OBJ)

%.o: %.c
	@$(C) $(FLAG) -c $< -o $@

clean:
	@$(RM)  $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : clean all

.PHONY: all, clean, fclean, re
