/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:37:53 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:40:21 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include "typeft.h"
# include "msh_structs.h"//kullanilmamis

t_c_char			**parse_cmd(t_c_char *cmd, int a, t_c_char **arg);
t_tokenzied_list	*lexer(t_c_char **words);
char				**ft_str_wordtab(char *str);
int					is_seperator(t_c_char *strr);
int					is_seperator_in(t_c_char *str);
int					is_double_seperator_in(t_c_char *str);
char				*ft_strsubdup(const char *s, size_t start, size_t end);

#endif
