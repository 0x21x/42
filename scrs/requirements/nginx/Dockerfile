FROM debian:buster
EXPOSE 443/tcp

# Update and Upgrade
RUN apt update -y && apt upgrade -y

# Install Nginx and OpenSSL
RUN apt install nginx -y && apt install openssl -y

# SSL Certificate
RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=troudot"

# Nginx Configuration
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Setting environment variables
ENV HOSTNAME=${HOSTNAME}

# Default Configuration
# RUN chmod 755 /var/www/html
# RUN chown -R www-data:www-data /var/www/html

CMD ["nginx", "-g", "daemon off;"]
