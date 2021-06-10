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

int			get_index(t_stack stack, int num)
{
	int i;

	i = 0;
	while (i < stack.size)
	{
		if (stack.stack[i] <= num)
			return(i);
		i++;
	}
	return(-1);
}

void		get_quarter_num(t_push *var, int num)
{
	//int i;
	int p;
	int len;
	int index;

	//i = 0;
	index = 0;
	while (1)
	{
		//if ( var->stack_a.stack[i] <= num)
		//{
			//index = i;
			index = get_index(var->stack_a, num);
			//printf("index:[%d]size:[%d] num[%d]\n",index,var->stack_a.size, num);
			if (index == -1)
				break ;
			p = var->stack_a.size / 2;
			if (index > p)
			{
				len = var->stack_a.size - index;
				while (len > 0)
				{
					ft_rra(&var->stack_a);
					printf("rra\n");
					len--;
				}
			}
			else
			{
				while (index > 0)
				{
					ft_ra(&var->stack_a);
					printf("ra\n");
					index--;
				}
				
			}
			ft_pa(&var->stack_b, &var->stack_a);
			printf("pb\n");
		//}
		//i++;
	}
}

int			find_max(int *stack, int size, int *max)
{
	int i;
	int index;

	*max = stack[0];
	index = 0;
	i = 1;
	while (i < size)
	{
		if (*max < stack[i])
		{
			*max = stack[i];
			index = i;
		}
		i++;
	}
	return(index);
}

void		free_b_to_a(t_push *var)
{
	int p;
	int len;
	int max;
	int index_max;

	while (var->stack_b.size > 0)
	{
		index_max = find_max(var->stack_b.stack, var->stack_b.size, &max);
		p = var->stack_b.size / 2;
		if (index_max > p)
		{
			len = var->stack_b.size - index_max;
			while (len > 0)
			{
				ft_rra(&var->stack_b);
				printf("rrb\n");
				len--;
			}
		}
		else
		{
			while (index_max > 0)
			{
				ft_ra(&var->stack_b);
				printf("rb\n");
				index_max--;
			}
		}
		ft_pa(&var->stack_a, &var->stack_b);
		printf("pa\n");
	}
	free(var->stack_b.stack);
}

void		sort_last_numbers_in_a(t_push *var)
{
	int i;
	int p;
	int len;
	int min;
	int min_index;

	while (var->stack_a.size > 3)
	{
		i = 0;
		p = var->stack_a.size / 2;
		min_index = get_min_num(var->stack_a.size, var->stack_a.stack, &min);
		if (min_index > p)
		{
			len = var->stack_a.size - min_index;
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
	free_b_to_a(var);
}

void		algo_under100(t_push *var)
{
	int num;
	int key;

	var->tab_size = var->stack_a.size;

	key = var->tab_size / 4;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);


	key = var->tab_size * 2 / 4;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * 3 / 4;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	sort_last_numbers_in_a(var);
}