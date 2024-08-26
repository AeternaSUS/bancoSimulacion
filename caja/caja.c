//
// Created by pamba on 25/08/2024.
//

#include <stdio.h>
#include "../cliente/cliente.h"
#include "../cola/cola.h"
#include <windows.h>
#include <pthread.h>
#include "caja.h"

pthread_mutex_t mutex;

int A = 1;
void *atender(void * ) {
    while (A) {

        pthread_mutex_lock(&mutex);
        cliente *cliente = poll();
        pthread_mutex_unlock(&mutex);

        if (cliente != NULL) {
            Sleep(3000);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Cliente atendido: %s\n", cliente->nombre);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            free(cliente->nombre);
            free(cliente);
        }
    }
    return NULL;
}

void iniciarMutex() {
    pthread_mutex_init(&mutex, NULL);
}
