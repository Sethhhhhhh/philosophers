NAME		=	philo

HEADER		=	./includes/philo.h

CC			=	gcc 

CFLAGS		=	-g

LIBS		=	-lpthread
 
SRCS		=	srcs/main.c \
				srcs/print.c \
				srcs/init.c \
				srcs/tasks.c \
				srcs/event.c \
				srcs/utils/s_putstr_fd.c \
				srcs/utils/s_putchar_fd.c \
				srcs/utils/s_putnbr_fd.c \
				srcs/utils/s_atoi.c \
				srcs/utils/s_bzero.c \
				srcs/utils/s_strlen.c \
				srcs/utils/get_time.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $(NAME) $(LIBS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm $(NAME)

re			:	fclean all
