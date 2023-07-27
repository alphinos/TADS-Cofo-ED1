// Discente: Carlos Eduardo Veras Gomes

#ifndef _GCOFO_C_
#define _GCOFO_C_

#include <stdio.h>
#include <stdlib.h>
#include "gcofo.h"

gCofo *gCofCreate(int max_items){
    if (max_items <= 0)
        return NULL;
    gCofo *gcofo;
    gcofo = (gCofo*) malloc(sizeof(gCofo));
    if (gcofo == NULL){
        free(gcofo);
        return NULL;
    }
    gcofo->items = (void* *)malloc(sizeof(void*)*max_items);
    if (gcofo == NULL){
        free(gcofo);
        return NULL;
    }
    gcofo->numItems = 0;
    gcofo->maxItems = max_items;
    gcofo->curr = -1;
    return gcofo;
}

int gCofDestroy(gCofo *cofo){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItems != 0)
        return FALSE;
    free(cofo->items);
    free(cofo);
    return TRUE;
}

int gCofInsert(gCofo *cofo, void* item){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItems < cofo->maxItems)
        cofo->items[cofo->numItems] = item;
        cofo->numItems++;
        return TRUE;
    return FALSE;
}

void* gCofGetFirst(gCofo *cofo){
    void* elm;
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    elm = cofo->items[0];
    cofo->curr = 0;
    return elm;
}

void* gCofGetNext(gCofo *cofo){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    cofo->curr++;
    if (cofo->curr < cofo->numItems)
        return cofo->items[cofo->curr];
    return NULL;
}

void* gCofQuery(gCofo *cofo, void* key, int (*cmp)(void*, void*)){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;

    for (int i = 0; i < cofo->numItems; i++){
        if (cmp(cofo->items[i], key) == TRUE)
            return cofo->items[i];
    }

    return NULL;
}

void* gCofRemove(gCofo *cofo, void* key, int (*cmp)(void*, void*)){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;

    int i, j;
    void* data;
    int status;

    for ( i = 0; i < cofo->numItems; i++){
        if ( cmp(cofo->items[i], key) == TRUE){
            status = TRUE;
            break;
        }
    }

    if (status == TRUE){
        data = cofo->items[i];
        for (j = i; j < cofo->numItems -1; j++){
            cofo->items[j] = cofo->items[j + 1];
        }
        cofo->numItems--;
        return data;
    }

    return NULL;
}

void* gCofRemoveByIndex(gCofo *cofo, int i){
    if (cofo == NULL)
        return NULL;
    if (cofo->numItems <= 0)
        return NULL;
    if (i >= cofo->numItems)
        return NULL;
    void* data;
    data = cofo->items[i];
    for(int j = i; j < cofo->numItems; j++){
        cofo->items[j] = cofo->items[j + 1];
    }
    cofo->numItems--;
    return data;
}

int gCofEmpty(gCofo *cofo){
    if (cofo == NULL)
        return -1;

    int aux = 0;
    void* elm;

    for (int i = cofo->numItems - 1; i >= 0; i--){
        aux = i;
        elm = gCofRemoveByIndex(cofo, i);
        if (elm == NULL)
            return -1;
    }
    return cofo->numItems;
}

#endif