// Carlos Eduardo Veras Gomes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "IO.h"

void imprimeInt( void *data ){
    if ( data == NULL ){
        printf("NULL ");
        return;
    }
    int num = *( int * ) data;
    printf("%d ", num );
}

int cmpInt( void *a, void *b ){
    int na = *( ( int *) a );
    int nb = *( ( int *) b );

    if ( a == NULL && b == NULL ){
        return 0;
    } else if ( a == NULL ){
        return 1;
    } else if ( b == NULL ){
        return -1;
    }

    printf( "\n\nTeste: na: %d nb: %d\n\n", na, nb);

    if ( na > nb ){
        return 1;
    }
    
    if ( na < nb ){
        return -1;
    }

    return 0;

}

void getUserInput(int *answer){
    scanf("%d", answer);
    while(getchar() != '\n');
}

int main(  ){
    tNode *tree = NULL;
    void *temp;

    int *intElm; // = ( int * ) malloc( sizeof( int ) );

    int answer;
    int menuTxt = 37;

    char stdColor[] = GREEN;
    int format = 0;
    int jump = 1;

    do {
        colorPrintNTimes('-', ROW_LEN, jump, stdColor );
        fcprint( "[0] - Sair do programa!", format, stdColor, jump, menuTxt );
        fcprint( "[1] - Criar árvore!", format, stdColor, jump, menuTxt );
        fcprint( "[2] - Inserir elemento na árvore!", format, stdColor, jump, menuTxt );
        fcprint( "[3] - Remover elemento da árvore!", format, stdColor, jump, menuTxt );
        fcprint( "[4] - Consultar elemento da árvore!", format, stdColor, jump, menuTxt );
        fcprint( "[5] - Listar elemento da árvore!", format, stdColor, jump, menuTxt );
        fcprint( "[6] - Destruir árvore!", format, stdColor, jump, menuTxt );
        colorPrintNTimes('-', ROW_LEN, jump, stdColor);

        printf("%s--- Resposta: ", stdColor);
        answer = -1;
        getUserInput(&answer);
        printf("%s", COLOR_RESET);

        switch ( answer ){
            case 0:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Tchau Tchau :(", format, stdColor, jump, 0);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            
            case 1:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);

                if ( getData( tree ) != NULL ){
                    fcprint("Destrua a árvore atual antes!", format, stdColor, jump, 46);
                } else {
                    tree = createTree( NULL );
                    if ( tree != NULL )
                        fcprint("Árvore criada com sucesso!", format, stdColor, jump, 46);
                    else
                        fcprint("Erro ao criar a árvore!", format, stdColor, jump, 46);
                }

                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;

            case 2:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Qual elemento desejas inserir?", format, stdColor, jump, 46);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);

                intElm = ( int * ) malloc( sizeof( int ) );

                printf("%s--- Item a inserir: ", stdColor);
                getUserInput(intElm);

                if ( getData( tree ) != NULL){
                    printf( "\n\n %d \n\n", *( int *) getData( tree ) );
                }

                if ( getData( tree ) == NULL ){
                    free( tree );
                    tree = createTree( (void*)intElm );
                } else {
                    tree = abpInsert( tree, (void*)intElm, cmpInt );
                    // abpInsert( tree, (void*)intElm, cmpInt );
                    if ( tree != NULL ){
                        fcprint("Elemento inserido!", format, stdColor, jump, 46);
                    } else {
                        fcprint("Não foi possível inserir o elemento!", format, stdColor, jump, 46);
                    }
                }

                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                answer = -1;
                break;

            case 3:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Qual elemento desejas remover?", format, stdColor, jump, 46);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                if ( tree != NULL ){
                    intElm = ( int * ) malloc( sizeof( int ) );
                    getUserInput(intElm);
                    if ( *intElm == -1 && abpQuery( tree, NULL, cmpInt ) != NULL ){
                        tree = abpRemove( tree, NULL, cmpInt, &temp );
                        printf("%s--- Item removido: ", stdColor);
                        printf("NULL |||||\n" );
                    } else if ( abpQuery( tree, (void*)intElm, cmpInt ) != NULL ){
                        tree = abpRemove( tree, (void*)intElm, cmpInt, &temp );
                        printf("%s--- Item removido: ", stdColor);
                        printf("%d |||||\n", *( (int *) temp ) );
                    } else {
                        fcprint("Elemento não foi encontrado.", format, stdColor, jump, 46);
                    }
                } else {
                    fcprint("Primeiro crie a árvore e insira um elemento", format, stdColor, jump, 46);
                }

                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                answer = -1;
                break;
            
            case 4:
                if ( tree != NULL ){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    fcprint("Qual elemento desejas encontrar?", format, stdColor, jump, 46);
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);

                    intElm = ( int * ) malloc( sizeof( int ) );
                    getUserInput(intElm);
                    temp = abpQuery( tree, (void*)intElm, cmpInt );
                    if ( temp == NULL ){
                        printf( "%s --- Item não encontrado! ---\n", stdColor );
                    } else {
                        printf("%s--- Item encontrado: ", stdColor);
                        printf("%d |||||\n", *( (int *) temp ) );
                    }
                }

                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                answer = -1;
                break;
            case 5:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Listando elementos!", format, stdColor, jump, 46);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);

                printf("%sOrdem simétrica:\n", stdColor);
                printf("%s[ ", stdColor);
                
                OrdemSimetrica( tree, imprimeInt );    
                    
                printf("%s]\n", stdColor);

                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                answer = -1;
                break;
            
            case 6:
                if (destroyTree( tree ) == FALSE){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    fcprint("A árvore deve estar vazia!...", format, stdColor, jump, 0);
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                } else {
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                    fcprint("Árvore destruída com sucesso", format, RED, jump, 0);
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                }
                break;

            default:
                colorPrintNTimes('-', ROW_LEN, jump, RED);
                fcprint("Coloque um valor válido!", format, RED, jump, 0);
                colorPrintNTimes('-', ROW_LEN, jump, RED);
                break;
            }
    } while( answer != 0 );
    
    return 0;
}

