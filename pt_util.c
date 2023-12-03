#include <stdlib.h>

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

int	pt_util_size_ptr_arr(void **arr)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i])
		++i;
	return (i);
}

int	pt_util_find_index_if_in_arr(void **arr, void *to_find)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i] != to_find)
		++i;
	return (i);
}

int	pt_util_remove_nth(void **arr, int n)
{
	int	size;

	size = pt_util_size_ptr_arr(arr);
	if (size == -1 || n < 0)
		return (-1);
	while (n < size)
	{
		arr[n] = arr[n + 1];
		++n;
	}
	return (0);
}

void	**arr_copy(void **arr)
	__attribute__((alias("pt_util_copy_ptr_arr")));
void	**arr_realloc(void **arr, int to_add)
	__attribute__((alias("pt_util_realloc_ptr_arr")));
int		arr_size(void **arr)
	__attribute__((alias("pt_util_size_ptr_arr")));
int		arr_index(void **arr, void *to_find)
	__attribute__((alias("pt_util_find_index_if_in_arr")));
int		arr_remove(void **arr, int n)
	__attribute__((alias("pt_util_remove_nth")));
