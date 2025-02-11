
# Descarga Docker

[https://docs.docker.com/get-started/get-docker/](https://docs.docker.com/get-started/get-docker/)

# Crea un archivo Dockerfile

Crealo en el lugar donde quieras que empieza tu home en Linux (bash).

```
FROM ubuntu:latest

# Instala las herramientas necesarias: Bash, GCC, Vim, Fish, Git, ping y curl
RUN apt update && apt install -y \
    bash \
    gcc \
    vim \
    fish \
    git \
    iputils-ping \
    curl \
 && rm -rf /var/lib/apt/lists/*

# Establece Fish como el shell predeterminado
RUN chsh -s /usr/bin/fish

# Configura el punto de entrada para Fish y la carpeta de trabajo
WORKDIR /home

# Configura el directorio de inicio como /home
CMD ["/usr/bin/fish"]

```

# Monta el volumen

Abre un terminal en la carpeta donde creaste el Dockerfile y corre el siguiente comando

```
docker run -it --rm -v ruta/carpeta/personal:/home mi-imagen-con-todo
```

# Crea un iniciar_docker.bat file en desktop para acceder de forma sencilla

```
@echo off
docker run -it --rm -v ruta/carpeta/personal:/home mi-imagen-con-todo
pause
```
