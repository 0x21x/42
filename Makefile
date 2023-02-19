# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Vars                                                                                                        #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

NAME			=	fract-ol
PRINT_NAME		=	fract-ol

CC 				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

INCLUDES_DIR	=	./includes/
SOURCES_DIR		=	./sources/

LIBMLX_DIR		=	./MLX42
LIBMLX			=	$(LIBFT_DIR)libmlx42.a
MLX				=	-L MLX42 -lmlx -I MLX42/Include -framework OpenGL -framework AppKit
# -L MLX42 -lmlx -I MLX42/Include -framework OpenGL -framework AppKit

MATH			=	-lm

PRINT_PREFIX	=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m
T 				=	1

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Files																										#
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

SRCS			=	main.c						render.c				hook.c						help.c					\
					utils.c																									\
																															\
					factals/mandelbrot.c		factals/julia.c			factals/burningship.c								\
																															\
					libft/strcmp_lower.c		libft/ft_atof.c			libft/ft_bzero.c			libft/ft_putstr_fd.c	\

SRCS_MLX		=	

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Rules					2																					#
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			 title $(LIBMLX) $(NAME)
	@:
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

$(NAME):
	@$(foreach s,$(SRCS),echo "$(PRINT_PREFIX) Compiling \033[0;33m$(s)\033[0m";)
	@$(CC) $(CFLAGS) $(addprefix $(SOURCES_DIR), $(SRCS)) -I $(INCLUDES_DIR) $(MLX) $(MATH) -o $(NAME)

$(LIBMLX):
	@echo "$(PRINT_PREFIX) Compiling \033[0;33mMLX\033[0m"
	@make -C $(LIBMLX_DIR) &>/dev/null
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

clean:			title
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@$(MAKE) clean -C $(LIBMLX_DIR) &>/dev/null

fclean:			clean
	@rm -f $(NAME)

re: 			fclean all

bonus:			all

.PHONY:			all

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Style                                                                                                       #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

title:
ifeq ($(T), 1)
	$(call title,$(PRINT_NAME))
	@T=0
endif

define title
	@echo "\033[38;5;240m━━━━━━━━━━━━━━━━━━━━━━\033[0m $(1) \033[38;5;240m━━━━━━━━━━━━━━━━━━━━━━\033[0m\n";
endef