FROM alpine:3.18@sha256:11e21d7b981a59554b3f822c49f6e9f57b6068bb74f49c4cd5cc4c663c7e5160

LABEL maintainer="0x21x https://github.com/0x21x"           \
        description="Wordpress Dockerfile"                  \
        alpineVersion="3.18"

RUN apk update && apk upgrade && apk add --no-cache         \
    curl                                                    \
    php81                                                   \
    php81-fpm                                               \
    php81-mysqli                                            \
    php81-phar                                              \
    php81-gd                                                \
    php81-curl                                              \
    php81-openssl                                           \
    php81-mbstring                                          \
    php81-xml                                               \
    php81-zip                                               \
    php81-json                                              \
    php81-iconv                                             \
    php81-posix                                             \
    && rm -rf /var/cache/apk/*

RUN mkdir -p /var/www/html
RUN adduser -u 82 -D -S -G www-data www-data
RUN chown www-data:www-data /var/www/html
RUN chmod 777 /var/www/html

RUN curl -L -o /usr/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x /usr/bin/wp

ADD conf/php.conf /etc/php81/php-fpm.d/www.conf
RUN	adduser -S www && addgroup -S www

ADD conf/setup.sh /scripts/run.sh
RUN chmod +x /scripts/run.sh
ENTRYPOINT ["/scripts/run.sh"]

WORKDIR /var/www/html/

EXPOSE 9000

CMD ["/usr/sbin/php-fpm81", "--nodaemonize"]