/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:56:16 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:56:17 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PT_UTIL_H
# define PT_UTIL_H

void	arr_free(void **arr);
void	**arr_copy(void **arr);
void	**arr_deep_copy(void **arr);
void	**arr_realloc(void **arr, int to_add);
int		arr_size(void **arr);
int		arr_index(void **arr, void *to_find);
int		arr_discard_n(void **arr, int n);

#endif
