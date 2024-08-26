//
// Created by pamba on 25/08/2024.
//

#ifndef NODO_H
#define NODO_H
#include "../cliente/cliente.h"

typedef struct nodo {
    cliente *cliente;
    struct nodo *siguiente;
}nodo;

#endif //NODO_H
