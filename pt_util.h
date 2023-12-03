#ifndef PT_UTIL_H
# define PT_UTIL_H

void	**arr_copy(void **arr);
void	**arr_realloc(void **arr, int to_add);
int		arr_size(void **arr);
int		arr_index(void **arr, void *to_find);
int		arr_remove(void **arr, int n);

#endif
