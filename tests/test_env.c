#include <stdio.h>
#include <unistd.h>
#include "env_util.h"

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

void	init_add_remove_deinit()
{
	// printenv();
	
	printf("env add = %s\n",
		env_add("NEWVAR=newvalue")
	[((char *[]){"Success", "Failure"})]);

	// printenv();
	
	printf("env rmv = %s\n",
		env_remove("XDG_SEAT")
	[((char *[]){"Success", "Failure"})]);
	
	// printenv();
	
	// printf("env deinit = %s\n",
	// 	env_deinit()
	// [((char *[]){"Success", "Failure"})]);
	// 
	// printenv();
}

#include "builtin.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	env[0] = ft_strdup("VAR1=val1");
	env[1] = ft_strdup("VAR2=val2");
	env[2] = ft_strdup("HOME=/home/hohhoh");
	env[3] = ft_strdup("PWD=/home/hohhoh/Desktop/minishell");
	env[4] = ft_strdup("OLDPWD=/home/hohhoh/Desktop");
	env[5] = ft_strdup("VAR3=val3");
	env[6] = ft_strdup("VAR4val4");
	env[7] = ft_strdup("VAR5=val5");
	env[8] = ft_strdup("VAR6=val6");
	env[9] = ft_strdup("VAR7=val7");
	env[10] = 0;
	env_init(env);
	for (int i = 0; i < 10; ++i) free(env[i]);
	ft_env();
	printf("\n\n##############\n\n");
	ft_cd("/home");
	ft_env();
	printf("\n\n##############\n\n");
	ft_pwd();
	env_deinit();
}
