#include <stdio.h>
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

int	main(void)
{
	char	*arr[4];

	arr[0] = ft_strdup("VAR1=value");
	arr[1] = ft_strdup("VAR2=value");
	arr[2] = ft_strdup("VAR3=value");
	arr[3] = 0;
	env_init((void **)arr);
	printenv();
	printf("env add = %s\n",
		((char *[]){"Success", "Fail"})[env_add("NEWVAR=newvalue")]);
	printenv();
	printf("env rmv = %s\n",
		((char *[]){"Success", "Fail"})[env_remove("VAR1")]);
	printenv();
	env_deinit();
	printenv();
}
