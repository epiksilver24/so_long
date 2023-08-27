NAME := so_long

SRC := src/path_map/map_struct.c src/main.c src/errors/errors.c \
   	src/path_map/path_error.c    \
	src/path_map/map_backtraking.c  src/grafics/map_draw.c  \
	src/controls/controlls.c src/path_map/ft_map_path.c \
	src/grafics/ft_start_mlx.c
# src/path_map/tiles_game.c
INCLUDE		=	-I.

LIBFT_DIR = libft

CC := cc 
#-g -fsanitize=address

OBJS		=	$(patsubst %.c,%.o,$(SRC))
OBJSR = $(SRC:.c=.o)

CFLAGS := -Wall -Werror -Wextra 

all: ${NAME}  ${callforlib}
	
%.o:%.c Makefile
	make -C $(LIBFT_DIR)
	make -C mlx
	@$(CC) -g $(CFLAGS) $(INCLUDE) -c $< -o $@ 

${NAME}: ${OBJSR} | ${callforlib}
	${CC} -g ${CFLAGS}   -o ${NAME} ${OBJSR} libft/libft.a mlx/libmlx.a  -Lmlx -lmlx -framework OpenGL -framework AppKit

callforlib:
	${MAKE} -C libft/

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C mlx clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 
	rm -f $(NAME).a
	

re: fclean ${NAME}

.PHONY: all clean fclean re 


#	make -C mlx/
