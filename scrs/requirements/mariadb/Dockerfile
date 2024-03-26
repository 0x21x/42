FROM alpine:3.18@sha256:11e21d7b981a59554b3f822c49f6e9f57b6068bb74f49c4cd5cc4c663c7e5160

LABEL maintainer="0x21x https://github.com/0x21x"       \
        description="MariaDB Dockerfile"                \
        alpineVersion="3.18"

RUN apk update && apk upgrade && apk add --no-cache     \
        mariadb                                         \
        mariadb-client                                  \
        mariadb-server-utils                            \
        && rm -rf /var/cache/apk/*

ADD conf/run.sh /scripts/run.sh
RUN mkdir /docker-entrypoint-initdb.d && \
    mkdir /scripts/pre-exec.d && \
    mkdir /scripts/pre-init.d && \
    chmod -R 755 /scripts

EXPOSE 3306

ENTRYPOINT ["/scripts/run.sh"]