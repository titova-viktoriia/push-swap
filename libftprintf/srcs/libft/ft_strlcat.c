
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len2);
	while (src[i] != '\0' && len1 + i < size - 1)
	{
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	if (size <= len1)
		return (len2 + size);
	else
		return (len1 + len2);
}
