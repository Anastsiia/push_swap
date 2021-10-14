/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:18:04 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_three_sort(t_arg *one, t_arg *two, t_arg *three, t_anb *stack)
{
	if (one->num > two->num && two->num > three->num)
	{
		ft_s(stack, 'a');
		ft_rr(stack, 'a');
	}
	if (one->num < three->num && two->num > three->num)
	{
		ft_s(stack, 'a');
		ft_r(stack, 'a');
	}
	if (one->num > two->num && one->num < three->num)
		ft_s(stack, 'a');
	if (one->num > three->num && two->num < three->num)
		ft_r(stack, 'a');
	if (one->num > three->num && two->num > one->num)
		ft_rr(stack, 'a');
}

static void	ft_six_sort(t_anb *stack, int count)
{
	int	step;

	step = 0;
	while (step < count - 3)
	{
		if (stack->a->index <= count - 3)
		{
			ft_p(stack, 'b');
			step++;
		}
		ft_rr(stack, 'a');
	}
	ft_three_sort(stack->a, stack->a->next, stack->a->next->next, stack);
	if (!ft_check_sort(stack->b))
		ft_r(stack, 'b');
	while (stack->b)
		ft_p(stack, 'a');
}

void	ft_sort_stack(t_anb *stack)
{
	int	len;

	len = ft_lstsize(stack->a);
	ft_fill_index(stack->a, len);
	if (len == 2)
		ft_s(stack, 'a');
	else if (len == 3)
		ft_three_sort(stack->a, stack->a->next, stack->a->next->next, stack);
	else if (len < 6)
		ft_six_sort(stack, len);
	else
		ft_all_sort(stack, len);
}
