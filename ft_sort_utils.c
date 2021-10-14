#include "push_swap.h"

int	ft_add_place(int *place, t_arg *temp, int index)
{
	int	count;

	count = 0;
	*place = temp->place;
	while (temp && temp->place == *place && temp->index >= index)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	ft_find(t_anb *stack, t_arg *temp, int index)
{
	int	begin;
	int	last;

	last = 0;
	begin = 0;
	while (temp->next && index != temp->index && index + 1 != temp->index)
	{
		begin++;
		temp = temp->next;
	}
	while (temp->back && index != temp->index && index + 1 != temp->index)
	{
		last++;
		temp = temp->back;
	}
	if (last < begin)
		ft_rr(stack, 'b');
	else
		ft_r(stack, 'b');
}
