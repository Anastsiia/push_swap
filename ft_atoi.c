/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:15:07 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		min;
	long	res;

	min = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = -min;
		str++;
	}
	if (*str < 48 || *str > 57)
		res = -21474836488;
	while (*str)
	{
		if (res > 2147483647 || res < -2147483648
			|| !(*str >= '0' && *str <= '9'))
		{
			res = -21474836488;
			break ;
		}
		res = (res * 10) + (((*str++) - 48) * min);
	}
	return (res);
}
