NAME = minishell

CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC = main.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HDR = minishell.h

LIBFT = libft/libft.a
LIBLPC = liblpc/liblpc.so

.PHONY = all create_objdir clean fclean re

all: $(NAME)

$(NAME): create_objdir $(LIBFT) $(LIBLPC) $(HDR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBLPC) -o $(NAME)

obj/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft bonus

$(LIBLPC):
	@make -C liblpc

clean:
	@rm -rf obj/

fclean:
	@rm -rf obj/ $(NAME) $(LIBFT)
	@make -C libft fclean
	@make -C liblpc fclean

re: fclean all

create_objdir:
	@mkdir -p obj/
