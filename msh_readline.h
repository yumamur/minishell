#ifndef MSH_READLINE_H
# define MSH_READLINE_H

char	*readline(const char *prompt);
void	add_history(const char *string);
void	rl_clear_history(void);
void	rl_replace_line(const char *string, int i);
int		rl_on_new_line(void);
void	rl_redisplay(void);
#endif
