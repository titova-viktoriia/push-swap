
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned int		k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0' && k < n)
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	return (s1);
}
