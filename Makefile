NAME := so_long

SRC := map_struct.c main.c errors.c path_error.c  utils.c count_01CEP.c \
	map_backtraking.c tiles_game.c map_draw.c

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
