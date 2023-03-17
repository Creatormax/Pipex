NAME	=	pipex

SRCS	=	src/pipex.c \
			

FLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address -O0

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	./inc/libft/libft.a

CC		=	gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCL) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./inc/libft/
	
clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"	
	@make fclean -C ./inc/libft/

fclean: clean
	@rm -rf $(NAME)

re: fclean all

