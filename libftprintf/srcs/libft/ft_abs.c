
#include "libft.h"

int			ft_abs(int a)
{
	if (a >= 0)
		return (a);
	if (a == -2147483648)
		return (2147483647);
	else
		return (a * (-1));
}
