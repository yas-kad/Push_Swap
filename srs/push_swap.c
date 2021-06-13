/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:32:31 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/06 15:32:34 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	take_argv(t_push *var, int ac, char **argv)
{
	int		i;

	i = -1;
	var->stack_a.stack = (int *)malloc(sizeof(int) * (ac - 1));
	var->stack_b.stack = (int *)malloc(sizeof(int) * (ac - 1));
	var->stack_a.size = ac - 1;
	while (++i < ac - 1)
		var->stack_a.stack[i] = ft_atoi(argv[i]);
}

void	initialize(t_push *var)
{
	var->stack_a.size = 0;
	var->stack_b.size = 0;
}

int	main(int ac, char **argv)
{
	int		i;
	t_push	vars;

	i = 0;
	argv = check_error(argv, ac);
	while (argv[i])
		i++;
	ac = i + 1;
	check_double(argv);
	if (already_sorted(argv) == 1)
		exit(1);
	initialize(&vars);
	take_argv(&vars, ac, argv);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	copy_stack_to_array(&vars);
	sort_table(&vars);
	execute_algo(&vars);
	free(vars.stack_a.stack);
	free(vars.sorted_tab);
}
