/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:15:50 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/12 18:15:54 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	before(char **argv, char *str, int size)
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

int	check_double(char **argv)
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
