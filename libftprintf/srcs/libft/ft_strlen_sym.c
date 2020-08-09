
#include "libft.h"

size_t		ft_strlen_sym(const char *str, char sym)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != sym)
		i++;
	return (i);
}
