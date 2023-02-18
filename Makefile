# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troudot <troudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 22:03:19 by troudot           #+#    #+#              #
#    Updated: 2023/02/08 05:32:06 by troudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETTINGS MAKEFILE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

SRCS	=		libft/ft_atoi.c 					libft/ft_lstadd_back.c			libft/ft_lstlast.c									\
				libft/ft_lstnew.c					libft/ft_split.c				libft/ft_lstsize.c									\
				libft/ft_lstadd_front.c				libft/ft_lstclear.c				libft/ft_lstdelone.c								\
				libft/ft_putstr_fd.c				libft/ft_putchar_fd.c			libft/ft_strncmp.c									\
																																		\
				libft/get_next_line_bonus.c			libft/get_next_line_utils_bonus.c													\
																																		\
				sources/parsing/parsing.c			sources/parsing/rank.c			sources/parsing/chunk.c								\
																																		\
																																		\
				sources/push_swap/push_swap.c																							\
																																		\
				sources/op/op.c						sources/op/op1.c				sources/op/op2.c									\
																																		\
																																		\
				sources/sorter/sorter_utils.c																							\
				sources/sorter/sorter_small.c	sources/sorter/sorter.c																	\


SRCS_BONUS =	libft/ft_atoi.c 					libft/ft_lstadd_back.c			libft/ft_lstlast.c									\
				libft/ft_lstnew.c					libft/ft_split.c				libft/ft_lstsize.c									\
				libft/ft_lstadd_front.c				libft/ft_lstclear.c				libft/ft_lstdelone.c								\
				libft/ft_putstr_fd.c				libft/ft_putchar_fd.c			libft/ft_strncmp.c									\
				libft/get_next_line_bonus.c			libft/get_next_line_utils_bonus.c													\
																																		\
				sources/parsing/parsing.c			sources/parsing/rank.c			sources/parsing/chunk.c								\
																																		\
																																		\
																																		\
																																		\
				sources/op/op.c						sources/op/op1.c				sources/op/op2.c									\
																																		\
																																		\
				sources/sorter/sorter_utils.c																							\
				sources/sorter/sorter_small.c	sources/sorter/sorter.c			sources/checker/checker.c								\


NAME_PRINT = 1
NAME	= push_swap
CHECKER = checker
PREFIX_NAME = PUSH SWAP

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAKEFILE CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

# Count how much files
NBR = 1
NBR_FILES= $(words $(SRCS))

#Center header
SIZE_TERM= $(shell tput cols)
SPACE_HEADER= $(shell echo $$((($(SIZE_TERM)-11)/2)))
PRINT_SPACE= $(shell printf "%$(SPACE_HEADER)s" | tr " " "-")

#Center Cleaning
HEADER_CLEANING= $(shell echo $$((($(SIZE_TERM)-9)/2)))
PRINT_CLEANING= $(shell printf "%$(HEADER_CLEANING)s" | tr " " " ")

#Center Finish
HEADER_FINISH= $(shell echo $$((($(SIZE_TERM)-7)/2)))
PRINT_FINISH= $(shell printf "%$(HEADER_FINISH)s" | tr " " " ")

#Center Progress Bar
HEADER_BAR= $(shell echo $$((($(SIZE_TERM)-$(NBR_FILES)-17)/2)))
PRINT_BAR= $(shell printf "%$(HEADER_BAR)s" | tr " " " ")

NEG = $(shell echo $$(($(NBR_FILES)-$(NBR))))

#change here char on progress bar|~~~|
TRUEE=$(shell printf "%$(NBR)s" | tr " " "\#")
FALSE=$(shell printf "%$(NEG)s" | tr " " "~")
PROGRES_BAR=[$(TRUEE)$(FALSE)][$(NAME_PRINT)

# FLAC GCC
CC =	gcc $(FLAG)
FLAG =	 -Wall -Wextra -Werror -g
OBJS =	$(SRCS:%.c=%.o)
OBJS_BONUS =	$(SRCS_BONUS:%.c=%.o)

H	= first

all: 	$(NAME)

titre:
ifeq (${H} , first)
	@echo "\033[38;5;105m\n\n$(PRINT_SPACE)[PUSH SWAP]$(PRINT_SPACE)\033[m\n"
	@H=second
endif


%.o: %.c
	@printf "\r$(PRINT_BAR)[$(NBR_FILES) Files]$(PROGRES_BAR)%%]"
	@$(CC) $< -o $@ -c -I includes/
	$(eval NBR=$(shell echo $$(($(NBR)+1))))
	$(eval NAME_PRINT=$(shell echo $$((${NBR}*100/$(NBR_FILES)))))

#Potentialy RGB PROGRESS BAR
#	$(eval COLOR=$(shell echo $$(($(COLOR)+$(shell test $(COLOR) -gt 37; echo $$?)-8*$(shell test $(COLOR) -lt 37; echo $$?)))))

$(NAME): titre $(SRCS) $(OBJS)
		@$(CC) -o push_swap $(OBJS)
		@echo "\n\n\033[38;5;084m$(PRINT_FINISH)Finish !\033[m"

$(CHECKER): titre $(SRCS_BONUS) $(OBJS_BONUS)
		@$(CC) -o checker $(OBJS_BONUS)
		@echo "\n\n\033[38;5;084m$(PRINT_FINISH)Finish !\033[m"

bonus: $(CHECKER)

clean: titre
		@rm -f $(OBJS) $(OBJS_BONUS)
		@echo "\033[38;5;084m$(PRINT_CLEANING)Cleaning !\033[m\n"

fclean:	clean
		@rm -f $(NAME)
		@rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re