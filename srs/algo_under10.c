/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_under10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:45:58 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/09 15:46:01 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_1_2(t_push *var)
{
	if (var->stack_a.stack[0] < var->stack_a.stack[2])
	{
		ft_sa_sb(var->stack_a.stack);
		printf("sa\n");
	}
	else
	{
		ft_ra_rb(&var->stack_a);
		printf("ra\n");
	}
}

void	case_2_5(t_push *var)
{
	if (var->stack_a.stack[0] > var->stack_a.stack[1])
	{
		ft_sa_sb(var->stack_a.stack);
		printf("sa\n");
		ft_rra_rrb(&var->stack_a);
		printf("rra\n");
	}
	else
	{
		ft_rra_rrb(&var->stack_a);
		printf("rra\n");
	}
}

void	algo_3number(t_push *var)
{
	int	min;

	get_min_num(var->stack_a.size, var->stack_a.stack, &min);
	if (var->stack_a.stack[1] == min)
		case_1_2(var);
	if (var->stack_a.stack[2] == min)
		case_2_5(var);
	if (var->stack_a.stack[0] == min
		&& var->stack_a.stack[1] > var->stack_a.stack[2])
	{
		ft_sa_sb(var->stack_a.stack);
		printf("sa\n");
		ft_ra_rb(&var->stack_a);
		printf("ra\n");
	}
}

void	free_b(t_push *var)
{
	while (var->stack_b.size > 0)
	{
		ft_pa_pb(&var->stack_a, &var->stack_b);
		printf("pa\n");
	}
	free(var->stack_b.stack);
}

void	algo_under10(t_push *var)
{
	int	p;
	int	min;
	int	min_index;

	while (var->stack_a.size > 3)
	{
		p = var->stack_a.size / 2;
		min_index = get_min_num(var->stack_a.size, var->stack_a.stack, &min);
		sort_method_a(var, min_index, p);
		ft_pa_pb(&var->stack_b, &var->stack_a);
		printf("pb\n");
	}
	algo_3number(var);
	free_b(var);
}
