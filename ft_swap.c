/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:18:43 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_arg **list, t_arg *second)
{
	if (second->next)
		second->next->back = *list;
	second->back = (*list)->back;
	(*list)->back = second;
	(*list)->next = second->next;
	second->next = *list;
	*list = second;
}

void	ft_s(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		ft_swap(&stack->a, stack->a->next);
		write(1, "sa\n", 3);
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		ft_swap(&stack->b, stack->b->next);
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		ft_swap(&stack->a, stack->a->next);
		ft_swap(&stack->b, stack->b->next);
		write(1, "ss\n", 3);
	}
}
