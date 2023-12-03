#ifndef MSH_ENV_H
# define MSH_ENV_H

const void *const	**g_env(void);
int					env_init(void **data);
int					env_deinit(void);
int					env_add(const char *var);
int					env_remove(char *to_remove);

#endif
