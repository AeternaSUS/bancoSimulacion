#include <pthread.h>
#include "caja/caja.h"
#include "archivo/archivo.h"

int main(void) {
    numClientes();


    iniciarMutex();
    pthread_t caja1;
    pthread_t caja2;
    pthread_t clientes;

    pthread_create(&caja1, NULL, atender, NULL);
    pthread_create(&caja2, NULL, atender, NULL);
    pthread_create(&clientes, NULL, crearCliente, NULL);


    pthread_join(caja1, NULL);
    pthread_join(caja2, NULL);
    pthread_join(clientes, NULL);


    pthread_mutex_destroy(&mutex);


    return 0;
}
