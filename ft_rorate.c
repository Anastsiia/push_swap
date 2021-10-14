/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rorate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:16:26 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_r(t_arg **list)
{
	t_arg	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list;
	tmp->back->next = NULL;
	tmp->back = NULL;
	(*list)->back = tmp;
	*list = tmp;
}

static void	ft_rotate(t_arg **lst)
{
	t_arg	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	(*lst)->back = tmp;
	tmp->next = *lst;
	(*lst)->next->back = NULL;
	*lst = (*lst)->next;
	tmp->next->next = NULL;
}

void	ft_rr(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		ft_rotate_r(&stack->a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		ft_rotate_r(&stack->b);
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		ft_rotate_r(&stack->a);
		ft_rotate_r(&stack->b);
		write(1, "rrr\n", 4);
	}
}

void	ft_r(t_anb *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		ft_rotate(&stack->a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		ft_rotate(&stack->b);
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		ft_rotate(&stack->a);
		ft_rotate(&stack->b);
		write(1, "rr\n", 3);
	}
}
