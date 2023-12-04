#include <stdio.h>
#include <unistd.h>
#include "msh_env.h"

char	*ft_strdup(char *str);

void	printenv(void)
{
	char	**tmp;

	tmp = (char **)*g_env();
	if (!tmp)
		return ;
	printf("\n########\n");
	while (*tmp)
		printf("%s\n", *tmp++);
	printf("########\n\n");
}

void	init_add_remove_deinit(void)
{
	char	*arr[4];

	arr[0] = ft_strdup("VAR1=value");
	arr[1] = ft_strdup("VAR2=value");
	arr[2] = ft_strdup("VAR3=value");
	arr[3] = 0;
	printf("env_init = %s\n",
		env_init((void **)arr)
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
