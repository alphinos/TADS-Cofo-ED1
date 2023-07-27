
#ifndef _N_QUEENS_C_
#define _N_QUEENS_C_

#include "sllist.h"
#include "nQueens.h"
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>

queen * createQueen(int id, int i, int j ){
    if ( i < 0 || j < 0 ){
        return NULL;
    }
    queen *q = (queen *) malloc ( sizeof(queen) );
    q->id = id;
    q->i = i;
    q->j = j;
    return q;
}

int destroyQueen(queen * q){
    if (q == NULL)
        return FALSE;
    free(q);
    return TRUE;
}

table * createTable( int n ){
    if ( n < 5 )
        return NULL;
    table *tab = (table *) malloc( sizeof(table) );
    if (tab == NULL)
        return NULL;
    
    int *map = (int *) malloc( n * n * sizeof(int) );
    for (int i = 0; i < n * n; i++){
        map[i] = -1;
    }
    if (map == NULL)
        return NULL;

    tab->size = n;
    tab->len = 0;
    tab->queens = sllCreate();
    tab->map = map;
    return tab;
}

int destroyTable( table * tab ){
    if ( tab == NULL || tab->queens != NULL )
        return FALSE;
    free(tab->map);
    sllEmpty(tab->queens);
    sllDestroy(tab->queens);
    free(tab);
    return TRUE;
}

unsigned long fulfillMap(table *tab){
    if (tab == NULL){
        return -1;
    }
    if ( tab->size < 5 ){
        return -1;
    }

    unsigned long iter = 0;

    int i, j, alocQ;

    queen *q;

    while ( tab->len < tab->size){

        for ( i = 0; i < tab->size; i++ ){
            for ( j = 0; j < tab->size; j++ ){
                printf(" %d ", tab->map[ i * tab->size + j ]);
            }
            printf("\n");
        }
        printf("\n");

        i = tab->len;
        alocQ = FALSE;
        for (j = 0; j < tab->size; j++){
            if (tab->map[i * tab->size + j] == -1 && alocQ == FALSE){
                tab->map[i * tab->size + j] = 0;
                q = createQueen(tab->len, i, j);
                sllInsertFirst(tab->queens, (void *) q);
                alocQ = TRUE;
            } else if (tab->map[i * tab->size + j] == -2){
                if ( alocQ == TRUE ){
                    tab->map[ q->i * tab->size + q->j ] = -1;
                    q = (queen *) sllRemoveFirst(tab->queens);
                    alocQ = FALSE;
                }
                tab->map[i * tab->size + j] = -1;
            }
        }

        if ( alocQ == FALSE ){
            q = (queen *) sllRemoveFirst(tab->queens);
            i = q->i;

            // Clear row
            for (j = 0; j < tab->size; j++){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
            }

            // Clear col
            j = q->j;
            for (i = tab->len; i < tab->size; i++){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
            }

            // Clear main diagonal
            i = q->i;
            j = q->j;

            while ( i > 0 && j > 0){
                i--;
                j--;
            }
            
            while ( i < tab->size && j < tab->size ){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
                i++;
                j++;
            }

            // Clear secondary diagonal
            i = q->i;
            j = q->j;

            while ( i > 0 && j < 4 ){
                i--;
                j++;
            }

            while ( i < tab->size && j > 0 ){
                if (tab->map[ i * tab->size + j ] == tab->len)
                    tab->map[ i * tab->size + j ] = -1;
                i++;
                j--;
            }

            tab->map[ q->i * tab->size + q->j ] = -2;
            tab->len--;
            iter++;
            destroyQueen(q);
            continue;
        }

        // Mark the row
        for (j = 0; j < tab->size; j++){
            if ( tab->map[ q->i * tab->size + j ] != -1 )
                continue;
            tab->map[ q->i * tab->size + j ] = tab->len + 1;
        }

        // Mark the col
        for (i = tab->len + 1; i < tab->size; i++){
            if ( tab->map[ i * tab->size + q->j ] != -1 )
                continue;
            tab->map[ i * tab->size + q->j ] = tab->len + 1;
        }

        // Mark the main diagonal
        i = q->i;
        j = q->j;

        while ( i > 0 && j > 0){
            i--;
            j--;
        }

        while ( i < tab->size && j < tab->size ){
            if ( ( i != q->i || j != q->j ) && tab->map[ i * tab->size + j ] == -1 )
                tab->map[ i * tab->size + j ] = tab->len + 1;
            i++;
            j++;
        }

        // Mark the secondary diagonal
        i = q->i;
        j = q->j;

        while ( i > 0 && j < 4 ){
            i--;
            j++;
        }

        while ( i < tab->size && j > 0 ){
            if ( ( i != q->i || j != q->j ) && tab->map[ i * tab->size + j ] == -1 )
                tab->map[ i * tab->size + j ] = tab->len + 1;
            i++;
            j--;
        }

        tab->len++;
        iter++;
    }

    return iter;
}

void printTab( table *tab){
    for (int i = 0; i < tab->size; i++){
        for (int j = 0; j < tab->size; j++){
            printf("%d ", tab->map[i * tab->size + j]);
        }
        printf("\n");
    }
}

blockStr * createBlockSTR( int n ){
    if ( n <= 0 ){
        return NULL;
    }
    blockStr *block = (blockStr *) malloc(sizeof(blockStr));
    if ( block == NULL){
        return NULL;
    }
    block->size = n;
    block->lines = ( char ** ) malloc( block->size * sizeof(char *) );
    int i, error = FALSE;
    for ( i = 0; i < block->size; i++ ){
        block->lines[i] = ( char * ) malloc( block->size  * sizeof(char) );
        if ( block->lines[i] == NULL ){
            error = TRUE;
            break;
        }
    }

    if ( error == TRUE ){
        while( i >= 0 ){
            free( block->lines[i] );
            i--;
        }
        free( block->lines );
        free( block );
        return NULL;
    } else {
        return block;
    }

}

int destroyBlockSTR( blockStr *block ){
    if ( block == NULL ){
        return FALSE;
    }
    if ( block->lines != NULL){
        return FALSE;
    }
    free( block->lines );
    free( block );
    return TRUE;
}

int emptyBlockSTR( blockStr *block ){
    int i = block->size - 1;
    while( i >= 0 ){
            free( block->lines[i] );
            i--;
        }

    free( block->lines );
}

blockStr * getStrTab( table *tab ){
    if ( tab == NULL ){
        return NULL;
    }

    blockStr *strMap = createBlockSTR(tab->size);
    if ( strMap == NULL ){
        return NULL;
    }

    int i, j;
    for ( i = 0; i < tab->size; i++ ){
        for ( j = 0; j < tab->size; j++ ){
            // strMap->lines[i][j] = tab->map[ i * tab->size + j ] + '0';
            if ( tab->map[ i * tab->size + j ] == 0 ){
                strMap->lines[i][j] = 'Q';
            } else {
                strMap->lines[i][j] = '-';
            }
        }
    }

    return strMap;
}

void printBlock( blockStr * block ){
    for (int i = 0; i < block->size; i++){
        printf("%s\n\v", block->lines[i]);
    }
}

void printfBlock( blockStr * block, int alignment, char color[], int jump, int sizeTxt ){
    for (int i = 0; i < block->size; i++){
        fcprint( block->lines[i], alignment, color, jump, sizeTxt );
    }
}

#endif