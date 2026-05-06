/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:22:10 by nbigot            #+#    #+#             */
/*   Updated: 2026/05/06 12:43:04 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display(const char *str, int *i, int *count, va_list ap)
{
	if (str[*i] == '%')
	{
		if (str[*i + 1] == 'c')
			*count = *count + ft_print_char(va_arg(ap, int));
		else if (str[*i + 1] == 's')
			*count = *count + ft_print_str(va_arg(ap, char *));
		else if (str[*i + 1] == 'p')
			*count = *count + ft_print_ptr(va_arg(ap, void *));
		else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
			*count = *count + ft_print_nbr(va_arg(ap, int));
		else if (str[*i + 1] == 'u')
			*count = *count + ft_print_unsigned(va_arg(ap, unsigned int));
		else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
			*count = *count + ft_print_hex(va_arg(ap, unsigned int),
					str[*i + 1]);
		else
			*count = *count + ft_print_char('%');
		*i = *i + 2;
	}
	else
	{
		*count = *count + ft_print_char(str[*i]);
		(*i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		display(str, &i, &count, ap);
	}
	va_end(ap);
	return (count);
}
