
NAME = fractol

MLX_LIB = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRCS = burningship.c	\
	   event_handler.c	\
	   julia.c			\
	   mandelbrot.c		\
	   move.c			\
	   multibrot.c		\
	   threads.c		\
	   utils.c			\
	   color.c			\
	   init.c			\
	   main.c			\
	   manipualtion.c	\
	   movingship.c		\
	   multijulia.c		\
	   usage.c

FILES = $(addprefix srcs/, $(SRCS))

OBJ = $(FILES:.c=.o)

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(FLAGS) $(MLX_LIB) $(LIB) $(OBJ) -o $@

$(OBJ): %.o : %.c
	gcc $(FLAGS) -c $< -o $@

$(LIB):
	make -C libft
clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

man:
	man /usr/share/man/man3/mlx.1

re: fclean $(NAME)
