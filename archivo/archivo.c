//
// Created by pamba on 25/08/2024.
//

#include "archivo.h"

#include <stdio.h>
#include "../cola/cola.h"
#include <pthread.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>


int NUM_CLIENTES = 0;

int ATENDER = 1;
void *crearCliente(void *) {
    while (ATENDER) {
        srand(time(NULL));
        int idCliente = (rand() % NUM_CLIENTES) + 1;
        cliente *cliente = extraerCliente(idCliente);
        offer(cliente);
        Sleep(1000);
    }


    return NULL;
}

//esto se ejecuta solamente una vez
void numClientes() {
    FILE *clientes = fopen("Clientes.txt", "r");

    while (!feof(clientes)) {
        if (fgetc(clientes) == '\n') {
            NUM_CLIENTES++;
        }
    }
}

cliente *extraerCliente(int posicion) {
    FILE *clientes = fopen("Clientes.txt", "r");

    int cont = 1;
    while (cont < posicion) {
        if (fgetc(clientes) == '\n') {
            cont++;
        }
    }

    char nombre[30];
    long cuenta;

    fscanf(clientes, "%s %ld", nombre, &cuenta);
    cliente *newCliente = malloc(sizeof(cliente));
    char *nombreStr = malloc(strlen(nombre) + 1);

    strcpy(nombreStr, nombre);

    newCliente->nombre = nombreStr;
    newCliente->cuenta = cuenta;

    return newCliente;
}
