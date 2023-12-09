#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include "typeft.h"
# include "msh_structs.h"//kullanilmamis

t_c_char            **parse_cmd(t_c_char *cmd, int a, t_c_char **arg);
t_tokenzied_list	*lexer(t_c_char **words);
char	            **ft_str_wordtab(char *str);
int					is_seperator(t_c_char *strr);
int					is_seperator_in(t_c_char *str);
int					is_double_seperator_in(t_c_char *str);
char				*ft_strsubdup(const char *s, size_t start, size_t end);

#endif
