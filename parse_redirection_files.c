#include <fcntl.h>
#include "libft/libft.h"
#include "msh_structs.h"

static void	setfor_out_file(int *o_flags, int *opr_flag)
{
	*o_flags = O_CREAT | O_WRONLY | O_TRUNC;
	*opr_flag = 1 - *opr_flag;
}

static void	setfor_append_file(int *o_flags, int *opr_flag)
{
	*o_flags = O_CREAT | O_WRONLY | O_APPEND;
	*opr_flag = 1 - *opr_flag;
}

static void	create_redir(void *tokenized)
{
	static int	open_flags;
	static int	operate_flag;
	t_tokenized	*ptr;

	ptr = tokenized;
	if (!operate_flag && ptr->token == REDIRECT_OUT)
		setfor_out_file(&open_flags, &operate_flag);
	else if (!operate_flag && ptr->token == APPEND)
		setfor_append_file(&open_flags, &operate_flag);
	else if (operate_flag)
	{
		if (ptr->token == WORD)
		{
			operate_flag = open(ptr->str, open_flags, 0644);
			if (operate_flag != -1)
				close(operate_flag);
		}
		operate_flag = 0;
	}

}

void	create_redirection_files(t_list *head)
{
	ft_lstiter(head, create_redir);
}
