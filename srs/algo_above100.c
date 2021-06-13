/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_above100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:23:41 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/10 19:23:43 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_above100(t_push *var)
{
	int	i;
	int	num;
	int	key;

	i = 1;
	var->tab_size = var->stack_a.size;
	while (i <= 7)
	{
		key = var->tab_size * i / 8;
		num = var->sorted_tab[key];
		get_quarter_num(var, num);
		i++;
	}
	sort_last_numbers_in_a(var);
}
