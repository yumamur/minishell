#include <stdio.h>

char ***g_env(void);
int	env_init(char **env);
int	env_add(char *var);
char *ft_strdup(char *str);

int main()
{
	env_init((char *[]){ft_strdup("var1"), ft_strdup("var2"), ft_strdup("var3"), 0});
	printf("env add = %d\n", env_add("qweasd"));
	char **tmp = *g_env();
	while (*tmp)
		printf("%s\n", *tmp++);
}
