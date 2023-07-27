// Discente: Carlos Eduardo Veras Gomes

#ifndef _TREE_C_
#define _TREE_C_

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tNode *createTree( void *data ){
    tNode *tree = ( tNode *)malloc( sizeof( tNode ) );

    if ( tree == NULL )
        return NULL;

    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

int destroyTree( tNode *tree ){
    if ( tree == NULL )
        return TRUE;

    if ( tree->left == NULL && tree->right == NULL && tree->data == NULL ){
        free( tree );
        return TRUE;
    }
    return FALSE;
}

void *abpQuery( tNode *t, void *key, int (*cmp)( void *, void * ) ){
    if ( t == NULL )
        return NULL;
    
    int stat = cmp( t->data, key );
    if ( stat == 0 ){
        return t->data;
    } else if ( stat < 0 ){
        return abpQuery( t->left, key, cmp );
    } else {
        return abpQuery( t->right, key, cmp );
    }
}

tNode *abpInsert( tNode *t, void *data, int (*cmp)( void *, void * ) ){
    if ( t != NULL ){
        printf( "\n\n %d \n\n", *( int * )t->data );
        if ( cmp( t->data, data ) <= 0 ){
            t->left = abpInsert( t->left, data, cmp );
            return t;
        } else {
            t->right = abpInsert( t->right, data, cmp );
            return t;
        }
    } else {
        tNode *tNewNode = ( tNode *)malloc( sizeof( tNode ) );

        if ( tNewNode != NULL ){
            tNewNode->data = data;
            tNewNode->left = NULL;
            tNewNode->right = NULL;

            return tNewNode;
        } else {
            return NULL;
        }
    }
}

tNode *abpRemove( tNode *t, void *key, int (*cmp)( void *, void * ), void **data ){
    tNode *aux;
    void *data2;

    if ( t != NULL){
        int stat = cmp( t->data, key );
        if ( stat < 0 ){
            t->left = abpRemove( t->left, key, cmp, data );
            return t;
        } else if ( stat > 0 ){
            t->right = abpRemove( t->right, key, cmp, data );
            return t;
        } else {
            if ( t->left == NULL && t->right == NULL ){
                *data = t->data;
                free( t );
                return NULL;
            } else if ( t->left == NULL ){
                aux = t->right;
                *data = t->data;
                free( t );
                return aux;
            } else if ( t->right == NULL ){
                aux = t->left;
                *data = t->data;
                free( t );
                return aux;
            } else {
                *data = t->data;
                t->left = abpRemoveMaior( t->left, cmp, &data2 );
                t->data = data2;
                return t;
            }
        }
    }
    *data = NULL;
    return NULL;
}

void *abpGetMin( tNode *t ){
    if ( t != NULL ){
        if ( t->left != NULL ){
            return abpGetMin( t->left );
        } else {
            return t->data;
        }
    }
    return NULL;
}

void *abpGetMax( tNode *t ){
    if ( t != NULL ){
        if ( t->right != NULL ){
            return abpGetMax( t->right );
        } else {
            return t->data;
        }
    }
    return NULL;
}

tNode *abpRemoveMaior( tNode *t, int (*cmp)( void *, void * ), void **data ){
    if ( t != NULL ){    
        void *data2;
        tNode *aux;
        if ( t->right != NULL ){
            t->right = abpRemoveMaior( t->right, cmp, &data2 );
            return t;
        } else {
            if ( t->left != NULL ){
                aux = t->left;
                *data = t->data;
                free( t );
                return aux;
            } else {
                *data = t->data;
                free( t );
                return NULL;
            }
        }
    }
    *data = NULL;
    return NULL;
}

tNode *abpRemoveMenor( tNode *t, int (*cmp)( void *, void * ), void **data ){
    if ( t != NULL ){    
        void *data2;
        tNode *aux;
        if ( t->left != NULL ){
            t->left = abpRemoveMaior( t->left, cmp, &data2 );
            return t;
        } else {
            if ( t->right != NULL ){
                aux = t->right;
                *data = t->data;
                free( t );
                return aux;
            } else {
                *data = t->data;
                free( t );
                return NULL;
            }
        }
    }
    *data = NULL;
    return NULL;
}

void OrdemSimetrica( tNode *t, void ( visit )( void* ) ){
    if( t != NULL){
        OrdemSimetrica(t->left, visit );
        visit(t->data);
        OrdemSimetrica(t->right, visit );
    }
}

void * getData( tNode *t ){
    if ( t != NULL ){
        return t->data;
    }
    return NULL;
}

#endif