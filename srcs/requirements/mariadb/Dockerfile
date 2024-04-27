FROM alpine:3.18@sha256:11e21d7b981a59554b3f822c49f6e9f57b6068bb74f49c4cd5cc4c663c7e5160

LABEL maintainer="0x21x https://github.com/0x21x"       \
        description="MariaDB Dockerfile"                \
        alpineVersion="3.18"

RUN apk update && apk upgrade && apk add --no-cache     \
        mariadb                                         \
        mariadb-client                                  \
        mariadb-server-utils                            \
        && rm -rf /var/cache/apk/*

# Add configuration files
ADD conf/my.cnf /etc/my.cnf
ADD conf/run.sh /scripts/run.sh
RUN chmod +x /scripts/run.sh

VOLUME ["/var/lib/mysql"]

ENTRYPOINT ["/scripts/run.sh"]

EXPOSE 3306

CMD [                                   \
    "/usr/bin/mysqld",                  \
    "--user=mysql",                     \
    "--console",                        \
    "--silent-startup",                 \
    "--skip-networking=0",              \
    "--lower_case_table_names=2"        \
]