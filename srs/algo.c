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

void		execute_algo(t_push *vars)
{
	if (vars->stack_a.size <= 10)
		algo_under10(vars);
	if (vars->stack_a.size > 10 && vars->stack_a.size <= 100)
		algo_under100(vars);
	if (vars->stack_a.size > 100)
		algo_above100(vars);
}
