FROM fedora:latest

RUN dnf -y update && \
    dnf -y install findutils fish gcc && \
    dnf clean all

# Cria um diretório para a aplicação (onde os arquivos do host serão mapeados)
RUN mkdir -p /app

# Define o diretório de trabalho padrão dentro do container
WORKDIR /app

# Comando padrão ao iniciar o container: inicia o shell fish
# Isso permite que o usuário compile e execute os códigos C manualmente
CMD ["fish"]

COPY reader-file.c /app/
COPY writer-file.c /app/