#ifndef _QUEUE_H_
#define _QUEUE_H_

#define TRUE 1
#define FALSE 0

#ifdef _QUEUE_C_

typedef struct _queue_{
    int front;
    int rear;
    int maxItems;
    void **items;
} Queue;

Queue *qCreate( int n );
int qDestroy( Queue *queue );
int qEnQueue( Queue *queue, void *data );
void *qDeQueue( Queue *queue );
void *qFirst( Queue *queue );
int qIsEmpty( Queue *queue );

#else

typedef struct _queue_ Queue;
extern Queue *qCreate( int n );
extern int qDestroy( Queue *queue );
extern int qEnQueue( Queue *queue, void *data );
extern void *qDeQueue( Queue *queue );
extern void *qFirst( Queue *queue );
extern int qIsEmpty( Queue *queue );

#endif
#endif