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

void			put_err_and_exit()
{
    ft_putstr_fd("Error\n",1);
    exit(0);
}

int			before(char **argv, char *str, int size)
{
	int	i;

	i = 0;
	while (argv[i] && i < size)
	{
		if (!ft_strcmp(argv[i], str))
			return (0);
		i++;
	}
	return (1);
}

int			check_double(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!before(argv, argv[i], i))
			put_err_and_exit();
		i++;
	}
	return (1);
}

int			is_curr_str_int(char *str)
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
        i++;
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

int			check_error(char **argv)
{
    int i;
    int j;

    i = 1;
	if (!argv || !argv[1])
		put_err_and_exit();
    while (argv[i])
    {
        if (is_curr_str_int(argv[i]) == false)
            put_err_and_exit();
        i++;
    }
    return(true);
}

int			already_sorted(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1])
		{
			if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
				return(0);	
		}
		i++;
	}
	return(1);
}