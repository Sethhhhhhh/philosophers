NAME		=	philo

HEADER		=	./includes/

CC			=	gcc 

CFLAGS		=	-g

LIBS		=	-lpthread
 
SRCS		=	srcs/main.c \
				srcs/s_error.c \
				srcs/init.c \
				srcs/utils/s_putstr_fd.c \
				srcs/utils/s_putchar_fd.c \
				srcs/utils/s_atoi.c \
				srcs/utils/s_bzero.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $(NAME) $(LIBS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm $(NAME)

re			:	fclean all
