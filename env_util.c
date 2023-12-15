#include "libft/libft.h"
#include "pt_util.h"

const char	*ft_getenv(const char *name);
void 		***g_env(void);

// int	is_sorted(void)
// {
// 	short	**ptr;

// 	ptr = (short **)*g_env();
// 	while (*ptr)
// 	{
// 	}
// 	return (0);
// }

// static void	env_sort(void)
// {
// 	char	**ptr;

// 	while (is_sorted())
// 	{

// 	}
// }

int	env_init(void **data)
{
	static int	initialized;

	if (!data || !*data || initialized)
		return (-1);
	*g_env() = arr_deep_copy(data);
	if (!*g_env())
		return (-1);
	initialized = -1;
	return (0);
}

int	env_add(const char *var)
{
	char	**tmp;
	char	*var_dup;

	tmp = (char **)arr_realloc(*g_env(), 1);
	if (!tmp)
		return (-1);
	*g_env() = (void **)tmp;
	var_dup = ft_strdup(var);
	if (!var_dup)
		return (-1);
	(*g_env())[arr_size(*g_env()) - 1] = var_dup;
	return (0);
}

int	env_remove(char *to_remove)
{
	char	*var;

	var = (void *)ft_getenv(to_remove);
	if (!var)
		return (-1);
	var -= ft_strlen(to_remove) + 1;
	free(var);
	arr_discard_n(*g_env(), arr_index(*g_env(), var));
	return (0);
}
