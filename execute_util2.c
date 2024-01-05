#include <unistd.h>
#include "msh_core.h"
#include "msh_structs.h"

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
