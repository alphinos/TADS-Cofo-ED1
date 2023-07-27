// Discente: Carlos Eduardo Veras Gomes

#ifndef _STACK_C_
#define _STACK_C_

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *stkCreate(int max){
    Stack *stack;
    if (max <= 0){
        return NULL;
    }
    stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL){
        return NULL;
    }
    stack->items = (void **) malloc( sizeof( void * ) * max );
    if (stack->items == NULL){
        return NULL;
    }
    stack->maxItems = max;
    stack->top = -1;
    return stack;
}

int stkDestroy( Stack *stack ){
    if ( stack == NULL){
        return FALSE;
    }
    if ( stack->top >= 0 ){
        return FALSE;
    }
    free(stack->items);
    free(stack);
    return TRUE;
}

int stkPush(Stack *stack, void *elm){
    if (stack == NULL){
        return FALSE;
    }
    if (stack->top >= stack->maxItems - 1){
        return FALSE;
    }
    stack->top++;
    stack->items[stack->top] = elm;
    return TRUE;
}

void *stkPop(Stack *stack){
    void *aux;
    if (stack == NULL){
        return NULL;
    }
    if (stack->top < 0){
        return NULL;
    }
    aux = stack->items[stack->top];
    stack->top--;
    return aux;
}

void *stkTop(Stack *stack){
    void *aux;
    if (stack == NULL){
        return NULL;
    }
    if (stack->top < 0){
        return NULL;
    }
    aux = stack->items[stack->top];
    return aux;
}

int isStkEmpty(Stack *stack){
    if (stack == NULL){
        return FALSE;
    }
    if (stack->top >= 0 ){
        return FALSE;
    }
    return TRUE;
}

#endif