#include <stdlib.h>

void	ft_va_start(t_ft_va_list *ap, void *last, size_t last_size)
{
	ap->ptr = (unsigned char *)last + last_size + 24;
}

void	ft_va_end(t_ft_va_list *ap)
{
	ap->ptr = NULL;
}
