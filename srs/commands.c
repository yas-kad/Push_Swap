/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:05:13 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/06 18:05:15 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void        ft_sa_sb(int *stack)
{
    int     tmp;
    
    tmp = stack[0];
    stack[0] = stack[1];
    stack[1] = tmp;
}

void        ft_ss(int *stack_a, int *stack_b)
{
    ft_sa_sb(stack_a);
    ft_sa_sb(stack_b);
}

void        ft_pa(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_b->size > 0)
    {
        int i;
        int num;
        int size;

        i = 0;
        num = stack_b->stack[0];
        size = stack_a->size;
        while (size > 0)
        {
            // if (size == 0)
            //     stack_a.stack[size] = num;
            // else
            stack_a->stack[size] = stack_a->stack[size - 1];
            size--;
        }
        stack_a->stack[0] = num;
        stack_a->size++;
        while (i < stack_b->size)
        {
            stack_b->stack[i] = stack_b->stack[i + 1];
            i++;
        }
        stack_b->size--;
    }
    else
        put_err_and_exit();
    
}

void        ft_ra(t_stack *stack_a)
{
    if(stack_a->size > 0)
    {
        int tmp;
        int i;

        tmp = stack_a->stack[0];
        i = 0;
        while (i < stack_a->size - 1)
        {
            stack_a->stack[i] = stack_a->stack[i + 1];
            i++;
        }
        stack_a->stack[i] = tmp;
        
    }
    else
        put_err_and_exit();
}

void        ft_rra(t_stack *stack_a)
{
    if (stack_a->size > 0)
    {
        int tmp;
        int size;
        int i;

        size = stack_a->size;
        tmp = stack_a->stack[--size];
        while (size > 0)
        {
            stack_a->stack[size] = stack_a->stack[size - 1];
            size--;
        }
        stack_a->stack[size] = tmp;
    }
    else
        put_err_and_exit();
}