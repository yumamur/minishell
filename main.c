#include "minishell.h"

int	main(void)
{
	TERMINAL	minishell;
	printf("%s\n", minishell.type.term_names);
	SET_TTY(1, NULL);
}
