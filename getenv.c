#include "typeft.h"
#include "libft/libft.h"

static t_c_char	inline	*ft_getenv_inline(t_c_char *envp[], t_c_char *name)
{
	size_t		len;
	t_ushort	name_start;
	t_ushort	ptenv_start;

	name_start = (name[0] * 256) + name[1];
	len = ft_strlen(name);
	while (*envp)
	{
		ptenv_start = ((*envp)[0] * 256) + (*envp)[1];
		if (ptenv_start == name_start && (*envp)[len] == '='
			&& !ft_strncmp(*envp + 2, name + 2, len - 2))
			return (&(*envp)[len + 1]);
		envp++;
	}
	return (NULL);
}

t_c_char	*ft_getenv(t_c_char *envp[], t_c_char *name)
{
	t_c_char	**ptenv;
	t_ushort	name_start;
	t_ushort	ptenv_start;

	if (!envp || !envp[0] || !name || name[0] == '\0')
		return (NULL);
	if (name[1] == '\0')
	{
		ptenv = envp;
		((t_uchar *)&name_start)[0] = *(t_uchar *)name;
		((t_uchar *)&name_start)[1] = '=';
		while (*ptenv)
		{
			ptenv_start = *((t_ushort *)*ptenv);
			if (ptenv_start == name_start)
				return (&(*ptenv)[2]);
			ptenv++;
		}
	}
	else
		return (ft_getenv_inline(envp, name));
	return (NULL);
}
