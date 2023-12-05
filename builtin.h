#ifndef	BUILTIN_H
# define BUILTIN_H

#define NULL 0

int	ft_cd(const char *arg);
int	ft_echo(const char **arg);
int	ft_exit(const char **arg);
int ft_export(const char **arg);
int	ft_pwd(void);
int	ft_unset(const char **arg);
int	ft_env(void);

#endif
