# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 18:40:13 by doda-cun          #+#    #+#              #
#    Updated: 2025/05/27 18:37:41 by doda-cun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I$(INC) -g
SRCDIR = src
OBJDIR = obj
INC = inc/
SRCS = $(SRCDIR)/main.c \
            $(SRCDIR)/utils.c \
            $(SRCDIR)/init.c \
            $(SRCDIR)/philo_routine.c \
            $(SRCDIR)/parsing.c \
            $(SRCDIR)/libfthelp.c\
			$(SRCDIR)/sim_mon.c\
			$(SRCDIR)/cleanup.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Build the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Clean object files
clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

# Clean everything
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Debug build
debug: CFLAGS += -g
debug: re

debug-vars:
	@echo SRCS = $(SRCS)
	@echo OBJS = $(OBJS)

.PHONY: all clean fclean re debug
