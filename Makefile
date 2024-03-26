# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Vars                                                                                                        #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
include ./scrs/.env

NAME			:=	Inception
PRINT_NAME		:=	Inception
PREFIX			:=	Inception

COMPOSE_PATH		:=	./scrs/docker-compose.yml

PRINT_PREFIX	:=	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PREFIX)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m
T 				:=	1

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#				Rules					2																					#
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			 title start $(MARIADB) $(WORDPRESS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Done !\033[0m\n"

start:			title
	@-docker compose -f $(COMPOSE_PATH) up -d
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Compose has been started!\033[0m\n"

build:			title
	@-docker compose -f $(COMPOSE_PATH) build
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Compose has been built!\033[0m\n"

config:			title
	@-docker compose -f $(COMPOSE_PATH) config

down:			title
	@-docker compose -f $(COMPOSE_PATH) down
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Compose has been downing!\033[0m\n"

volumes:		title $(MARIADB) $(WORDPRESS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Volumes has been created!\033[0m\n"

stop:			title
	@-docker compose -f $(COMPOSE_PATH) stop
	@echo "$(PRINT_PREFIX)\033[0;38;5;190m Compose has been stopped!\033[0m\n"

$(NAME):		all

$(MARIADB):
	@mkdir -p $(MARIADB_VOLUME)
	@echo "$(PRINT_PREFIX) Mariadb volume has been created!"

$(WORDPRESS):
	@mkdir -p $(WORDPRESS_VOLUME)
	@echo "$(PRINT_PREFIX) Wordpress volume has been created!"

re: 			down build all

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