#include "push_swap.h"

static void	ft_push(t_arg **target, t_arg **source)
{
	t_arg	*tmp;

	tmp = *source;
	if ((*source)->next)
		(*source)->next->back = NULL;
	*source = (*source)->next;
	if (*target)
		(*target)->back = tmp;
	tmp->next = *target;
	*target = tmp;
}

void	ft_p(t_anb *stack, char c)
{
	if (c == 'a' && stack->b)
	{
		ft_push(&stack->a, &stack->b);
		write(1, "pa\n", 3);
	}
	else if (c == 'b' && stack->a)
	{
		ft_push(&stack->b, &stack->a);
		write(1, "pb\n", 3);
	}
}
