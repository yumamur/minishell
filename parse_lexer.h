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

#ifndef PARSE_LEXER_H
# define PARSE_LEXER_H

# include "typeft.h"
# include "msh_structs.h"

t_tokenized_list	*lexer(t_c_char **words);
char				**ft_str_wordtab(char *str);

#endif
