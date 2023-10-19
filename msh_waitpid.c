#include <sys/wait.h>

enum e_pstate
{
	RUNNING,
	WAITING,
	STOPPED,
	ZOMBIE
};

typedef struct s_child
{
	pid_t			pid;
	enum e_pstate	pstate;
	int				pestatus;
}	t_child;

int	exited_child(pid_t pid, int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus));
	return (0);
}

int	ter_waitpid(pid_t child)
{
	int		wstatus;
	pid_t	pid;

	pid = waitpid(child, &wstatus, WNOHANG);
	if (pid)
		exited_child(pid, wstatus);
	return (0);
}
