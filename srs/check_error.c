/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:46:54 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/08 10:46:57 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	put_err_and_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	is_curr_str_int(char *str)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!ft_isdigit(str[++i]))
			put_err_and_exit();
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		num = (num * 10) + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

char	**ft_get_line(char **argv, int argc)
{
	char	*tmp;
	char	*tmp1;
	char	*str;
	char	**split;
	int		j;

	j = 0;
	tmp = NULL;
	str = NULL;
	while (++j < argc)
	{
		if (!str)
			str = ft_strjoin(argv[j], " ");
		else
		{
			tmp = str;
			tmp1 = ft_strjoin(argv[j], " ");
			str = ft_strjoin(str, tmp1);
			free(tmp);
			free(tmp1);
		}
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

char	**check_error(char **str, int argc)
{
	int		i;
	char	**argv;

	argv = ft_get_line(str, argc);
	i = 0;
	if (!argv || !argv[0])
		put_err_and_exit();
	while (argv[i])
	{
		if (is_curr_str_int(argv[i]) == false)
			put_err_and_exit();
		i++;
	}
	return (argv);
}

int	already_sorted(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1])
		{
			if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}
