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

void		algo_above100(t_push *var)
{
	int num;
	int key;

	var->tab_size = var->stack_a.size;

	key = var->tab_size / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);


	key = var->tab_size * 2 / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * 3 / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * 4 / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * 5 / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * 6 / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	key = var->tab_size * 7 / 8;
	num = var->sorted_tab[key];
	get_quarter_num(var, num);

	sort_last_numbers_in_a(var);
}