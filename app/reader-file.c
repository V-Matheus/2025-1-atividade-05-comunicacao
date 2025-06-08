#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
int mensagem_disponivel = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* escritor(void* arg) {
    pthread_mutex_lock(&mutex);
    snprintf(buffer, BUFFER_SIZE, "Olá, comunicação via threads!\n");
    mensagem_disponivel = 1;
    printf("Escritor: Mensagem escrita no buffer.\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* leitor(void* arg) {
    pthread_mutex_lock(&mutex);
    while (!mensagem_disponivel) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Leitor: Mensagem lida:\n%s", buffer);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t_escritor, t_leitor;

    pthread_create(&t_leitor, NULL, leitor, NULL);
    sleep(1); // Garante que o leitor está esperando
    pthread_create(&t_escritor, NULL, escritor, NULL);

    pthread_join(t_escritor, NULL);
    pthread_join(t_leitor, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}