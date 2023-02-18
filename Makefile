# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troudot <troudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 03:09:47 by troudot           #+#    #+#              #
#    Updated: 2022/12/16 07:16:16 by troudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

SRCS	=   ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	\
			ft_bzero.c		ft_strlen.c 	ft_memset.c		ft_memcpy.c		ft_memmove.c	\
			ft_toupper.c	ft_tolower.c	ft_strlcpy.c	ft_strlcat.c	ft_strchr.c		\
			ft_strrchr.c	ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	\
			ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		ft_strjoin.c	\
			ft_strtrim.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putnbr_fd.c	ft_putendl_fd.c	\
			ft_itoa.c		ft_striteri.c	ft_strmapi.c	ft_split.c

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BONUS FILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

SRCS_BONUS = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstiter.c\
			 ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstmap.c

# Count how much files
NBR = 1
NBR_FILES= $(shell find ft*.c | wc -l | tr -d " ")

#Center header
SIZE_TERM= $(shell tput cols)
SPACE_HEADER= $(shell echo $$((($(SIZE_TERM)-36)/2)))
PRINT_SPACE= $(shell printf "%$(SPACE_HEADER)s" | tr " " " ")

#Center Cleaning
HEADER_CLEANING= $(shell echo $$((($(SIZE_TERM)-8)/2)))
PRINT_CLEANING= $(shell printf "%$(HEADER_CLEANING)s" | tr " " " ")

#RGB colors
COLOR = 29
MAX_COLOR = 37

#Re-Print multiple line
REMOVE_BACK=$(shell tput cuu1)
REMOVE_LINE=$(shell tput el)

#Clear screen
CLEAR_SCREEN=$(shell tput clear)

NAME	= libft.a
PREFIX_NAME = $(NAME_PRINT)
NEG = $(shell echo $$(($(NBR_FILES)-$(NBR))))

TRUEE=$(shell printf "%$(NBR)s" | tr " " "\#")
FALSE=$(shell printf "%$(NEG)s" | tr " " "~")
PROGRES_BAR=$(TRUEE)$(FALSE)]	[$(PREFIX_NAME)

CC =	gcc $(FLAG)
FLAG =	 -Wall -Wextra -Werror
OBJS =	$(SRCS:%.c=%.o)
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

H	= first

all: 	$(NAME)

titre:
ifeq (${H} , first)
	@echo "\033[38;5;105m\n\n$(PRINT_SPACE)██╗     ██╗██████╗ ███████╗████████╗\033"
	@echo "\033[38;5;105m$(PRINT_SPACE)██║     ██║██╔══██╗██╔════╝╚══██╔══╝\033"
	@echo "\033[38;5;105m$(PRINT_SPACE)██║     ██║██████╔╝█████╗     ██║   \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)██║     ██║██╔══██╗██╔══╝     ██║   \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)███████╗██║██████╔╝██║        ██║   \033"
	@echo "\033[38;5;105m$(PRINT_SPACE)╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝   \n\n\033"
	@H=second
endif


%.o: %.c
	@printf "\r[$(PROGRES_BAR)%%]"
	@$(CC) $< -o $@ -c
	$(eval NBR=$(shell echo $$(($(NBR)+1))))
	$(eval NAME_PRINT=$(shell echo $$((${NBR}*100/$(NBR_FILES)))))
	$(eval COLOR=$(shell echo $$(($(COLOR)+$(shell test $(COLOR) -gt 37; echo $$?)-8*$(shell test $(COLOR) -lt 37; echo $$?)))))

$(NAME): titre $(SRCS) $(OBJS) bonus
		@ar rcs $(NAME) $(OBJS)
		@printf "\n$(PRINT_CLEANING)Finist !\n"

$(OBJS_BONUS): %.o: %.c
		@printf "\r[$(PROGRES_BAR)%%]"
		@$(CC) $< -o $@ -c
		$(eval NBR=$(shell echo $$(($(NBR)+1))))
		$(eval NAME_PRINT=$(shell echo $$((${NBR}*100/($(NBR_FILES))))))

bonus: $(OBJS_BONUS)
		@ar rcs $(NAME) $(OBJS_BONUS)

clean: titre
		@rm -f $(OBJS) $(OBJS_BONUS)
		@printf "\033\n$(PRINT_CLEANING)Cleaning !\n"

fclean:	clean
		@rm -f $(NAME) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean re