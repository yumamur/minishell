#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "msh_readline.h"
#include "msh_core.h"
#include "msh_structs.h"

void	heredoc_loop(char *str, int fd)
{
	char	*rl;

	while (1)
	{
		rl = readline("> ");
		if (!rl)
		{
			break ;
		}
		else if (!ft_strncmp(rl, str, ft_strlen(str) + 1))
			break ;
		ft_putstr_fd(rl, fd);
		ft_putstr_fd("\n", fd);
	}
}

int	heredoc(t_tokenized *tkn)
{
	int	fds[2];

	pipe(fds);
	heredoc_loop(tkn->str, fds[1]);
	close(fds[1]);
	return (fds[0]);
}

void	close_all_pipes(void)
{
	int	i;

	i = -1;
	while (++i < g_pipe()->size)
	{
		close(g_pipe()->arr_pipe[i].fds[0]);
		close(g_pipe()->arr_pipe[i].fds[1]);
	}
}
