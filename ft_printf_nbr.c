/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:23:21 by nbigot            #+#    #+#             */
/*   Updated: 2026/05/06 15:58:34 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	if (!str)
		return (0);
	count = ft_print_str(str);
	free(str);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	char	buf[11];
	int		i;
	int		count;

	i = 10;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = '0';
	while (n > 0)
	{
		buf[--i] = (n % 10) + '0';
		n /= 10;
	}
	count = ft_print_str(&buf[i]);
	return (count);
}
