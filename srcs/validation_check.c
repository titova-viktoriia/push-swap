
#include "push_swap.h"

int			check_flags(t_pushswap *head, char **argv)
{
	int i;

	i = head->count_of_elements;
	while (i > 0)
	{
		if (ft_strcmp(argv[i], "-t\0") == 0)
			head->t_flag = 1;
		else
			break ;
		i--;
	}
	if ((head->count_of_elements = i) == 0)
		return (0);
	return (1);
}

int			check_actions_str(char *str, int i)
{
	if (ft_strncmp(str + i, "sa\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "sb\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "ss\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "pa\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "pb\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "ra\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "rb\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "rr\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "rra\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "rrb\0",
			ft_strlen_sym(str + i, '\n')) == 0 ||
	ft_strncmp(str + i, "rrr\0",
			ft_strlen_sym(str + i, '\n')) == 0)
		return (0);
	return (-1);
}

char		*reading_file(void)
{
	int				readed;
	char			*buff;
	char			*tmp;
	char			*tmp2;

	tmp = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER + 1)))
		|| read(0, buff, 0) < 0)
		return (NULL);
	while ((readed = read(0, buff, BUFFER)) > 0)
	{
		buff[readed] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buff);
		else
		{
			tmp2 = ft_strdup(tmp);
			ft_strdel(&tmp);
			tmp = ft_strjoin(tmp2, buff);
			ft_strdel(&tmp2);
		}
	}
	ft_strdel(&buff);
	return (tmp);
}

int			check_actions(t_pushswap *head)
{
	int i;

	i = 0;
	head->actions = reading_file();
	while (head->actions != NULL && head->actions[i] != '\0')
	{
		if (head->actions[i] == '\n' ||
		check_actions_str(head->actions, i) == -1)
			return (0);
		while (head->actions[i] >= 'a' && head->actions[i] <= 'z')
			i++;
		if (head->actions[i] != '\n' && head->actions[i] != '\0')
			return (0);
		if (head->actions[i] != '\0')
			i++;
	}
	return (1);
}

int			check_argv(const char *str, char stop)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	if ((str[0] == '-' || str[0] == '+') && (str[1] == stop || str[1] == '\0' ||
		str[1] == '0'))
		return (-1);
	if (str[0] == '0' && str[1] != stop && str[1] != '\0')
		return (-1);
	while (str[i] != stop && str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	if (i > 11)
		return (-1);
	return (1);
}
