// Discente: Carlos Eduardo Veras Gomes

#ifndef _SLLIST_C_
#define _SLLIST_C_

#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

sllist * sllCreate( void ){
    sllist *list;
    list = (sllist *) malloc( sizeof(sllist) );
    if (list == NULL)
        return NULL;
    list->first = NULL;
    return list;
}

int sllDestroy ( sllist *list ){
    if ( list == NULL || list->first != NULL )
        return FALSE;
    free(list);
    return TRUE;
}

int sllInsertFirst( sllist *list, void *data ){
    if (list == NULL)
        return FALSE;
    sllnode *node;
    node = (sllnode *) malloc( sizeof(sllnode) );
    if ( node == NULL )
        return FALSE;
    node->data = data;
    node->next = list->first;
    list->first = node;
    return TRUE;
}

void * sllRemoveFirst( sllist *list ){
    if (list == NULL)
        return NULL;
    if (list->first == NULL)
        return NULL;
    sllnode *first = list->first;
    void *data;
    data = first->data;
    list->first = first->next;
    free(first);
    return data;
}

void * sllGetFirst( sllist *list ){
    if (list == NULL)
        return NULL;
    return list->first;
}

int sllEmpty( sllist *list ){
    if (list == NULL)
        return FALSE;
    while(sllRemoveFirst(list) != NULL);
    return TRUE;
}

int sllInsertLast( sllist *list, void *data ){
    if (list == NULL)
        return FALSE;
    sllnode *node = (sllnode *) malloc( sizeof(sllnode) );
    if (node == NULL)
        return FALSE;
    node->data = data;
    node->next;
    sllnode *last = list->first;
    while( last->next != NULL )
        last = last->next;
    last->next = node;
}

void * sllGetLast( sllist *list ){
    if (list == NULL)
        return NULL;
    sllnode *last = list->first;
    if (last == NULL)
        return NULL;
    while (last->next != NULL){
        last = last->next;
    }
    return last->data;
}

int sllNNodes( sllist *list ){
    if (list == NULL)
        return -1;
    sllnode *last = list->first;
    if (last == NULL)
        return 0;
    int n = 1;
    while (last->next != NULL){
        last = last->next;
        n++;
    }
    return n;
}

int sllInsertPEsimo( sllist *list, void *data, int p ){
    if (list == NULL || p <= 0)
        return FALSE;
    //Se p for maior do que a quantidade de elementos, coloca no final
    sllnode *pelm;
    int i = 0;
    pelm = list->first;
    if (pelm != NULL){
        while (i < p && pelm->next!= NULL){
            pelm = pelm->next;
            i++;
        }
    }
    sllnode *node = (sllnode *) malloc( sizeof(sllnode) );
    if (node == NULL)
        return FALSE;
    node->data = data;
    node->next = pelm;
    pelm = node;
    return TRUE;
}

int sllInsertAfterPEsimo( sllist *list, void *data, int p ){
    if (list == NULL || p <= 0)
        return FALSE;
    //Se p for maior do que a quantidade de elementos, coloca no final
    sllnode *pelm;
    int i = 0;
    pelm = list->first;
    if (pelm != NULL){
        while (i < p && pelm->next != NULL){
            pelm = pelm->next;
            i++;
        }
    }
    sllnode *node = (sllnode *) malloc( sizeof(sllnode) );
    if (node == NULL)
        return FALSE;
    node->data = data;
    node->next = pelm->next;
    pelm->next = node;
    return TRUE;
}

// Exercícios 5
void * sllQuery( sllist *list, void *key, int (*cmp)(void *, void *) ){
    if (list == NULL || key == NULL || cmp == NULL)
        return NULL;
    if (list->first == NULL)
        return NULL;
    sllnode *elm = list->first;
    int found = FALSE;
    while ( elm->next != NULL && found == FALSE ){
        if (cmp(elm->data, key) == TRUE){
            found = TRUE;
        } else {
            elm = elm->next;
        }
    }
    if (found == TRUE){
        return elm;
    } else {
        return NULL;
    }
}

// Exercícios 5
void * sllRemoveSpecified( sllist *list, void *key, int (*cmp)(void *, void *) ){
    if (list == NULL || key == NULL || cmp == NULL)
        return NULL;
    if (list->first == NULL)
        return NULL;

    sllnode *befr = list->first;
    sllnode *curr = list->first->next;
    int found = FALSE;
    void * data;

    while ( curr->next != NULL && found == FALSE ){
        if (cmp(curr->data, key) == TRUE){
            found = TRUE;
        } else {
            befr = curr;
            curr = curr->next;
        }
    }
    if (found == TRUE){
        befr->next = curr->next;
        data = curr->data;
        free(curr);
        return data;
    } else {
        return NULL;
    }
}

void * sllRemoveAfterSpecified( sllist *list, void *key, int (*cmp)(void *, void *) ){
    if (list == NULL || key == NULL || cmp == NULL)
        return NULL;
    if (list->first == NULL)
        return NULL;

    sllnode *curr = list->first;
    sllnode *after = curr->next;
    int found = FALSE;
    void * data;

    while ( after != NULL && found == FALSE ){
        if (cmp(curr->data, key) == TRUE){
            found = TRUE;
        } else {
            curr = after;
            after = after->next;
        }
    }
    if (found == TRUE){
        curr->next = after->next;
        data = after->data;
        free(after);
        return data;
    } else {
        return NULL;
    }
}

// Exercícios 5
int sllInsertAfterSpecified( sllist *list, void *data, void *key, int (*cmp)(void *, void *) ){
    if (list == NULL || key == NULL || cmp == NULL)
        return FALSE;
    if (list->first == NULL)
        return FALSE;

    sllnode *curr = list->first;
    sllnode *after = curr->next;
    int found = FALSE;

    while ( after != NULL && found == FALSE ){
        if (cmp(curr->data, key) == TRUE){
            found = TRUE;
        } else {
            curr = after;
            after = after->next;
        }
    }

    if (found == TRUE){
        sllnode *node = (sllnode *) malloc( sizeof(sllnode) );
        if (node == NULL)
            return FALSE;

        node->data = data;
        curr->next = node;
        node->next = after;

        return TRUE;
    } else {
        return FALSE;
    }
}

// Exercícios 5
int sllInsertBeforeSpecified( sllist *list, void *data, void *key, int (*cmp)(void *, void *) ){
    if (list == NULL || key == NULL || cmp == NULL)
        return FALSE;
    if (list->first == NULL)
        return FALSE;

    sllnode *curr = list->first;
    sllnode *after = curr->next;
    int found = FALSE;

    while ( after != NULL && found == FALSE ){
        if (cmp(after->data, key) == TRUE){
            found = TRUE;
        } else {
            curr = after;
            after = after->next;
        }
    }

    if (found == TRUE){
        sllnode *node = (sllnode *) malloc( sizeof(sllnode) );
        if (node == NULL)
            return FALSE;

        node->data = data;
        curr->next = node;
        node->next = after;

        return TRUE;
    } else {
        return FALSE;
    }
}

#endif