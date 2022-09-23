NAME				:= get_next_line.a

CC					:= gcc
CFLAGS				:= -Wall -Wextra -Werror
RM					:= rm -rf

HEADER				:= get_next_line.h

SRCS				:=	get_next_line.c get_next_line_utils.c

OBJS				:= ${SRCS:.c=.o}

all :	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:		all clean fclean re