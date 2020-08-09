
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
