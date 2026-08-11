/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:28:02 by ywada             #+#    #+#             */
/*   Updated: 2025/03/15 18:25:00 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_va_start(t_ft_va_list *ap, void *last, size_t last_size)
{
	ap->ptr = (unsigned char *)last + last_size + 24;
}

void	ft_va_end(t_ft_va_list *ap)
{
	ap->ptr = NULL;
}
