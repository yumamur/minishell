#include <ctype.h>
#include <stdlib.h>
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	errorer(char *command, char *detail, char *error_message, int error_nb);

int export_isvalid(char *str)
{
	int i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (errorer("export", str, "not a valid identifier", EXIT_FAILURE));
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '=' || str[i] == '/')
			i++;
		else
			return (errorer("export", str, "not a valid identifier", EXIT_FAILURE));
	}
	return(1);
}

int	export_isenv(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);

}