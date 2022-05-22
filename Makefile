NAME =	pipex

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   mandatory/InitArgs.c	\
		mandatory/pipex.c	\
		mandatory/main.c	\


INC = 	-I libft/libft.h 	\
		-I mandatory/pipex.h	\

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} ./libft/libft.a -o ${NAME}


all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)