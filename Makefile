SRCS	=	./src/main.c ./src/exit/exit.c ./src/utility/optparser.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	container

RM		=	rm -rf

.c.o:
			$(CC) -c $< -o $(<:.c=.o) -I./include

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re