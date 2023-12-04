#include <stdlib.h>
#include "libft/libft.h"

int		pt_util_size_ptr_arr(void **arr);

void	pt_util_free_arr(void **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void __attribute__((malloc))
	**pt_util_copy_ptr_arr(void **arr)
{
	void	**ret;
	int		len;

	len = 0;
	while (arr[len])
		len++;
	ret = malloc((len + 1) * sizeof(void *));
	if (!ret)
		return (NULL);
	ret[len] = NULL;
	while (len--)
		ret[len] = arr[len];
	return (ret);
}

void __attribute__((malloc))
	**pt_util_realloc_ptr_arr(void **arr, int to_add)
{
	void	**ret;
	int		len;

	len = 0;
	while (arr[len])
		++len;
	ret = malloc((len + to_add + 1) * sizeof(void *));
	if (!ret)
		return (NULL);
	while (to_add)
	{
		ret[len + to_add] = NULL;
		--to_add;
	}
	while (len--)
		ret[len] = arr[len];
	free(arr);
	return (ret);
}

char __attribute__((malloc))
	**pt_util_deep_copy_str(const char **arr)
{
	char	**ret;
	int		i;

	if (!arr)
		return (NULL);
	ret = malloc((pt_util_size_ptr_arr((void **)arr) + 1) * sizeof(*ret));
	if (!ret)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		ret[i] = ft_strdup(arr[i]);
		if (!ret[i])
		{
			pt_util_free_arr((void **)arr);
			return (NULL);
		}
	}
	return (ret);
}

void	**arr_copy(void **arr)
		__attribute__((alias("pt_util_copy_ptr_arr")));
void	**arr_realloc(void **arr, int to_add)
		__attribute__((alias("pt_util_realloc_ptr_arr")));