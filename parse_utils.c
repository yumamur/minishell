#include "libft/libft.h"
#define NULL 0

char	*ft_strsubdup(const char *s, size_t start, size_t end)
{
	char	*dups;
	size_t	len;
	size_t	i;

	if (!s || start > end)
		return (NULL);
	len = ft_strlen(s);
	if (end > len)
		end = len; 
	len = end - start; 
	dups = ft_calloc(len + 1, 1);
	if (!dups)
		return (NULL);
	i = 0;
	while (start < end)
		dups[i++] = s[start++];
	dups[i] = '\0'; 
	return (dups);
}