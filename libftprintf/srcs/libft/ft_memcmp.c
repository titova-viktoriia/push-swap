
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	i = 0;
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a[i] == b[i] && n - 1 > i)
	{
		i++;
	}
	return (a[i] - b[i]);
}
