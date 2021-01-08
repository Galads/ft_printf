# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brice <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 04:22:21 by brice             #+#    #+#              #
#    Updated: 2021/01/07 15:33:15 by brice            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

LIBFTDIR	= ./libft/

PARSERDIR	= ./parser/

INCLUDES	= ./include/

PROCDIR 	= ./processor/

HELPDIR		=./helper/

LIBFT		= libft.a

SRCS		= ft_printf.c $(PARSERDIR)ft_itoa_base_ull.c $(PARSERDIR)ft_itoa_base_xu.c  \
						  $(PARSERDIR)ft_parser.c  $(PARSERDIR)ft_struct_init.c \
						  $(PROCDIR)ft_print_char.c $(PROCDIR)ft_print_char.c \
						  $(PROCDIR)ft_print_d.c   $(PROCDIR)ft_print_p.c \
						  $(PROCDIR)ft_print_percent.c $(PROCDIR)ft_print_string.c \
						  $(PROCDIR)ft_print_u.c \
						  \
						  $(HELPDIR)ft_helper_prints.c \
						  \
						  $(HELPDIR)ft_helper_check_u.c $(HELPDIR)ft_check_minus_helper.c \
						  $(HELPDIR)ft_while_print_null_helper.c \
						  \
						  $(HELPDIR)ft_print_helpers_str.c


OBJS		= $(SRCS:.c=.o)

GREEN		= \033[0;32m

RED			= \033[0;31m

RESET		= \033[0m

%.o:	%.c
			@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "$(GREEN)|.........Compilation.........|$(RESET)"
			@make -C $(LIBFTDIR)
			@cp  $(LIBFTDIR)$(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all:		$(NAME)

clean:
			@make -C $(LIBFTDIR) clean
			@rm -rf $(OBJS)
			@echo "$(LIBFT): $(RED)object files were deleted$(RESET)"
			@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:		clean
			@make -C $(LIBFTDIR) fclean
			@echo "$(LIBFT): $(RED)$(LIBFT) was deleted$(RESET)"
			@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
			@rm -rf $(NAME) $(LIBFT)

re:			fclean all
