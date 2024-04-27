include ./srcs/.env

WORDPRESS	:=	$(WORDPRESS_VOLUME)
MARIADB		:=	$(MARIADB_VOLUME)

build: $(WORDPRESS) $(MARIADB)
	@-docker compose -f ./srcs/docker-compose.yml build

up: build
	@-docker compose -f ./srcs/docker-compose.yml up -d

down:
	@-docker compose -f ./srcs/docker-compose.yml down

clean:
	@-docker compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@rm -rf $(VOLUME)

logs:
	@-docker compose -f ./srcs/docker-compose.yml logs -f

$(WORDPRESS):
	@mkdir -p $(WORDPRESS)

$(MARIADB):
	@mkdir -p $(MARIADB)

.PHONY: build up down clean logs host