int	arr_size(void **arr)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i])
		++i;
	return (i);
}

int	arr_index(void **arr, void *to_find)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (arr[i] != to_find)
		++i;
	return (i);
}

int	arr_discard_n(void **arr, int n)
{
	int	size;

	size = arr_size(arr);
	if (size == -1 || n < 0)
		return (-1);
	while (n < size)
	{
		arr[n] = arr[n + 1];
		++n;
	}
	return (0);
}
