# **************************************************************************** #
# VARIABLES

NAME		:= so_long

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
INCS		:= -I ./inc/
HEADER		:= ./inc/so_long.h

MLX_DIR		:= mlx
MLX_A		:= ./mlx/libmlx.a

SRC_DIR		:= ./src/
OBJ_DIR		:= ./obj/

FT_PRINTF_DIR		:= printf
FT_PRINTF_A			:= ./printf/ft_printf.a

GET_NEXT_LINE_DIR	:= get_next_line
GET_NEXT_LINE_A		:= ./get_next_line/get_next_line.a

# **************************************************************************** #
# SOURCES

SRC_FILES	:= so_long.c

OBJ_FILES	:= ${SRC_FILES:.c=.o}
SRC			:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# **************************************************************************** #
# RULES

all :	$(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	make -C $(FT_PRINTF_DIR)
	make -C $(GET_NEXT_LINE_DIR)
	$(CC) $(OBJ) $(MLX_A) -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)
	make clean -C $(MLX_DIR)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all
	echo "Cleaned all and rebuild $(NAME)!"

.PHONY:		all clean fclean re
