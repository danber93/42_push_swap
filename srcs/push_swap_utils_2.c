#include "push_swap.h"


void	ft_print_error(void)
{
	ft_putstr_fd("Error\n\0", 1);
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (i == (int)ft_strlen(s1))
		return (1);
	return (0);
}

int	ft_repetions(char **av)
{
	int	i;
	int	j;
	int	n_args;

	n_args = ft_n_args(av);
	i = 1;
	while (i < n_args)
	{
		j = i + 1;
		while (j < n_args)
		{
			if (ft_strcmp(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_bigger_maxint(char *str)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res > 2147483647)
			return (1);
	}
	return (0);
}

int	ft_check_valid_input(char **av)
{
	int	i;
	int	j;

	if (ft_repetions(av))
		return (0);
	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j]) || ft_isspace(av[i][j])))
				return (0);
			if ((ft_bigger_maxint(av[i])))
				ft_print_error();
			j++;
		}
		i++;
	}
	return (1);
}