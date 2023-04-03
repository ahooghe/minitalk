# Binary Name:
NAME	=
CLIENT	=	client
SERVER	=	server

#ft_printf Variables:
LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

#minitalk variables
SRC_C	=	src/main_client.c
SRC_S	=	src/main_server.c
OBJ_S	=	src/main_server.o
OBJ_C	=	src/main_client.o
INC		=	ft_minitalk.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S)
	@$(CC) $(CFLAGS) -I $(INC) $(OBJ_S) $(LIBFTPRINTF) -o server
	@echo "$(_SUCCESS) server ready."

$(CLIENT): $(OBJ_C)
	@$(CC) $(CFLAGS) -I $(INC) $(OBJ_C) $(LIBFTPRINTF) -o client
	@echo "$(_SUCCESS) client ready."

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -s -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -s -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@echo "$(_INFO) object files removed."

fclean:
	@ $(MAKE) fclean -s -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER) $(OBJ_C) $(OBJ_S)
	@echo "$(_INFO) object files removed."
	@echo "$(_INFO) client removed."
	@echo "$(_INFO) server removed."

re: fclean all

.PHONY: all clean fclean re
