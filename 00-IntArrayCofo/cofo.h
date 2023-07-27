// Discente: Carlos Eduardo Veras Gomes

#ifndef __COFO_H
#define __COFO_H

typedef struct _cofo_{
    int numItens;
    int maxItens;
    int *item;
} Cofo;

Cofo *cofCreate(int maxItens);
int cofInsert(Cofo *c, int item);
int cofRemove(Cofo *c, int item);
int cofQuery(Cofo *c, int key);
int cofDestroy(Cofo *c);

#endif