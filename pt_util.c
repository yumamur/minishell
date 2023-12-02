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
		len++;
	ret = malloc((len + to_add + 1) * sizeof(void *));
	if (!ret)
		return (NULL);
	while (to_add)
		ret[len + to_add--] = NULL;
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

void	**arr_copy(void **arr)
	__attribute__((alias("pt_util_copy_ptr_arr")));
void	**arr_realloc(void **arr, int to_add)
	__attribute__((alias("pt_util_realloc_ptr_arr")));
int		arr_size(void **arr)
	__attribute__((alias("pt_util_size_ptr_arr")));
