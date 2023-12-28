/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:02:01 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:02:02 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_STRUCTS_H
# define MSH_STRUCTS_H

# include "typeft.h"

# define MAX_REDIRECTION 256

typedef enum e_token
{
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	APPEND,
	HEREDOC,
	OR,
	AND,
	FILE_IN,
	FILE_OUT,
	FILE_APPEND,
	EOF_HEREDOC,
	INVALID
}	t_token;

typedef struct s_tokenized
{
	char	*str;
	t_token	token;
}	t_tokenized;

typedef struct s_tokenized_list
{
	t_c_char				*str;
	t_token					token;
	struct s_tokenized_list	*next;
}	t_tokenized_list;

typedef struct s_cmd
{
	t_c_char	*cmd;
	t_c_char	**args;
}	t_cmd;

#endif
