#ifndef	BUILTIN_H
# define BUILTIN_H

#define NULL 0

#include "libft/libft.h"
#include "typeft.h"

int	ft_cd(char *arg);
int	ft_echo(char **arg);
int	ft_exit(char **arg, int *last_exit);
int ft_export(char **arg);
int	ft_pwd(void);
int	ft_unset(char **arg);
int	ft_env(void);

#endif