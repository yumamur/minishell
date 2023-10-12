NAME = minishell

SRC = main.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HDR = minishell.h

LIBFT = libft.a

.PHONY = all create_objdir clean fclean re

all: $(NAME)

$(NAME): create_objdir $(LIBFT) $(HDR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -l$(LIBFT) -o $@

$(LIBFT):
	@make -C libft bonus
	@mv libft/$(LIBFT) .

clean:
	@rm -rf obj/

fclean:
	@rm -rf obj/ $(NAME) $(LIBFT)

re: fclean all

create_objdir:
	@mkdir -p obj/
