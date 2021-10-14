NAME = push_swap

FILES = push_swap.c	ft_atoi.c	ft_lst_lib.c	ft_swap.c	ft_rorate.c	ft_push.c	ft_split.c	ft_utils.c	ft_sort.c	ft_sort_utils.c	ft_all_sort.c

SRSS		= push_swap.c	ft_atoi.c	ft_lst_lib.c	ft_swap.c	ft_rorate.c	ft_push.c	ft_split.c	ft_utils.c	ft_sort.c	ft_sort_utils.c	ft_all_sort.c

OBJS		= $(SRSS:.c=.o)

HEADER		= push_swap.h

CC = gcc

WWW = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
				$(CC) $(WWW) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	 clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re