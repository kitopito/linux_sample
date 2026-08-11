/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:22 by ywada             #+#    #+#             */
/*   Updated: 2025/03/15 18:25:23 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_va_list
typedef struct s_ft_va_list
{
	unsigned char	*ptr;
}					t_ft_va_list;


char	*ft_va_str(t_ft_va_list *ap)
{
	char	*str;

	str = *(char **)(ap->ptr);
	ap->ptr += sizeof(char *);
	return (str);
}

#include <stdio.h>

void	print_strs(char *s1, ...)
{
	t_ft_va_list	ap;
	char			*str;

	ft_va_start(&ap, &s1, sizeof(char *));
	str = ft_va_str(&ap);
	while (str != NULL)
	{
		printf("%s\n", str);
		str = ft_va_str(&ap);
	}
	ft_va_end(&ap);
}

void	ft_p(int fmt, unsigned long moke, ...)
{
	void	*p2;
	int		a2;

	// p2 = ((char *)&fmt) + ((sizeof(fmt) + 3) / 4) * 8;
	// a2 = *(int *)p2;
	printf("%d\n", a2);
}

int	main(void)
{
	print_strs("HOGE", "/", "FUGA ", "PIYO", " ", "hello.", NULL);
	// ft_p(42, (unsigned long)0x1234567812345678, 0xabcdabcdabcdabcd, 42, 42);
	return (0);
}

// gcc libft/ft_va_arg.c libft/ft_va_list.c