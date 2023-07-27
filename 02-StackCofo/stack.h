#ifndef _STACK_H_
#define _STACK_H_

#define TRUE 1
#define FALSE 0

#ifdef _STACK_C_
typedef struct _stack_{
    int maxItems;
    int top;
    void* *items;
} Stack;

Stack *stkCreate(int max);
int stkPush(Stack *s, void *elm);
void *stkPop(Stack *s);
void *stkTop(Stack *s);
int isStkEmpty(Stack *s);
int stkDestroy(Stack *s);

#else
typedef struct _stack_ Stack;

extern Stack *stkCreate(int max);
extern int stkPush(Stack *s, void *elm);
extern void *stkPop(Stack *s);
extern void *stkTop(Stack *s);
extern int isStkEmpty(Stack *s);
extern int stkDestroy(Stack *s);

#endif
#endif