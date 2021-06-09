/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:19:16 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/08 13:19:21 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_intlen(unsigned int n, int base)
{
	int i;

	i = 1;
	while (n / base != 0)
	{
		n = n / base;
		i++;	
	}
	return (i);
}

void		swap(int *a, int *b)
{
	int keep;

	keep = *a;
	*a = *b;
	*b = keep;
}

void		sort_table(t_push *vars)
{
	int i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = vars->stack_a.size;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (vars->sorted_tab[i] > vars->sorted_tab[j])
				swap(&vars->sorted_tab[i], &vars->sorted_tab[j]);
			j++;
		}
		i++;
	}
}

void		copy_stack_to_array(t_push *var)
{
	var->sorted_tab = malloc(sizeof(int) * var->stack_a.size);
	ft_memcpy(var->sorted_tab, var->stack_a.stack, var->stack_a.size * 4);
}