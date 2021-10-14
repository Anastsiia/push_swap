/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:28:10 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(t_anb *stack)
{
	t_arg	*a_list;
	t_arg	*b_list;

	a_list = NULL;
	b_list = NULL;
	stack->a = a_list;
	stack->b = b_list;
}

int	ft_check_double(t_arg *tmp, long num)
{
	while (tmp)
	{
		if (num == (long)tmp->num)
			return (1);
		tmp = tmp->next;
	}
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

int	ft_check_sort(t_arg *tmp)
{
	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	ft_fill_index(t_arg *a, int count)
{
	int		ind;
	int		max;
	t_arg	*temp;
	t_arg	*minimum;

	ind = 1;
	minimum = NULL;
	while (count >= ind)
	{
		temp = a;
		max = 2147483647;
		while (temp)
		{
			if (max >= temp->num && !temp->index)
			{
				max = temp->num;
				minimum = temp;
			}
			temp = temp->next;
		}
		if (minimum)
			minimum->index = ind++;
	}
}