// I'm assuming that only integers are on the tree
// void main(void){
//     tNode *tree = NULL;

//     void *temp = ( void * ) malloc( sizeof( void ) ); //Pra pegar o retorno dos negócios
//     void *aux;

//     int *intElm = (int *) malloc( sizeof( int ) );

//     int answer;
//     int flagAux = -1;
//     int menuTxt = 37;

//     char stdColor[] = GREEN;
//     int format = 0;
//     int jump = 1;

//     do {
//         colorPrintNTimes('-', ROW_LEN, jump, stdColor );
//         fcprint( "[0] - Sair do programa!", format, stdColor, jump, menuTxt );
//         fcprint( "[1] - Criar árvore!", format, stdColor, jump, menuTxt );
//         fcprint( "[2] - Inserir elemento na árvore!", format, stdColor, jump, menuTxt );
//         fcprint( "[3] - Remover elemento da árvore!", format, stdColor, jump, menuTxt );
//         fcprint( "[4] - Consultar elemento da árvore!", format, stdColor, jump, menuTxt );
//         fcprint( "[5] - Listar elemento da árvore!", format, stdColor, jump, menuTxt );
//         fcprint( "[6] - Destruir árvore!", format, stdColor, jump, menuTxt );
//         colorPrintNTimes('-', ROW_LEN, jump, stdColor);

//         printf("%s--- Resposta: ", stdColor);
//         answer = -1;
//         getUserInput(&answer);
//         printf("%s", COLOR_RESET);
//         switch (answer){
//             case 0:
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 fcprint("Tchau Tchau :(", format, stdColor, jump, 0);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 break;
//             case 1:
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);

//                 if ( tree != NULL ){
//                     fcprint("Destrua a árvore atual antes!", format, stdColor, jump, 46);
//                 } else {
//                     tree = createTree( NULL );
//                     if ( tree != NULL )
//                         fcprint("Árvore criada com sucesso!", format, stdColor, jump, 46);
//                     else
//                         fcprint("Erro ao criar a árvore!", format, stdColor, jump, 46);
//                 }

//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 break;
//             case 2:
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 fcprint("Qual elemento desejas inserir?", format, stdColor, jump, 46);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);

//                 printf("%s--- Item a inserir: ", stdColor);
//                 getUserInput(intElm);

//                 if ( getData( tree ) == NULL ){
//                     free( tree );
//                     tree = createTree( (void*)intElm );
//                     printf( "\n\n%d\n\n", *( (int *) getData( tree ) ) );
//                 } else {
//                     tree = abpInsert( tree, (void*)intElm, cmpInt );
//                     if ( tree != NULL ){
//                         fcprint("Elemento inserido!", format, stdColor, jump, 46);
//                     } else {
//                         fcprint("Não foi possível inserir o elemento!", format, stdColor, jump, 46);
//                     }
//                 }

//                 printf("%s", COLOR_RESET);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 answer = -1;
//                 break;
//             case 3:
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 fcprint("Qual elemento desejas remover?", format, stdColor, jump, 46);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 if ( tree == NULL ){
//                     getUserInput(intElm);
//                     if ( abpQuery( tree, (void*)intElm, cmpInt ) != NULL){
//                         tree = abpRemove( tree, (void*)intElm, cmpInt, &temp );
//                         printf("%s--- Item removido: ", stdColor);
//                         printf("%d |||||\n", *( (int *) temp ) );
//                     } else {
//                         fcprint("Elemento não foi encontrado.", format, stdColor, jump, 46);
//                     }
//                 } else {
//                     fcprint("Primeiro crie a árvore e insira um elemento", format, stdColor, jump, 46);
//                 }

//                 printf("%s", COLOR_RESET);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 answer = -1;
//                 break;
//             case 4:
//                 if ( tree != NULL ){
//                     colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                     fcprint("Qual elemento desejas encontrar?", format, stdColor, jump, 46);
//                     colorPrintNTimes('-', ROW_LEN, jump, stdColor);

//                     getUserInput(intElm);
//                     aux = abpQuery( tree, (void*)intElm, cmpInt );
//                     if ( aux == NULL ){
//                         printf( "%s --- Item não encontrado! ---\n", stdColor );
//                     } else {
//                         printf("%s--- Item encontrado: ", stdColor);
//                         printf("%d |||||\n", *( (int *) aux ) );
//                     }
//                 }

//                 printf("%s", COLOR_RESET);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 answer = -1;
//                 break;
//             case 5:
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 fcprint("Listando elementos", format, stdColor, jump, 46);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);

//                 printf("%sOrdem simétrica:\n", stdColor);
//                 printf("%s[ ", stdColor);
                
//                 OrdemSimetrica( tree, imprimeInt );    
                    
//                 printf("%s]\n", stdColor);

//                 printf("%s", COLOR_RESET);
//                 colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 answer = -1;
//                 break;
//             case 6:
//                 if (destroyTree( tree ) == FALSE){
//                     colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                     fcprint("A árvore deve estar vazia!...", format, stdColor, jump, 0);
//                     colorPrintNTimes('-', ROW_LEN, jump, stdColor);
//                 } else {
//                     colorPrintNTimes('-', ROW_LEN, jump, RED);
//                     fcprint("Tchau Tchau :(", format, RED, jump, 0);
//                     colorPrintNTimes('-', ROW_LEN, jump, RED);
//                 }
//                 break;
//         }

//     } while (answer != 0);
// }