#ifndef _CQUEUE_H_
#define _CQUEUE_H_

#define TRUE 1
#define FALSE 0

#ifdef _CQUEUE_C_

typedef struct _c_queue_{
    int front;
    int rear;
    int maxItems;
    int nElms;
    void **items;
} CQueue;

int circInc( int i, int max );
int circDec( int i, int max );

CQueue *qcCreate( int max );
int qcEnQueue( CQueue *queue, void *elm );
int qcDeQueue( CQueue *queue );
void *qcFirst( CQueue *queue );
int qcDestroy( CQueue *queue );
int isQcEmpy( CQueue *queue );
int qcPromoteLast( CQueue *queue, int n );
int qcPunishFirst( CQueue *queue, int n );

#else

typedef struct _c_queue_ CQueue;
extern CQueue *qcCreate( int max );
extern int qcEnQueue( CQueue *queue, void *elm );
extern int qcDeQueue( CQueue *queue );
extern void *qcFirst( CQueue *queue );
extern int qcDestroy( CQueue *queue );
extern int isQcEmpy( CQueue *queue );
extern int qcPromoteLast( CQueue *queue, int n );
extern int qcPunishFirst( CQueue *queue, int n );

#endif
#endif