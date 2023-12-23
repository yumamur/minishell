#include "msh_structs.h"
#include "lexer.h"
#include "libft/libft.h"
#include "lpc.h"

int		is_syntax_valid(t_tokenzied_list *lst);
t_list	*separate_by_pipe(t_tokenzied_list *tkn_list);
void	create_redirection_files(void *inner_list);
void	validate_cmds(void *inner_list);

void	free_parse(t_list *parsed)
{
	t_list	*ptr;
	
	ptr = parsed;
	while (ptr)
	{
		lpc_export(ptr, NULL);
		ptr = ptr->next;
	}
	lpc_flush();
}

t_list	*parse(char *input)
{
	t_list				*cmds;
	t_tokenzied_list	*lex;
	char				**tab;

	tab = ft_str_wordtab(input);
	lex = lexer((const char **)tab);
	free(tab);
	if (is_syntax_valid(lex))
	{
		free(lex);
		return (NULL);
	}
	cmds = separate_by_pipe(lex);
	// ft_lstiter(cmds, validate_cmds);
	ft_lstiter(cmds, create_redirection_files);
	return (cmds);
}
