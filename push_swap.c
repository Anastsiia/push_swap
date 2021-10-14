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
