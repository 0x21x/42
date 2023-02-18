# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troudot <troudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 20:14:41 by troudot           #+#    #+#              #
#    Updated: 2023/01/22 20:14:44 by troudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_hexa.c \
		ft_putstr.c \

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETTINGS MAKEFILE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

NAME	= libftprintf.a
PREFIX_NAME = $(NAME_PRINT)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAKEFILE CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

# Count how much files
NBR = 1
NBR_FILES= $(shell find ft*.c | wc -l | tr -d " ")

#Center header
SIZE_TERM= $(shell tput cols)
SPACE_HEADER= $(shell echo $$((($(SIZE_TERM)-49)/2)))
PRINT_SPACE= $(shell printf "%$(SPACE_HEADER)s" | tr " " " ")

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
TRUEE=$(shell printf "%$(NBR)s" | tr " " "█")
FALSE=$(shell printf "%$(NEG)s" | tr " " "~")
PROGRES_BAR=$(TRUEE)$(FALSE)][$(PREFIX_NAME)

# FLAC GCC
CC =	gcc $(FLAG)
FLAG =	 -Wall -Wextra -Werror
OBJS =	$(SRCS:%.c=%.o)

H	= first

all: 	$(NAME)

titre:
ifeq (${H} , first)
	@echo "\033[38;5;105m\n\n$(PRINT_SPACE)██▓███   ██▀███   ██▓ ███▄    █ ▄▄▄█████▓  █████▒\033"
	@echo "\033[38;5;105m$(PRINT_SPACE)▓██░  ██▒▓██ ▒ ██▒▓██▒ ██ ▀█   █ ▓  ██▒ ▓▒▓██   ▒ \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)▓██░ ██▓▒▓██ ░▄█ ▒▒██▒▓██  ▀█ ██▒▒ ▓██░ ▒░▒████ ░ \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)▒██▄█▓▒ ▒▒██▀▀█▄  ░██░▓██▒  ▐▌██▒░ ▓██▓ ░ ░▓█▒  ░ \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)▒██▒ ░  ░░██▓ ▒██▒░██░▒██░   ▓██░  ▒██▒ ░ ░▒█░    \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)▒▓▒░ ░  ░░ ▒▓ ░▒▓░░▓  ░ ▒░   ▒ ▒   ▒ ░░    ▒ ░    \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)░▒ ░       ░▒ ░ ▒░ ▒ ░░ ░░   ░ ▒░    ░     ░      \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)░░         ░░   ░  ▒ ░   ░   ░ ░   ░       ░ ░    \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)            ░      ░           ░                  \n\n\033"
	@H=second
endif


%.o: %.c
	@printf "\r$(PRINT_BAR)[$(NBR_FILES) Files][$(PROGRES_BAR)%%]"
	@$(CC) $< -o $@ -c
	$(eval NBR=$(shell echo $$(($(NBR)+1))))
	$(eval NAME_PRINT=$(shell echo $$((${NBR}*100/$(NBR_FILES)))))

#Potentialy RGB PROGRESS BAR
#	$(eval COLOR=$(shell echo $$(($(COLOR)+$(shell test $(COLOR) -gt 37; echo $$?)-8*$(shell test $(COLOR) -lt 37; echo $$?)))))

$(NAME): titre $(SRCS) $(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "\n\n\033[38;5;084m$(PRINT_FINISH)Finish !\033[m"

clean: titre
		@rm -f $(OBJS)
		@echo "\033[38;5;084m$(PRINT_CLEANING)Cleaning !\033[m\n"

fclean:	clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re