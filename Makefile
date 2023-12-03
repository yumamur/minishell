NAME = minishell

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
SANITIZER	=	-fsanitize=address

SRC_EXEC	=	exec.c \
				exec_utils.c

SRC_PARSE	=	lexer.c

SRC_SIGNAL	=	signal.c

SRCS	= main.c getenv.c $(SRC_SIGNAL) $(SRC_EXEC) $(SRC_PARSE)

OBJS	= $(patsubst %.c, obj/%.o, $(SRCS))

LIBFT		= libft/libft.a
LIBLPC		= liblpc/liblpc.so
LIBREADLINE	= libreadline.a
LIBHISTORY	= libhistory.a

LIBS		= -lcurses $(LIBFT) $(LIBLPC) $(LIBREADLINE) $(LIBHISTORY)

.PHONY = all create_objdir clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBLPC) $(LIBREADLINE) $(HDR) $(OBJS)
	@$(CC) $(CFLAGS) $(SANITIZER) $(OBJS) $(LINKS) $(LIBS) -o $(NAME)

obj/%.o: %.c | create_objdir 
	@$(CC) $(CFLAGS) $(SANITIZER) -c $< -o $@

$(LIBFT):
	@printf "Building libft\n"
	@make -sC libft bonus

$(LIBLPC):
	@printf "Building liblpc\n"
	@make -sC liblpc

################################
#                              #
#           READLINE           #
#                              #
################################

FTP_READLINE = https://ftp.gnu.org/gnu/readline
TAR_READLINE = readline-8.2.tar.gz
DIR_READLINE = $(basename $(TAR_READLINE))

$(LIBREADLINE) $(LIBHISTORY):
	@printf "Downloading $(TAR_READLINE)\n"
	@curl -sO $(FTP_READLINE)/$(TAR_READLINE)
	@printf "Extracting $(TAR_READLINE)\n"
	@tar -xvzf $(TAR_READLINE) 1>/dev/null
	@rm -f $(TAR_READLINE)
	@printf "Configuring readline build\n"
	@sh -c "cd $(DIR_READLINE) && ./configure --prefix=\"$(PWD)/tmp\" 1>/dev/null"
	@printf "Building readline\n"
	@make -sC $(DIR_READLINE) install 1>/dev/null 2>/dev/null
	@rm -rf $(DIR_READLINE)
	@mv tmp/lib/libreadline.a $(LIBREADLINE)
	@mv tmp/lib/libhistory.a $(LIBHISTORY)
	@rm -rf tmp

clean:
	@rm -rf obj/
	@make -sC libft clean

fclean:
	@rm -rf obj/ $(NAME) $(LIBFT)
	@make -sC libft fclean
	@make -sC liblpc fclean

re: fclean all

create_objdir:
	@mkdir -p obj/
