NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c mandelbrot.c julia.c utils1.c utils2.c burningship.c

OBJ = $(SRC:.c=.o)

MLX_FLAGS = -L/home/yel-guad/Downloads/minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX_FLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
