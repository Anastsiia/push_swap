/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:33:24 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:28:27 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	long		num;
	t_anb		stack;
	t_arg		*tmp;
	int			i;

	i = 0;
	ft_create_stack(&stack);
	while (argv[++i] && argc > 1)
	{
		num = ft_atoi(argv[i]);
		tmp = ft_lstnew((int)num, 0);
		if (!tmp || ft_check_double(stack.a, num))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		ft_lstadd_back(&stack.a, tmp);
	}
	if (ft_check_sort(stack.a))
		ft_sort_stack(&stack);
}
