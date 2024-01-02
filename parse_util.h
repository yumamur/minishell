/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lexer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:37:53 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:40:21 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include "typeft.h"
# include "libft/libft.h"
# include "msh_structs.h"

t_tokenized_list	*lexer(t_c_char **words);
char				**ft_str_wordtab(char *str);
int					is_syntax_valid(t_tokenized_list *lst);
t_list				*separate_by_pipe(t_tokenized_list *tkn_list);
void				create_redirection_files(void *inner_list);
void				validate_cmds(void *inner_list);
int					is_cmds_valid(t_list *head);
char				*env_variable_extension(char *str);

#endif
