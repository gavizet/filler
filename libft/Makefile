# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavizet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/16 21:13:36 by gavizet           #+#    #+#              #
#    Updated: 2017/01/15 12:08:26 by gavizet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS ###
NOC			= \033[0m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

### LIBFT ###
NAME 	= libft.a

### COMPILATION ###
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -c -o

## SOURCES ###
SRCS	= ft_memalloc.c		\
		  ft_putendl_fd.c	\
		  ft_strequ.c		\
		  ft_strnew.c		\
		  ft_memccpy.c		\
		  ft_putnbr.c		\
		  ft_striter.c		\
		  ft_strnstr.c		\
		  ft_memchr.c		\
		  ft_putnbr_fd.c	\
		  ft_striteri.c		\
		  ft_strrchr.c		\
		  ft_atoi.c			\
		  ft_memcmp.c		\
		  ft_putstr.c		\
		  ft_strjoin.c		\
		  ft_strrev.c		\
		  ft_bzero.c		\
		  ft_memcpy.c		\
		  ft_putstr_fd.c	\
		  ft_strlcat.c		\
		  ft_strsplit.c		\
		  ft_memdel.c		\
		  ft_strcat.c		\
		  ft_strlen.c		\
		  ft_strstr.c		\
		  ft_isalnum.c		\
		  ft_memmove.c		\
		  ft_strchr.c		\
		  ft_strmap.c		\
		  ft_strsub.c		\
		  ft_isalpha.c		\
		  ft_memset.c		\
		  ft_strclr.c		\
		  ft_strmapi.c		\
		  ft_strtrim.c		\
		  ft_isascii.c		\
		  ft_strcmp.c		\
		  ft_strncat.c		\
		  ft_tolower.c		\
		  ft_isdigit.c		\
		  ft_putchar.c		\
		  ft_strcpy.c		\
		  ft_strncmp.c		\
		  ft_toupper.c		\
		  ft_isprint.c		\
		  ft_putchar_fd.c	\
		  ft_strdel.c		\
		  ft_strncpy.c		\
		  ft_itoa.c			\
		  ft_putendl.c		\
		  ft_strdup.c		\
		  ft_strnequ.c		\
		  ft_lstdel.c		\
		  ft_lstdelone.c	\
		  ft_lstiter.c		\
		  ft_lstmap.c		\
		  ft_lstnew.c		\
		  ft_lstadd.c		\
		  ft_lstaddback.c	\
		  ft_sqrt.c			\
		  ft_rec_fac.c		\
		  ft_islower.c		\
		  ft_isupper.c		\
		  ft_match.c		\
		  ft_abs.c			\
		  ft_pow.c			\
		  get_next_line.c

### OBJECTS ###
OBJS	= $(SRCS:%.c=%.o)


### RULES ###
all : $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]"

$(NAME) : $(OBJS)
	@echo "$(YELLOW)Creating library [$(NAME)] from object files..."
	@ar rc $(NAME) $(OBJS)			
	@ranlib $(NAME)
	@echo "$(GREEN)[$(NAME)] was successfully created"

clean:
	@echo "$(YELLOW)Deleting object files from [Project : Libft]..."
	@/bin/rm -rf $(OBJS)
	@echo "$(GREEN)Object files were successfully deleted from [Project : Libft]."


fclean:
	@echo "$(YELLOW)Deleting object files from [Project : Libft]..."
	@/bin/rm -rf $(OBJS)
	@echo "$(GREEN)Object files were successfully deleted from [Project : Libft]."
	@echo "$(YELLOW)Deleting library [$(NAME)] from [Project : Libft]..."
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)Library [$(NAME)] was successfully deleted from [Project : Libft].$(NOC)"

re:		fclean all
