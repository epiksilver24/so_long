NAME := so_long

SRC := src/map_struct.c src/main.c src/errors.c src/path_error.c  src/utils.c src/count_01CEP.c \
	src/map_backtraking.c src/tiles_game.c src/map_draw.c src/exit_game.c \

INCLUDE		=	-I.

LIBFT_DIR = libft

CC := cc

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
