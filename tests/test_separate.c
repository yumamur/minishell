#include <stdio.h>
#include "../libft/libft.h"
#include "../msh_structs.h"
#include "../lexer.h"
#include "../parse.h"
#include "../lpc.h"


void	puttoken(void *ptr)
{
	t_tokenized	*tkn;

	tkn = ptr;
	printf("%s\t", ((char *[]){"WORD", "PIPE", "RDR_IN", "RDR_OUT",
			"APPEND", "HEREDOC", "OR", "AND", "INVALID"})[tkn->token]);
	printf(" = %s\n", tkn->str);
}

int main(int argc, char *argv[])
{
	char				**tab;
	t_tokenized_list	*lex;
	char *tmp;

	(void)argc;
	tmp = ft_strdup(argv[0]);
	tab = ft_str_wordtab(tmp);
	for (int i = 0; tab[i]; ++i) printf("%s\n", tab[i]);

	lex = lexer((const char **)tab);
	typeof(lex) ptr = lex;
	while (ptr)
	{
		printf("%d  %s\n", ptr->token, ptr->str);
		ptr = ptr->next;
	}
	lpc_flush();
}

// int	main(int argc, char *argv[])
// {
// 	t_list	*parsed;
// 	t_list	*ptr;
// 	size_t	size;
// ;
// 	if (argc < 2 || !argv)
// 		return (-1);
// 	parsed = parse(argv[1]);
// 	size = ft_lstsize(parsed);
// 	ptr = parsed;
// 	while (ptr)
// 	{
// 		printf("%lu\n", size - ft_lstsize(ptr));
// 		ft_lstiter(ptr->content, puttoken);
// 		ptr = ptr->next;
// 	}
// 	lpc_flush();
// }
