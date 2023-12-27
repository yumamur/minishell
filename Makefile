NAME = minishell

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
SANITIZER	=	-fsanitize=address

SRC_BUILTIN	=	builtin_cd.c \
				builtin_echo.c \
				builtin_env.c \
				builtin_export.c \
				builtin_pwd.c \
				builtin_unset.c

SRC_UTIL	=	env_util.c \
				env_util_core.c \
				error_handler.c \
				getenv.c \
				prompt.c \
				pt_util.c \
				pt_util_alloc.c

SRC_EXEC	=	execute.c \
				execute_set.c \
				execute_util.c

SRC_PARSE	=	lexer.c \
				parse.c \
				parse_validate.c \
				parse_separate.c \
				str_wordtab.c \
				str_wordtab_util.c

SRC_SIGNAL	=	signal.c

LPC			=	lpc_export.c \
				lpc_flush.c \
				lpc_int_addr.c \
				lpc_int_constructor.c \
				lpc_int_destroyer.c \
				lpc_int_errmsg.c \
				lpc_int_load.c \
				lpc_int_storage.c


SRCS		=	main.c \
				constructor.c \
				destructor.c \
				$(SRC_BUILTIN) \
				$(SRC_SIGNAL) \
				$(SRC_EXEC) \
				$(SRC_PARSE) \
				$(SRC_UTIL) \
				$(LPC)

OBJS	= $(patsubst %.c, obj/%.o, $(SRCS))

LIBFT		= .lib/libft.a
LIBREADLINE	= .lib/libreadline.a
LIBHISTORY	= .lib/libhistory.a

LIBS		= -lcurses $(LIBFT) $(LIBREADLINE) $(LIBHISTORY)

.PHONY = all create_objdir clean fclean re

all: $(NAME)

$(NAME): $(LIBREADLINE) $(LIBHISTORY) $(LIBFT) $(LIBLPC) $(HDR) $(OBJS)
	@printf "Building $(NAME)\n"
	@$(CC) $(CFLAGS) $(SANITIZER) $(OBJS) $(LINKS) $(LIBS) -o $(NAME) -g

obj/%.o: %.c | create_objdir 
	@$(CC) $(CFLAGS) $(SANITIZER) -c $< -o $@ -g

$(LIBFT):
	@printf "Building libft\n"
	@make -sC libft bonus clean
	@mv libft/libft.a .lib/

################################
#                              #
#           READLINE           #
#                              #
################################

FTP_READLINE = https://ftp.gnu.org/gnu/readline
TAR_READLINE = readline-8.2.tar.gz
DIR_READLINE = $(shell echo $(TAR_READLINE) | cut -d. -f1-2)

$(LIBREADLINE) $(LIBHISTORY):
	@mkdir -p .lib
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

re: fclean all

create_objdir:
	@mkdir -p obj/
