#include "libft/libft.h"
#include "typeft.h"
#include "pt_util.h"

t_c_char	*ft_getenv(t_c_char *envp[], t_c_char *name);
void 		***g_env(void);

int	is_sorted(void)
{
	short	**ptr;

	ptr = (short **)*g_env();
	while (*ptr)
	{
	}
	return (0);
}

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
	void	**tmp;
	char	*var_dup;

	tmp = arr_realloc(*g_env(), 1);
	if (!tmp)
		return (-1);
	*g_env() = tmp;
	var_dup = ft_strdup(var);
	if (!var_dup)
		return (-1);
	(*g_env())[arr_size(*g_env()) - 1] = var_dup;
	return (0);
}

int	env_remove(char *to_remove)
{
	void	**env;
	void	*var;

	env = *g_env();
	var = (void *)ft_getenv((t_c_char **)env, to_remove);
	if (!var)
		return (-1);
	var = ((char *)var) - ft_strlen(to_remove) - 1;
	arr_discard_n(env, arr_index(env, var));
	free((void *)var);
	return (0);
}
