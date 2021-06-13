/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:05:13 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/06 18:05:15 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa_sb(int *stack)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ft_ss(int *stack_a, int *stack_b)
{
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
}

void	ft_pa_pb(t_stack *stack_dest, t_stack *stack_src)
{
	int	i;
	int	num;
	int	size;

	if (stack_src->size > 0)
	{
		i = 0;
		num = stack_src->stack[0];
		size = stack_dest->size;
		while (size > 0)
		{
			stack_dest->stack[size] = stack_dest->stack[size - 1];
			size--;
		}
		stack_dest->stack[0] = num;
		stack_dest->size++;
		while (i < stack_src->size)
		{
			stack_src->stack[i] = stack_src->stack[i + 1];
			i++;
		}
		stack_src->size--;
	}
	else
		put_err_and_exit();
}

void	ft_ra_rb(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->size > 0)
	{
		tmp = stack_a->stack[0];
		i = 0;
		while (i < stack_a->size - 1)
		{
			stack_a->stack[i] = stack_a->stack[i + 1];
			i++;
		}
		stack_a->stack[i] = tmp;
	}
	else
		put_err_and_exit();
}

void	ft_rra_rrb(t_stack *stack_a)
{
	int	tmp;
	int	size;

	if (stack_a->size > 0)
	{
		size = stack_a->size;
		tmp = stack_a->stack[--size];
		while (size > 0)
		{
			stack_a->stack[size] = stack_a->stack[size - 1];
			size--;
		}
		stack_a->stack[size] = tmp;
	}
	else
		put_err_and_exit();
}
