#ifndef PARSE_H
# define PARSE_H

#include "typeft.h"
#include "libft/libft.h"//kullanilmamis
#include "msh_structs.h"//kullanilmamis

t_c_char **parse_cmd(t_c_char *cmd, int a, t_c_char **arg);
t_tokenzied_list	**lexer(t_c_char **words, t_tokenzied_list **for_tok);
int is_seperator(t_c_char *strr);
char	**ft_str_wordtab(char *str);

#endif
