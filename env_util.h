#ifndef MSH_ENV_H
# define MSH_ENV_H

char *const	**g_env(void);
int			env_init(char **data);
int			env_deinit(void);
int			env_add(const char *var);
int			env_remove(char *to_remove);
const char	*ft_getenv(const char *name);

#endif
