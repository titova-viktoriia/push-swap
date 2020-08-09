
#include "ft_printf.h"

void	ft_putstr_with_counter(char *str, t_data *data)
{
	size_t		len;
	size_t		i;
	int			b;

	b = 0;
	i = 0;
	if (str == NULL)
		return ;
	len = ft_strlen(str);
	if (data->type == 's' && data->precision > -1 && data->precision < (int)len)
		len = data->precision;
	if (data->type == 's' && data->flag_dot == 1 && data->precision < 0)
		len = 0;
	data->len = data->len + len;
	while (i < len && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
