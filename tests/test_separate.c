#include <stdio.h>
#include "../libft/libft.h"
#include "../msh_structs.h"
#include "../parse.h"


void	puttoken(void *ptr)
{
	t_tokenized	*tkn;

	tkn = ptr;
	printf("%s\t", ((char *[]){"WORD", "PIPE", "RDR_IN", "RDR_OUT",
			"APPEND", "HEREDOC", "OR", "AND", "INVALID"})[tkn->token]);
	printf(" = %s\n", tkn->str);
}

int	main(int argc, char *argv[])
{
	t_list	*parsed;
	t_list	*ptr;
	size_t	size;
;
	if (argc < 2 || !argv)
		return (-1);
	parsed = parse(argv[1]);
	size = ft_lstsize(parsed);
	ptr = parsed;
	while (ptr)
	{
		printf("%lu\n", size - ft_lstsize(ptr));
		ft_lstiter(ptr->content, puttoken);
		ptr = ptr->next;
	}
	free_parse(parsed);
}
