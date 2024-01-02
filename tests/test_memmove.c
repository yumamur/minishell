#include <stdio.h>
#include "../libft/libft.h"

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc < 2)
		return (0);
	str = ft_strdup(argv[1]);
	printf("%lu %s\n", ft_strlen(str), str);
	ft_memmove(str, str + 1, ft_strlen(str));
	str[ft_strlen(str) - 1] = 0;
	printf("%lu %s\n", ft_strlen(str), str);
	free(str);
}
