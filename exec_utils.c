#include "libft/libft.h"
#include "typeft.h"

char	*ft_file_name(char *path)
{
	char	*tmp;

	tmp = ft_strdup(ft_strrchr(path, '/') + 1);
	return (tmp);
}

void	ft_free_change(void **dest, void *src)
{
	if (dest)
		free(*dest);
	*dest = src;
}

void	ft_free_2pt(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

char	*ft_strjoin_frees1(char *s1, t_c_char *s2)
{
	char	*str;
	int		i1;
	int		i2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i1 = -1;
	while (s1[++i1])
		str[i1] = s1[i1];
	i2 = 0;
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s1);
	return (str);
}
