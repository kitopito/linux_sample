#ifndef FT_VA_H
# define FT_VA_H

#include <stdlib.h>

typedef struct s_ft_va_list
{
	unsigned char	*ptr;
}					t_ft_va_list;

void	ft_va_start(t_ft_va_list *ap, void *last, size_t last_size);

void	ft_va_end(t_ft_va_list *ap);

#endif