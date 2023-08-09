NAME := so_long

SRC := map_struct.c main.c \

INCLUDE		=	-I.

LIBFT_DIR = libft

CC := cc

OBJS		=	$(patsubst %.c,%.o,$(SRC))
OBJSR = $(SRC:.c=.o)

CFLAGS := -Wall -Werror -Wextra 

all: ${NAME}  ${callforlib}
	
%.o:%.c Makefile
	make -C $(LIBFT_DIR)
	@$(CC) -g $(CFLAGS) $(INCLUDE) -c $< -o $@ 

${NAME}: ${OBJSR} | ${callforlib}
	${CC} -g ${CFLAGS}   -o ${NAME} ${OBJSR} libft/libft.a

callforlib:
	${MAKE} -C libft/

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 
	rm -f $(NAME).a
	

re: fclean ${NAME}

.PHONY: all clean fclean re 


#	make -C mlx/
