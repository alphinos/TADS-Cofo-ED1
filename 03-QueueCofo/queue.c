// Discente: Carlos Eduardo Veras Gomes

#ifndef _QUEUE_C_
#define _QUEUE_C_

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *qCreate( int n ){
    if ( n <= 0 )
        return NULL;
    Queue *queue;
    queue = (Queue *) malloc( sizeof(Queue) );
    if (queue == NULL){
        free(queue);
        return NULL;
    }
    queue->items = (void* * ) malloc(sizeof(void *) * n);
    if (queue->items == NULL){
        free(queue->items);
        free(queue);
        return NULL;
    }
    queue->maxItems = n;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int qDestroy( Queue *queue ){
    if (queue == NULL)
        return FALSE;
    if (queue->rear >= 0)
        return FALSE;
    free(queue->items);
    free(queue);
    return TRUE;
}

int qEnQueue( Queue *queue, void *data ){
    if (queue == NULL)
        return FALSE;
    if (queue->rear >= queue->maxItems - 1)
        return FALSE;
    queue->rear++;
    queue->items[queue->rear] = data;
    return TRUE;
}

void *qDeQueue( Queue *queue ){
    if (queue == NULL)
        return NULL;
    if (queue->rear < 0)
        return NULL;
    void *data;
    int curr, next, i;
    data = queue->items[queue->front];
    for (i = queue->front; i < queue->rear; i++){
        curr = i;
        next = i + 1;
        queue->items[curr] = queue->items[next];
    }
    queue->rear--;
    return data;
}

void *qFirst( Queue *queue ){
    if (queue != NULL){
        if (queue->rear >= 0){
            return queue->items[queue->front];
        }
    }
    return NULL;
}

int qIsEmpty( Queue *queue ){
    if (queue != NULL){
        if (queue->rear < 0){
            return TRUE;
        }
    }
    return FALSE;
}

#endif