/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:57:04 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 00:57:05 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*_last_exit_location(void)
{
	static int	last_exit_status;

	return (&last_exit_status);
}

void	***g_env(void)
{
	static void	**env;

	return (&env);
}
