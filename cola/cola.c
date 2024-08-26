//
// Created by pamba on 25/08/2024.
//
#include "nodo.h"
#include "../cliente/cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

nodo *cabeza = NULL;
nodo *cola = NULL;

void offer(cliente *cliente) {
    nodo *creado = malloc(sizeof(nodo));
    if(cabeza == NULL) {
        creado->cliente = cliente;
        cabeza = creado;
    }else {
        creado->cliente = cliente;
        cola->siguiente = creado;
    }
    cola = creado;
    cola->siguiente = NULL;
}

cliente *poll() {
    if(cabeza != NULL) {
        nodo *aux = cabeza;
        cabeza = cabeza->siguiente;
        cliente *cliente = aux->cliente;
        free(aux);
        mostrar();
        return cliente;
    }
    return NULL;
}

void mostrar() {

    if(cabeza != NULL) {
        nodo *aux = cabeza;

        printf("---------------------------------------------------------------------------------\n");
        printf("Clientes en espera:\n");

        while(aux != NULL) {
            printf("%s, ", aux->cliente->nombre);
            aux = aux->siguiente;
        }
        printf("\n---------------------------------------------------------------------------------\n");

        printf("\n");
    }

}
