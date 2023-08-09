# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scespede <scespede@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 13:00:41 by scespede          #+#    #+#              #
#    Updated: 2023/08/08 16:50:36 by scespede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJECTS = ft_strchr.o  ft_toupper.o ft_isalpha.o ft_isdigit.o \
	ft_strlen.o ft_tolower.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	ft_strlcpy.o ft_strrchr.o ft_strlcat.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putnbr_fd.o ft_putendl_fd.o ft_strncmp.o ft_atoi.o ft_bzero.o \
	ft_memset.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	ft_strnstr.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o \
	ft_strtrim.o ft_itoa.o ft_strmapi.o ft_split.o ft_striteri.o \
	ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o \
	ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o  \
	ft_lstiter_bonus.o ft_lstmap_bonus.o get_next_line.o get_next_line_utils.o 	
CFLAGS = -Wall -Werror -Wextra -I

INC = ../includes/

LIBRAR = ar rc




all: ${NAME} 

${NAME}: ${OBJECTS}
		 ${LIBRAR} ${NAME} ${OBJECTS}

%.o : %.c ${HEADERS} Makefile
		cc -c ${CFLAGS} ${INC} $< -o $@

fclean: clean	
	rm -f ${NAME}

clean:
	rm -f ${OBJECTS}
	
re: fclean ${NAME}

.PHONY: all clean fclean re bonus 

