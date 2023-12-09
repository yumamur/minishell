#include "libft/libft.h"
#include "typeft.h"

int is_double_seperator_in(t_ushort chrs)
{
	t_ushort	seperators[4];
	int			i;
	
	seperators[0] = ('>' << 8) + '>';
	seperators[1] = ('<' << 8) + '<';
	seperators[2] = ('&' << 8) + '&';
	seperators[3] = ('|' << 8) + '|';
	i = -1;
	while (++i < 4)
		if (chrs == seperators[i])
			return (1);
	return (0);
}

int is_seperator_in(int	chr)
{
	char	seperators[3];
	int		i;

	seperators[0] = '>';
	seperators[1] = '<';
	seperators[2] = '|';
	i = -1;
	while (++i < 3)
		if (chr == seperators[i])
			return (1);
	return (0);
}

int is_seperator(char *str)
{
	while (*str)
	{
		if (*str == '\'')
			str = ft_strchr(str, '\'');
		if (*str == '\"')
			str = ft_strchr(str, '\"');
		if (*(str + 1) && is_double_seperator_in((*str << 8) + (*str + 1)))
			return (2);
		else if (*str && is_seperator_in(*str))
			return (1);
		++str;
	}
	return (0);
}
