cmake_minimum_required(VERSION 3.29)
project(Banco C)

set(CMAKE_C_STANDARD 11)

add_executable(Banco main.c
        caja/caja.h
        caja/caja.c
        cliente/cliente.h
        cola/cola.c
        cola/cola.h
        cola/nodo.h
        archivo/archivo.c
        archivo/archivo.h
)
