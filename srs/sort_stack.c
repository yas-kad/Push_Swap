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

void		swap(int *a, int *b)
{
	int keep;

	keep = *a;
	*a = *b;
	*b = keep;
}

void		sort_stack(t_push *var)
{
	int i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = var->stack_a.size;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (var->stack_a.stack[i] > var->stack_a.stack[j])
				swap(&var->stack_a.stack[i], &var->stack_a.stack[j]);
			j++;
		}
		i++;
	}
}