/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_under100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:17:54 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/09 17:17:59 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(t_stack stack, int num)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		if (stack.stack[i] <= num)
			return (i);
		i++;
	}
	return (-1);
}

void	get_quarter_num(t_push *var, int num)
{
	int	p;
	int	index;

	index = 0;
	while (1)
	{
		index = get_index(var->stack_a, num);
		if (index == -1)
			break ;
		p = var->stack_a.size / 2;
		sort_method_a(var, index, p);
		ft_pa_pb(&var->stack_b, &var->stack_a);
		printf("pb\n");
	}
}

void	free_b_to_a(t_push *var)
{
	int	p;
	int	index_max;

	while (var->stack_b.size > 0)
	{
		index_max = find_max(var->stack_b.stack, var->stack_b.size);
		p = var->stack_b.size / 2;
		sort_method_b(var, index_max, p);
		ft_pa_pb(&var->stack_a, &var->stack_b);
		printf("pa\n");
	}
	free(var->stack_b.stack);
}

void	sort_last_numbers_in_a(t_push *var)
{
	int	i;
	int	p;
	int	min;
	int	min_index;

	while (var->stack_a.size > 3)
	{
		i = 0;
		p = var->stack_a.size / 2;
		min_index = get_min_num(var->stack_a.size, var->stack_a.stack, &min);
		sort_method_a(var, min_index, p);
		ft_pa_pb(&var->stack_b, &var->stack_a);
		printf("pb\n");
	}
	algo_3number(var);
	free_b_to_a(var);
}

void	algo_under100(t_push *var)
{
	int	i;
	int	num;
	int	key;

	i = 1;
	var->tab_size = var->stack_a.size;
	while (i <= 4)
	{
		key = var->tab_size * i / 4;
		num = var->sorted_tab[key];
		get_quarter_num(var, num);
		i++;
	}
	sort_last_numbers_in_a(var);
}
