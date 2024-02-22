# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audreyer <audreyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 01:52:00 by audreyer          #+#    #+#              #
#    Updated: 2022/08/08 15:54:43 by audreyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -g -Wall -Werror -Wextra -MMD

RM = rm -rf

INC = include/libft.h

-include ${DOBJ}

.c.o:
			$(CC) $(FLAGS) -I include -c $< -o $(<:.c=.o)

AR = ar -crs

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR),$(FILE))

FILE =	ft_atoi.c \
		ft_splitint.c \
		ft_exit.c \
		ft_abs.c \
		ft_posprint.c \
		ft_freevaria.c \
		ft_setpos.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_posclear.c \
		ft_lstrange.c \
		ft_lstmin.c \
		ft_lstmax.c \
		ft_lstmedian.c \
		get_next_line.c \
		ft_strstr.c \
		get_next_line_utils.c \
		ft_setintzerovaria.c \
		ft_unsplit.c \
		ft_malloc.c \
		ft_mallocint.c \
		ft_lstiter.c 

OBJ = $(SRC:.c=.o)

DOBJ		=	${SRC:.c=.d}

$(NAME):	$(OBJ) $(INC)
		$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
		${RM} $(OBJ) ${DOBJ} ${OBJB} ${DOBJB}

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re .c.o
