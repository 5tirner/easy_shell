SRCS	= built_ins.c\
		create_args.c\
		delete_lexer.c\
		error_generate.c\
		exec.c\
		ft_calloc.c\
		ft_cmp.c\
		lexer.c\
		main.c\
		modify_list.c\
		split.c\
		work.c\

OBJS	= $(SRCS:.c=.o)

NAME	= shell

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -pedantic

RM		= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)

	$(CC) $(OBJS) -o $(NAME)

fclean:

	$(RM) $(OBJS) $(NAME)

re: fclean all