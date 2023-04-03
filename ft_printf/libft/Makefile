# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:27:17 by ahooghe           #+#    #+#              #
#    Updated: 2023/01/23 15:06:23 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./ft_atoi.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_putchar_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c \
		./ft_putstr_fd.c \
		./ft_split.c \
		./ft_strlcat.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcpy.c \
		./ft_strlen.c \
		./ft_strmapi.c \
		./ft_strncmp.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strtrim.c \
		./ft_substr.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_uitoa.c

SRCSB = ./ft_lstnew_bonus.c \
		./ft_lstadd_front_bonus.c \
		./ft_lstsize_bonus.c \
		./ft_lstlast_bonus.c \
		./ft_lstadd_back_bonus.c \
		./ft_lstdelone_bonus.c \
		./ft_lstclear_bonus.c \
		./ft_lstiter_bonus.c \
		./ft_lstmap_bonus.c 

OBJS	= ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

NAME	= libft.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

AR = ar rcs

RM	= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(OBJSB)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re bonus
