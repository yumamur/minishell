#include "msh_core.h"
#include "env_util.h"
#include "libft/libft.h"
#include "typeft.h"

t_bool	contains_variable(char *str)
{
	while (*str)
	{
		if (*str == '\'')
			str = ft_strchr(str + 1, '\'');
		else if (*str == '$')
			return (TRUE);
		++str;
	}
	return (FALSE);
}

static void	bypass_single_qt(char **str, size_t *len)
{
	char	*ptr;

	ptr = ft_strchr((*str) + 1, '\'');
	if (!ptr)
	{
		(*str)++;
		return ;
	}
	*len += ptr - *str + 1;
	*str = ptr + 1;
}

static void	length_of_last_exit(char **str, size_t *len)
{
	int	status;

	status = *_last_exit_location();
	++*len;
	while (status)
	{
		status /= 10;
		++*len;
	}
	*str += 2;
}

static void	length_of_var_name(char **str, size_t *len)
{
	char	*ptr;
	char	*val;
	int		buf;

	ptr = *str;
	++ptr;
	while (*ptr && (ft_isalnum(*ptr) || *ptr == '_'))
		++ptr;
	buf = *ptr;
	*ptr = 0;
	val = (char *)ft_getenv(*str + 1);
	if (val)
		*len += ft_strlen(val);
	*ptr = buf;
	*str = ptr;
}

size_t	calculate_length(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\'')
			bypass_single_qt(&str, &len);
		else if (*str != '$' || !*(str + 1))
		{
			++str;
			++len;
		}
		else if (*(str + 1) == '?')
			length_of_last_exit(&str, &len);
		else if (!ft_isalpha(*(str + 1)) && *(str + 1) != '_')
		{
			str += 2;
			len += 2;
		}
		else
			length_of_var_name(&str, &len);
	}
	return (len);
}
