NAME = minishell

CC			= clang
CFLAGS		= -Wall -Werror -Wextra
SANITIZER	= -fsanitize=address

SRC = main.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HDR = minishell.h

READLINEBIN = readline/shlib

LIBFT		= libft/libft.a
LIBLPC		= liblpc/liblpc.so
LIBREADLINE	= readline/shlib/libreadline.so.8.2
LIBHISTORY	= readline/shlib/libhistory.so.8.2

LINKS		= -lcurses
LIBS		= $(LIBFT) $(LIBLPC) $(LIBREADLINE) $(LIBHISTORY)

.PHONY = all create_objdir clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBLPC) $(LIBREADLINE) $(HDR) $(OBJ)
	@$(CC) $(CFLAGS) $(SANITIZER) $(OBJ) $(LINKS) $(LIBS) -o $(NAME)

obj/%.o: %.c | create_objdir 
	@$(CC) $(CFLAGS) $(SANITIZER) -c $< -o $@

$(LIBFT):
	@make -C libft bonus

$(LIBLPC):
	@make -C liblpc

$(LIBREADLINE) $(LIBHISTORY):
	@make -C readline

clean:
	@rm -rf obj/

fclean:
	@rm -rf obj/ $(NAME) $(LIBFT)
	@make -C libft fclean
	@make -C liblpc fclean

re: fclean all

create_objdir:
	@mkdir -p obj/
