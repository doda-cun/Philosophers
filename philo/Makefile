# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 18:40:13 by doda-cun          #+#    #+#              #
#    Updated: 2025/05/29 15:45:52 by doda-cun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I$(INC) -g.
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

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)


fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

debug-vars:
	@echo SRCS = $(SRCS)
	@echo OBJS = $(OBJS)

.PHONY: all clean fclean re debug
