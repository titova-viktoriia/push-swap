
#include "libft.h"

int			ft_number_in_degree(int number, int power)
{
	int		result;
	int		i;

	i = 1;
	result = number;
	if (power == 0)
		return (1);
	while (i < power)
	{
		result = result * number;
		i++;
	}
	return (result);
}
