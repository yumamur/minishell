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

int	pt_util_discard_nth(void **arr, int n)
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

int	arr_size(void **arr)
	__attribute__((alias("pt_util_size_ptr_arr")));
int	arr_index(void **arr, void *to_find)
	__attribute__((alias("pt_util_find_index_if_in_arr")));
int	arr_discard_n(void **arr, int n)
	__attribute__((alias("pt_util_discard_nth")));
