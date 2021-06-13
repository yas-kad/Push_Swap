/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:41:29 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/12 17:41:31 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_num(int size, int *stack, int *min)
{
	int	i;
	int	index;

	*min = stack[0];
	index = 0;
	i = 1;
	while (i < size)
	{
		if (*min > stack[i])
		{
			*min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_max(int *stack, int size)
{
	int	i;
	int	max;
	int	index;

	max = stack[0];
	index = 0;
	i = 1;
	while (i < size)
	{
		if (max < stack[i])
		{
			max = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	sort_method_a(t_push *var, int index, int p)
{
	int	len;

	if (index > p)
	{
		len = var->stack_a.size - index;
		while (len > 0)
		{
			ft_rra_rrb(&var->stack_a);
			printf("rra\n");
			len--;
		}
	}
	else
	{
		while (index > 0)
		{
			ft_ra_rb(&var->stack_a);
			printf("ra\n");
			index--;
		}	
	}
}

void	sort_method_b(t_push *var, int index, int p)
{
	int	len;

	if (index > p)
	{
		len = var->stack_b.size - index;
		while (len > 0)
		{
			ft_rra_rrb(&var->stack_b);
			printf("rrb\n");
			len--;
		}
	}
	else
	{
		while (index > 0)
		{
			ft_ra_rb(&var->stack_b);
			printf("rb\n");
			index--;
		}
	}
}
