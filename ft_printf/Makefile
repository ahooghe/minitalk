# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:14:40 by ahooghe           #+#    #+#              #
#    Updated: 2023/04/05 18:26:39 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
TARGET_TYPE = lib
NAME = libftprintf.a

# Directories
OBJDIR = obj
SRCDIRS = src
LIBDIRS = libft

# Default value overrides
override CFLAGS += -Wall -Werror -Wextra
override LDFLAGS +=

# Compiler and linker options
CC = gcc
AR = ar
CFLAGS =
LDFLAGS =
ARFLAGS = rcs

# Colors
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=	\033[0;31m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]
# Library sources and objects
# Define the library directories, library source files and library object files
LIBSOURCES = $(foreach DIR,$(LIBDIRS),$(wildcard $(DIR)/*.c))
LIBOBJECTS = $(patsubst %.c,$(OBJDIR)/$(dir %)%.o,$(LIBSOURCES))

# Program sources and objects
# Define the source directories, program source files and object files
SOURCES = $(foreach DIR,$(SRCDIRS),$(wildcard $(DIR)/*.c))
OBJECTS = $(patsubst %.c,$(OBJDIR)/$(dir %)%.o,$(SOURCES))

# Targets
.PHONY: all clean fclean re

# If TARGET_TYPE is set to "exe", build an executable
# If TARGET_TYPE is set to "lib", build a library archive file
# Otherwise, print an error and exit
all: $(OBJECTS) $(LIBOBJECTS)
	@echo "$(GREEN)Object files generated.$(RESET)"

ifeq ($(TARGET_TYPE),exe)
	$(NAME) $(LIBOBJECTS) $(OBJECTS)
		$(CC) $(CFLAGS) $(LIBOBJECTS) $(OBJECTS) -o $(NAME)
			@echo "$(GREEN)Executable file $(YELLOW)'$(NAME)'$(GREEN) created.\n\n$(RESET)"
else ifeq ($(TARGET_TYPE),lib)
	$(if $(findstring .a,$(NAME)),,$(eval NAME := $(NAME).a))
		$(AR) $(ARFLAGS) $(NAME) $(LIBOBJECTS) $(OBJECTS)
		@echo "$(GREEN)Archive file $(YELLOW)'$(NAME)'$(GREEN) created.\n\n$(RESET)"
else
	@echo "$(RED)TARGET_TYPE not set correctly. Set TARGET_TYPE=exe or TARGET_TYPE=lib to build an executable or library respectively$(RESET)"
endif

# Generate output file names based on the source file's directory structure
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $(OBJDIR)/$*)
	@echo "$(GREEN)Generating object files...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1

# Create the obj directory if it does not exist
$(OBJDIR): 
	mkdir -p $(OBJDIR)

# Clean up object files and the obj directory
clean:
	rm -rf $(OBJDIR)/*
	@echo "$(_INFO) $(NAME)'s object files have been deleted."

# Remove the executable, object files and the obj directory
fclean: clean
	rm -f $(NAME)
	@echo "$(_INFO) $(NAME) has been deleted."

# Rebuild everything
re: fclean all


.SILENT: all clean fclean re
