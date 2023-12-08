#include <stdio.h>
#include <unistd.h>
#include "env_util.h"
#include "builtin.h"

int	printenv(void)
{
	char	**tmp;

	tmp = (char **)*g_env();
	if (!tmp)
		return (-1);
	while (*tmp)
		printf("%s\n", *tmp++);
	return (0);
}

void	init_add_remove_deinit(void)
{
	printf("env_init = %s\n",
		env_init((char *[]){"VAR1=val1", "_VAR2=v&a*l2", 0})
	[((char *[]){"Success", "Failure"})]);
	printenv();
	printf("env add = %s\n",
		env_add("NEWVAR=newvalue")
	[((char *[]){"Success", "Failure"})]);
	printenv();
	printf("env rmv = %s\n",
		env_remove("VAR1")
	[((char *[]){"Success", "Failure"})]);
	printenv();
	printf("env rmv = %s\n",
		env_deinit()
	[((char *[]){"Success", "Failure"})]);
	printenv();
}

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	env_init(env);
	ft_export((char *[]){"HOME=test", 0});
	printenv();
}
