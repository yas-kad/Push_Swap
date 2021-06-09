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

int			get_index(int *tab, int num)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] <= num)
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
			index = get_index(var->stack_a.stack, num);
			if (index == -1)
				break ;
			printf("index:[%d][%d]\n",index,var->stack_a.size);
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

void		algo_under100(t_push *var)
{
	int num;
	int key;

	var->tab_size = var->stack_a.size;

	key = var->tab_size / 4;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);


	key = var->tab_size * (2 / 4);
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * (3 / 4);
	num = var->sorted_tab[key];
printf("HHHHHHHH{%d}\n",num);
	get_quarter_num(var, num);

}