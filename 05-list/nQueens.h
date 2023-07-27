#ifndef _N_QUEENS_H_
#define _N_QUEENS_H_

#define TRUE 1
#define FALSE 0

#ifdef _N_QUEENS_C_

typedef struct _queen_{
    int id;
    int i;
    int j;
} queen;

typedef struct _table_{
    int size;
    int len;
    sllist *queens;
    int *map;
} table;

typedef struct _blockStr_{
    int size;
    char **lines;
} blockStr;

void printTab( table *tab);
queen * createQueen(int id, int i, int j );
int destroyQueen(queen * q);
table * createTable( int n );
int destroyTable( table * tab );
unsigned long fulfillMap(table *tab);

blockStr * createBlockSTR( int n );
int destroyBlockSTR( blockStr *block );
int emptyBlockSTR( blockStr *block );
blockStr * getStrTab( table *tab );
void printBlock( blockStr * block );
void printfBlock( blockStr * block, int alignment, char color[], int jump, int sizeTxt );

#else

typedef struct _queen_ queen;
typedef struct _table_ table;
typedef struct _blockStr_ blockStr;

extern queen * createQueen(int id, int i, int j );
extern int destroyQueen(queen * q);
extern table * createTable( int n );
extern int destroyTable( table * tab );
extern unsigned long fulfillMap(table *tab);
extern void printTab( table *tab);

extern blockStr * createBlockSTR( int n );
extern int destroyBlockSTR( blockStr *block );
extern int emptyBlockSTR( blockStr *block );
extern blockStr * getStrTab( table *tab );
extern void printBlock( blockStr * block );
extern void printfBlock( blockStr * block, int alignment, char color[], int jump, int sizeTxt );

#endif
#endif