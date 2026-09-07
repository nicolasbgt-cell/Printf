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
