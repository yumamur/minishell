#ifndef MSH_ENV_H
# define MSH_ENV_H

const char *const	**g_env(void);
int					env_init(void **data);
int					env_deinit(void);
int					env_add(const char *var);
int					env_remove(char *to_remove);
const char			*ft_getenv(const char *envp[], const char *name);

#endif
