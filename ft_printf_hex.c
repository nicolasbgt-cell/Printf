/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:23:48 by nbigot            #+#    #+#             */
/*   Updated: 2026/05/06 16:14:03 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count = count + ft_print_hex(n / 16, format);
	count = count + ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		ft_print_str("(nil)");
		return (5);
	}
	count = count + ft_print_str("0x");
	count = count + ft_print_hex((unsigned long)ptr, 'x');
	return (count);
}
