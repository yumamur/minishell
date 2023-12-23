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
