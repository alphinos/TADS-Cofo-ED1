//Carlos Eduardo Veras Gomes - 3º período 

#ifndef _GCOFO_H_
#define _GCOFO_H_

#define TRUE 1
#define FALSE 0

#ifdef _GCOFO_C_
typedef struct _gcofo_{
    int numItems;
    int maxItems;
    int curr;
    void* *items;
} gCofo;

gCofo *gCofCreate(int max_items);
int gCofInsert(gCofo *cofo, void* item);
void* gCofRemove(gCofo *cofo, void* key, int (*cmp)(void*, void*));
void* gCofRemoveByIndex(gCofo *cofo, int i);
int gCofEmpty(gCofo *cofo);
void* gCofQuery(gCofo *cofo, void* key, int (*cmp)(void*, void*));
void* gCofGetFirst(gCofo *cofo);
void* gCofGetNext(gCofo *cofo);
int gCofDestroy(gCofo *cofo);
#else
typedef struct _gcofo_ gCofo;
extern gCofo *gCofCreate(int max_items);
extern int gCofInsert(gCofo *cofo, void* item);
extern void* gCofRemove(gCofo *cofo, void* key, int (*cmp)(void*, void*));
extern void* gCofRemoveByIndex(gCofo *cofo, int i);
extern int gCofEmpty(gCofo *cofo);
extern void* gCofQuery(gCofo *cofo, void* key, int (*cmp)(void*, void*));
extern void* gCofGetFirst(gCofo *cofo);
extern void* gCofGetNext(gCofo *cofo);
extern int gCofDestroy(gCofo *cofo);
#endif
#endif