/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:00:03 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/24 01:00:04 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LPC_H
# define LPC_H

# ifdef __clang__

int	lpc_export(void *addr, ...) __attribute__((sentinel(0, 0)));
# else
#  ifdef __GNUC__

int	lpc_export(void *addr, ...) __attribute__((sentinel(0)));
#  endif
# endif

int	lpc_flush(void);

#endif /* LPC_H */
