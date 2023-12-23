#include <fcntl.h>
#include "libft/libft.h"
#include "msh_structs.h"

static void	create_redir(void *tokenized)
{
	if (((t_tokenized *)tokenized)->token == FILE_OUT
		&& open(((t_tokenized *)tokenized)->str,
			O_CREAT | O_TRUNC | O_RDWR,
			0644))
		return ;
	else if (((t_tokenized *)tokenized)->token == FILE_APPEND
		&& open(((t_tokenized *)tokenized)->str,
			O_CREAT | O_APPEND | O_RDWR,
			0644))
		return ;
}

void	create_redirection_files(t_list *head)
{
	ft_lstiter(head, create_redir);
}
