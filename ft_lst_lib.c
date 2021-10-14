/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:15:46 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*ft_lstnew(int num, int index)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (new)
	{
		new->num = num;
		new->index = index;
		new->place = 0;
		new->next = NULL;
		new->back = NULL;
	}
	return (new);
}

void	ft_lstadd_back(t_arg **lst, t_arg *num)
{
	t_arg	*temp;

	temp = *lst;
	if (!*lst)
		*lst = num;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (temp && num)
	{
		temp->next = num;
		num->back = temp;
	}
}

int	ft_lstsize(t_arg *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
