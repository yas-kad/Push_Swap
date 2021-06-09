/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:39:03 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/08 15:39:06 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			get_min_num(int size, int *stack, int *min)
{
	int i;
	int index;

	*min = stack[0];
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
	return(index);
}

void		algo_3number(t_push *var)
{
	int min;

	get_min_num(var->stack_a.size, var->stack_a.stack, &min);
	if (var->stack_a.stack[1] == min)
	{
		if (var->stack_a.stack[0] < var->stack_a.stack[2])
		{
			ft_sa_sb(var->stack_a.stack);
			printf("sa\n"); //case1
		}else
		{
			ft_ra(&var->stack_a);
			printf("ra\n"); //case3
		}
	}
	if (var->stack_a.stack[2] == min)
	{
		if (var->stack_a.stack[0] > var->stack_a.stack[1])
		{
			ft_sa_sb(var->stack_a.stack);
			printf("sa\n");
			ft_rra(&var->stack_a);
			printf("rra\n"); //case2
		}else
		{
			ft_rra(&var->stack_a);
			printf("rra\n"); //case5
		}
	}
	if (var->stack_a.stack[0] == min
						&& var->stack_a.stack[1] > var->stack_a.stack[2])
	{
		ft_sa_sb(var->stack_a.stack);
		printf("sa\n");
		ft_ra(&var->stack_a);
		printf("ra\n"); //case2
	}
}

void		free_b(t_push *var)
{
	while (var->stack_b.size > 0)
	{
		ft_pa(&var->stack_a, &var->stack_b);
		printf("pa\n");
	}
	free(var->stack_b.stack);
}

void		algo_under10(t_push *var)
{
	int	i;
	int p;
	int min;
	int	min_index;

	while (var->stack_a.size > 3)
	{
		i = 0;
		p = var->stack_a.size / 2;
		min_index = get_min_num(var->stack_a.size, var->stack_a.stack, &min);
		if (min_index > p)
		{
			int len = var->stack_a.size - min_index;
			while (len > 0)
			{
				ft_rra(&var->stack_a);
				printf("rra\n");
				len--;
			}
		}
		else
		{
			while (min_index > 0)
			{
				ft_ra(&var->stack_a);
				printf("ra\n");
				min_index--;
			}
			
		}
		ft_pa(&var->stack_b, &var->stack_a);
		printf("pb\n");
	}
	algo_3number(var);
	free_b(var);
}

void		execute_algo(t_push *vars)
{
	if (vars->stack_a.size < 10)
		algo_under10(vars);
}
