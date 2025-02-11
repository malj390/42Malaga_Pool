
# Descarga Docker

[https://docs.docker.com/get-started/get-docker/](https://docs.docker.com/get-started/get-docker/)

# Crea un archivo Dockerfile

Crealo en el lugar donde quieras que empieza tu home en Linux (bash).

```
# Usar la imagen de Ubuntu como base
FROM ubuntu:latest

# Instalar herramientas necesarias
RUN apt update && apt install -y \
    bash \
    gcc \
    vim \
    fish \
    git \
    curl \
    iputils-ping \
    xclip \
&& rm -rf /var/lib/apt/lists/*

# Configurar Git automáticamente para no olvidar el nombre de usuario y correo
RUN git config --global user.name "Tu Nombre" && \
    git config --global user.email "tuemail@example.com"

# Configurar el directorio de trabajo y la carpeta de inicio
WORKDIR /home
VOLUME ["/home"]

# Configurar el punto de entrada para iniciar en Bash
CMD ["/bin/bash"]



```

# Monta el volumen

Abre un terminal en la carpeta donde creaste el Dockerfile y corre el siguiente comando

```
docker build -t mi-imagen-con-todo .
```

Luego, ejecuta el contenedor de forma persistente y monta el volumen para que tu directorio C:/ruta/carpeta sea tu home:

```
docker run -it --name mi-container -v /ruta/carpeta:/home mi-imagen-con-todo

```

# Crea un iniciar_docker.bat file en desktop para acceder de forma sencilla

```
@echo off
cmd /k "docker start -ai mi-container"
```
