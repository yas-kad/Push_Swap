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
	int			*sorted_tab;
	int			tab_size;
}               t_push;


void		put_err_and_exit();

void		ft_sa_sb(int *stack);
void		ft_ra(t_stack *stack_a);
void		ft_rra(t_stack *stack_a);
void		ft_pa(t_stack *stack_a, t_stack *stack_b);

int			check_error(char **argv);
int			check_double(char **argv);
int			already_sorted(char **str);

void		execute_algo(t_push *vars);
void		algo_under10(t_push *var);
void		algo_under100(t_push *var);
void		algo_above100(t_push *var);

void		sort_table(t_push *vars);
void		copy_stack_to_array(t_push *var);

void		algo_3number(t_push *var);
int			get_min_num(int size, int *stack, int *min);
void		get_quarter_num(t_push *var, int num);
void		sort_last_numbers_in_a(t_push *var);
void		execute_algo(t_push *vars);
#endif
