/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:08:16 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 03:08:17 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

int	set_term_attr(void)
{
	struct termios	term;

	if (tcgetattr(ttyslot(), &term))
		return (-1);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(ttyslot(), 0, &term))
		return (-1);
	return (0);
}

void	unset_term_attr(void)
{
	struct termios	term;

	term = (struct termios){};
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
