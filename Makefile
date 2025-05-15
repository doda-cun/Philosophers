# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 18:40:13 by doda-cun          #+#    #+#              #
#    Updated: 2025/05/15 18:47:56 by doda-cun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCDIR = src
OBJDIR = obj
SRCS = $(SRCDIR)/main.c \
			$(SRCDIR)/utils.c\
			$(SRCDIR)/init.c \
			$(SRCDIR)/philo_routine.c\
			$(SRCDIR)/parsing.c\
			$(SRCDIR)/libfthelp.c\
OBJS = $(SRCS:.c=.o)

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

.PHONY: all clean fclean re debug
