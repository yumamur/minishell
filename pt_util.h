#ifndef PT_UTIL_H
# define PT_UTIL_H

void	**pt_util_copy_ptr_arr(void **arr)
		__attribute__((malloc));
void	**pt_util_realloc_ptr_arr(void **arr, int to_add)
		__attribute__((malloc));
int		pt_util_size_ptr_arr(void **arr);

void	**arr_copy(void **arr);
void	**arr_realloc(void **arr, int to_add);
int		arr_size(void **arr);

#endif
