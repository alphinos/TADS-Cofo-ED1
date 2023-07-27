// Discente: Carlos Eduardo Veras Gomes

#ifndef _CQUEUE_C_
#define _CQUEUE_C_

#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"

int circInc( int i, int max ){
    if (i == max - 1)
        return 0;
    else
        return i + 1;
}

int circDec( int i, int max ){
    if (i == 0)
        return max - 1;
    else
        return i - 1;
}

CQueue *qcCreate( int max ){
    if (max <= 0)
        return NULL;
    CQueue *queue;
    queue = (CQueue *) malloc( sizeof(CQueue) );
    if (queue == NULL)
        return NULL;
    queue->items = (void* *) malloc( sizeof( void * )*max );
    if (queue->items == NULL)
        return NULL;
    queue->front = 0;
    queue->rear = -1;
    queue->maxItems = max;
    queue->nElms = 0;
    return queue;
}

int qcEnQueue( CQueue *queue, void *elm ){
    if (queue == NULL)
        return FALSE;
    if (queue->nElms >= queue->maxItems)
        return FALSE;
    queue->rear = circInc(queue->rear, queue->maxItems);
    queue->items[queue->rear] = elm;
    queue->nElms++;
}

int qcDeQueue( CQueue *queue ){
    void *data;
    if (queue == NULL)
        return FALSE;
    if (queue->nElms <= 0)
        return FALSE;
    data = queue->items[queue->front];
    queue->front = circInc(queue->front, queue->maxItems);
    queue->nElms--;
    return data;
}

void *qcFirst( CQueue *queue ){
    if (queue == NULL)
        return NULL;
    if (queue->nElms <= 0)
        return NULL;
    return queue->items[queue->front];
}

int qcDestroy( CQueue *queue ){
    if (queue == NULL)
        return FALSE;
    if (queue->nElms != 0)
        return FALSE;
    free(queue->items);
    free(queue);
    return TRUE;
}

int isQcEmpy( CQueue *queue ){
    if (queue == NULL)
        return FALSE;
    if (queue->nElms == 0)
        return TRUE;
    else
        return FALSE;
}

int qcPromoteLast( CQueue *queue, int n ){
    if (queue == NULL)
        return FALSE;
    if (n <= 0 )
        return FALSE;
    
    void *data;
    data = queue->items[queue->rear];
    int i, j, prev_j;
    
    if (queue->nElms <= n){
        queue->front = circDec(queue->front, queue->maxItems);
        queue->items[queue->front] = data;
        queue->rear = circDec(queue->rear, queue->maxItems);
        return TRUE;
    }

    j = queue->rear;
    for (i = 0; i < n; i++){
        prev_j = circDec(j, queue->maxItems);
        queue->items[j] = queue->items[prev_j];
        j = prev_j;
    }
    queue->items[j] = data;
    return TRUE;
}

int qcPunishFirst( CQueue *queue, int n ){
    if (queue == NULL)
        return FALSE;
    if (n <= 0)
        return FALSE;
    
    void *data;
    data = queue->items[queue->front];
    int i, j, next_j;

    if (queue->nElms <= n){
        queue->rear = circInc(queue->rear, queue->maxItems);
        queue->items[queue->rear] = data;
        queue->front = circInc(queue->front, queue->maxItems);
        return TRUE;
    }

    j = queue->front;
    for (i = 0; i < n; i++){
        next_j = circInc(j, queue->maxItems);
        queue->items[j] = queue->items[next_j];
        j = next_j;
    }
    queue->items[j] = data;
    return TRUE;
}

#endif