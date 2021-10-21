NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I./include -I./libft/libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

OBJECTS = $(SRC:.c=.o)

SRC = push_swap.c \

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
		ar -rcs $(NAME) $(OBJECTS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(LIBFT):
		make -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJECTS)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
