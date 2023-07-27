// Carlos Eduardo Veras Gomes

#ifndef _TREE_H_
#define _TREE_H_

#define TRUE 1
#define FALSE 0

#ifdef _TREE_C_


typedef struct _tnode_ {
    void *data;
    struct _tnode_ *left;
    struct _tnode_ *right;
} tNode;

tNode *createTree( void *data );
int destroyTree( tNode *tree);

void *abpQuery( tNode *t, void *key, int (*cmp)( void *, void * ) );
tNode *abpInsert( tNode *t, void *data, int (*cmp)( void *, void * ) );
tNode *abpRemove( tNode *t, void *key, int (*cmp)( void *, void * ), void **data );

void *abpGetMin( tNode *t );
void *abpGetMax( tNode *t );

tNode *abpRemoveMaior( tNode *t, int (*cmp)( void *, void * ), void **data );
tNode *abpRemoveMenor( tNode *t, int (*cmp)( void *, void * ), void **data );

void * getData( tNode *t );

void preOrdem( tNode *t , void ( visit )( void* ) );
void OrdemSimetrica( tNode *t, void ( visit )( void* ) );
void posOrdem( tNode *t, void ( visit )( void* ) );

#else

typedef struct _tnode_ tNode;

extern tNode *createTree( void *data );
extern int destroyTree( tNode *tree);

extern void *abpQuery( tNode *t, void *key, int (*cmp)( void *, void * ) );
extern tNode *abpInsert( tNode *t, void *data, int (*cmp)( void *, void * ) );
extern tNode *abpRemove( tNode *t, void *key, int (*cmp)( void *, void * ), void **data );

extern void *abpGetMin( tNode *t );
extern void *abpGetMax( tNode *t );

extern tNode *abpRemoveMaior( tNode *t, int (*cmp)( void *, void * ), void **data );
extern tNode *abpRemoveMenor( tNode *t, int (*cmp)( void *, void * ), void **data );

extern void * getData( tNode *t );

extern void preOrdem( tNode *t , void ( visit )( void* ) );
extern void OrdemSimetrica( tNode *t, void ( visit )( void* ) );
extern void posOrdem( tNode *t, void ( visit )( void* ) );

#endif

#endif