#include "pt_util.h"

void	***g_env(void);
char	*ft_strdup(char *str);

int	env_init(void **data)
{
	static int	initialized;

	if (!data || !*data || initialized)
		return (-1);
	*g_env() = arr_copy(data);
	if (!*g_env())
		return (-1);
	initialized = -1;
	return (0);
}

int	env_add(char *var)
{
	*g_env() = arr_realloc(*g_env(), 1);
	if (!*g_env())
		return (-1);
	var = ((*g_env())[arr_size(*g_env()) - 1] = ft_strdup(var));
	if (!var)
		return (-2);
	return (0);
}
