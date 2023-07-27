#ifndef _SLLIST_H_
#define _SLLIST_H_

#define TRUE 1
#define FALSE 0

#ifdef _SLLIST_C_

typedef struct _sllnode_ {
    void *data;
    struct _sllnode_ *next;
} sllnode;

typedef struct _sllist_{
    sllnode *first;
} sllist;

//Stack
sllist * sllCreate( void );
int sllDestroy ( sllist *list );
int sllInsertFirst( sllist *list, void *data );
void * sllRemoveFirst( sllist *list );
void * sllGetFirst( sllist *list );
int sllEmpty( sllist *list );

//Queue
int sllInsertLast( sllist *list, void *data );
void * sllGetLast( sllist *list );
int sllNNodes( sllist *list );
int sllInsertPEsimo( sllist *list, void *data, int p );
int sllInsertAfterPEsimo( sllist *list, void *data, int p );

void * sllQuery( sllist *list, void *key, int (*cmp)(void *, void *) );
void * sllRemoveSpecified( sllist *list, void *key, int (*cmp)(void *, void *) );
void * sllRemoveAfterSpecified( sllist *list, void *key, int (*cmp)(void *, void *) );
int sllInsertAfterSpecified( sllist *list, void *data, void *key, int (*cmp)(void *, void *) );
int sllInsertBeforeSpecified( sllist *list, void *data, void *key, int (*cmp)(void *, void *) );

#else

typedef struct _sllist_ sllist;
extern sllist * sllCreate( void );
extern int sllDestroy ( sllist *list );
extern int sllInsertFirst( sllist *list, void *data );
extern void * sllRemoveFirst( sllist *list );
extern void * sllGetFirst( sllist *list );
extern int sllEmpty( sllist *list );

extern int sllInsertLast( sllist *list, void *data );
extern void * sllGetLast( sllist *list );
extern int sllNNodes( sllist *list );
extern int sllInsertPEsimo( sllist *list, void *data, int p );
extern int sllInsertAfterPEsimo( sllist *list, void *data, int p );

extern void * sllQuery( sllist *list, void *key, int (*cmp)(void *, void *) );
extern void * sllRemoveSpecified( sllist *list, void *key, int (*cmp)(void *, void *) );
extern void * sllRemoveAfterSpecified( sllist *list, void *key, int (*cmp)(void *, void *) );
extern int * sllInsertAfterSpecified( sllist *list, void *data, void *key, int (*cmp)(void *, void *) );
extern void * sllInsertBeforeSpecified( sllist *list, void *data, void *key, int (*cmp)(void *, void *) );

#endif
#endif