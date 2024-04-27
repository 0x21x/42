FROM alpine:3.18@sha256:11e21d7b981a59554b3f822c49f6e9f57b6068bb74f49c4cd5cc4c663c7e5160

LABEL maintainer="0x21x https://github.com/0x21x"       \
        description="Nginx Dockerfile"                  \
        alpineVersion="3.18"

RUN apk update && apk upgrade && apk add --no-cache     \
        nginx                                           \
        openssl                                         \
        && rm -rf /var/cache/apk/*

# SSL Certificate
RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=troudot"

# Web Directory
RUN mkdir -p /www
RUN mkdir -p /var/www/html

# UnRoot NGINX and Docker
RUN adduser -D -g 'www' www
RUN chown -R www:www /var/lib/nginx                     \
        && chown -R www:www /etc/nginx                  \
        && chown -R www:www /var/log/nginx              \
        && chown -R www:www /var/run/nginx              \
        && chown -R www:www /var/www/html               \
        && chown -R www:www /www
USER www

ADD ./requirements/nginx/conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]