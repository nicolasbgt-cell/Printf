/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:21:38 by nbigot            #+#    #+#             */
/*   Updated: 2026/05/06 16:17:53 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_percent(void);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned long n, char format);
int	ft_print_ptr(void *ptr);

#endif
