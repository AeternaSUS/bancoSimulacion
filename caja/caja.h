//
// Created by pamba on 25/08/2024.
//

#ifndef CAJA_H
#define CAJA_H

extern pthread_mutex_t mutex;

void* atender(void* arg);
void iniciarMutex();

#endif //CAJA_H
