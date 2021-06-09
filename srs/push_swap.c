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

void        take_argv(t_push *var, int ac, char **argv)
{
    int     i;

    i = -1;
    var->stack_a.stack = (int *)malloc(sizeof(int) * (ac - 1));
    var->stack_b.stack = (int *)malloc(sizeof(int) * (ac - 1));
    var->stack_a.size = ac - 1;
    while (++i < ac - 1)
        var->stack_a.stack[i] = ft_atoi(argv[i + 1]);
}

void        initialize(t_push *var)
{
    var->stack_a.size = 0;
    var->stack_b.size = 0;
}

int         main(int ac, char **argv)
{
    t_push  vars;

    check_error(argv);
    check_double(argv);
	if (already_sorted(argv + 1) == 1)
		exit(1);
    initialize(&vars);
    take_argv(&vars, ac, argv);
    
	//sort_stack(&vars);
	execute_algo(&vars);
    //int i = 0;
    //ft_sa_sb(vars.stack_a.stack);
    //ft_pa(&vars.stack_b, &vars.stack_a);
    //ft_pa(&vars.stack_b, &vars.stack_a);
    //ft_ra(&vars.stack_a);
    //ft_rra(&vars.stack_a);
    printf("stack a\n");
    for (int i = 0; i < vars.stack_a.size; i++)
    {
        ft_putnbr_fd(vars.stack_a.stack[i],1);
        write(1,"\n",1);
    }
    printf("stack b\n");
    for (int i = 0; i < vars.stack_b.size; i++)
    {
        ft_putnbr_fd(vars.stack_b.stack[i],1);
        write(1,"\n",1);
    }
    free(vars.stack_a.stack);
}