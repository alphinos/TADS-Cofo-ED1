// Discente: Carlos Eduardo Veras Gomes

#ifndef _COFO_C_
#define _COFO_C_

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

// typedef struct _cofo_ {
//     int numItens;
//     int maxItens;
//     int *item;
// } Cofo;

Cofo *cofCreate(int maxItens){
    Cofo *cofo;
    if (maxItens <= 0){
        return NULL;
    }
    cofo = (Cofo *)malloc(sizeof(Cofo));
    if (cofo == NULL){
        free(cofo);
        return NULL;
    }
    cofo->item = (int *)malloc(sizeof(int) * maxItens);
    if (cofo->item == NULL){
        free(cofo);
        return NULL;
    }
    cofo->numItens = 0;
    cofo->maxItens = maxItens;
    return cofo;
}

int cofDestroy(Cofo *cofo){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItens != 0)
        return FALSE;
    
    free(cofo->item);
    free(cofo);
    return TRUE;
}

int cofInsert(Cofo *cofo, int item){
    if (cofo == NULL)
        return FALSE;
    if ( cofo->numItens >= cofo->maxItens)
        return FALSE;
    if (cofo->item == NULL)
        return FALSE;
    cofo->item[cofo->numItens] = item;
    cofo->numItens++;
    return TRUE;
}

int cofRemove(Cofo *cofo, int item){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItens <= 0)
        return FALSE;
    
    int i = 0, status = FALSE, data;
    while(i < cofo->numItens && status == FALSE){
        if ( cofo->item[i] == item )
            status = TRUE;
        else
            i++;
        
        if (status == TRUE){
            data = cofo->item[i];
            for (int j = i; j < cofo->numItens - 1; j++){
                cofo->item[j] = cofo->item[j+1];
            }
            cofo->numItens--;
            return data;
        }
    }
    return FALSE; // If the item is not in the cofo
}

int cofQuery(Cofo *cofo, int item){
    if (cofo == NULL)
        return FALSE;
    if (cofo->numItens <= 0)
        return FALSE;
    
    int i = 0, status = FALSE;
    while (i < cofo->numItens && status == FALSE){
        if (cofo->item[i] == item)
            status = TRUE;
        else
            i++;
        
        if (status == TRUE)
            return TRUE;
    }

    return FALSE; // If the item is not in the cofo
}

#endif