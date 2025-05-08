NAME = cub3D
CC = gcc
MLX = mlx/libmlx.a
CFLAGS = -Wall -Wextra -Werror
SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c main.c cub3d_utils.c cub3d_utils2.c cub3d_utils3.c \
cub3d_utils4.c cub3d_utils5.c control.c error.c cub3d_utils6.c control2.c control3.c cub3d_utils7.c cub3d_utils8.c \
set_all_variable.c cub3d_utils9.c control4.c maneuver.c maneuver2.c cub3d_utils10.c cub3d_utils11.c cub3d_utils12.c 
OBJS = $(SRCS:.c=.o)

FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDES = -Isrc/gnl

all: $(NAME)

$(MLX):
	make -C mlx

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) $(MLX) -o $(NAME) $(OTHERS) $(INCLUDES)


clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re
