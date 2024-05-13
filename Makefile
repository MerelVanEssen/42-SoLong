SRC 		=	./src/
LIB_DIR		=	./libft/
LIBX_DIR	=	./minilibx-linux/

LIBFT		=	$(LIB_DIR)libft.a
HEADER		=	$(SRC)so_long.h
MLX			=	$(LIBX_DIR)Makefile.gen

INCLUDES	=	-Iminilibx-linux
LIB			=	-Lminilibx-linux -lmlx_Linux -lX11 -lXext $(LIBFT)

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

OBJ			=	$(CFILES:.c=.o)

CFILES 		=	$(SRC)so_long.c \
				$(SRC)prepare_map.c \
				$(SRC)valid_map_1.c \
				$(SRC)valid_map_2.c \
				$(SRC)finish.c \
				$(SRC)get_images.c \
				$(SRC)images_to_window.c \
				$(SRC)get_key.c \
				$(SRC)directions.c \
				$(SRC)skull.c \
				$(SRC)move_skulls.c

all :		$(NAME)

$(NAME): 	$(OBJ)
			make -C $(LIB_DIR)
			make -C $(LIBX_DIR)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)		

$(OBJ):	%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re : 		fclean all

.PHONY:		all clean fclean re
