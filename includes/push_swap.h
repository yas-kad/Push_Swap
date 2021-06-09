/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:33:12 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/06 15:33:19 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "../libft/libft.h"
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

enum e_bool {false, true};

typedef struct  s_stack
{
    int         *stack;
    int         size;
}               t_stack;

typedef struct  push_swap
{
    t_stack     stack_a;
    t_stack     stack_b;
	int			*tab_sort;
}               t_push;


void		put_err_and_exit();
void		ft_sa_sb(int *stack);
void		ft_ra(t_stack *stack_a);
void		ft_rra(t_stack *stack_a);
int			check_error(char **argv);
int			check_double(char **argv);
void		execute_algo(t_push *vars);
int			already_sorted(char **str);
void		sort_stack(t_push *var);
void		ft_pa(t_stack *stack_a, t_stack *stack_b);

#endif
