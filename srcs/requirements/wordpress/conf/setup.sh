#!/bin/sh

if [ -f ./wp-config.php ]; then
    echo "WordPress is already installed";
else
    wp core download --locale=en_US --allow-root;

    wp config create                        \
        --dbname=$MYSQL_DATABASE            \
        --dbuser=$MYSQL_USER                \
        --dbpass=$MYSQL_PASSWORD            \
        --dbhost=mariadb                    \
        --dbcharset="utf8"                  \
        --dbcollate="utf8_general_ci"       \
        --skip-check                        \
        --allow-root;

    wp core install                         \
        --url=$HOSTNAME                     \
        --title="worpress"                  \
        --admin_user=$WP_ROOT_USER          \
        --admin_password=$WP_ROOT_PASSWORD  \
        --admin_email=$WP_ROOT_MAIL         \
        --skip-email                        \
        --allow-root;

    wp theme activate twentytwentythree --allow-root;

    wp user create $WP_USER $WP_USER_MAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root;

fi;

echo "Starting WordPress...";
exec "$@"