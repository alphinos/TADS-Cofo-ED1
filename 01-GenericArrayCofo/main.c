//Carlos Eduardo Veras Gomes - 3º período 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gcofo.h"

typedef struct _Product_{
    char name[30];
    int id;
    int amtStock;
    float price;
} Product;

int getUserInput(int *answer){
    scanf("%d", answer);
    while(getchar() != '\n');
}

int findByName( void* item, void* key ){
    Product* temp = (Product*)item;
    if (strcmp(temp->name, (char *)key) == FALSE)
        return TRUE;
    return FALSE;
}

int findByID( void* item, void* key ){
    Product* temp = (Product*)item;
    if ( temp->id == *(int*)key )
        return TRUE;
    return FALSE;
}

int findByPrice( void* item, void* key ){
    Product* temp = (Product*)item;
    if ( temp->price == *(float*)key )
        return TRUE;
    return FALSE;
}

void main(void){
    gCofo *cofo = NULL;
    Product *product;

    int answer = -1;
    int flagAux = -1;

    char name[30];
    int id;
    float price;

    do {
        printf("--------------------------------------------------------------\n");
        printf("- [0] - Sair do programa!             ------------------------\n");
        printf("- [1] - Criar o cofo!                 ------------------------\n");
        printf("- [2] - Inserir um produto no cofo!   ------------------------\n");
        printf("- [3] - Remover produto!              ------------------------\n");
        printf("- [4] - Achar produto!                ------------------------\n");
        printf("- [5] - Mostrar os elementos do cofo! ------------------------\n");
        printf("- [6] - Esvaziar o cofo!              ------------------------\n");
        printf("- [7] - Destruir o cofo!              ------------------------\n");
        printf("--------------------------------------------------------------\n");
        answer = -1;
        getUserInput(&answer);
        switch(answer){
            case 0:
                flagAux = TRUE;
                if (cofo != NULL)
                    flagAux = FALSE;
                while(flagAux != TRUE){
                    gCofEmpty(cofo);
                    flagAux = gCofDestroy(cofo);
                }
                printf("--------------------------------------------------------------\n");
                printf("----------------------- Tchau tchau :( -----------------------\n");
                printf("--------------------------------------------------------------\n");
                break;
            case 1:
                printf("--------------------------------------------------------------\n");
                printf("- Qual a quantidade de itens que desejas que caibam no cofo? -\n");
                printf("--------------------------------------------------------------\n");
                getUserInput(&answer);

                cofo = gCofCreate(answer);
                if (cofo == NULL){
                    printf("--------------------------------------------------------------\n");
                    printf("-------------- Não foi possível criar o cofo :( --------------\n");
                    printf("--------------------------------------------------------------\n");
                }

                break;
            case 2:
                product = (Product*)malloc(sizeof(Product));
                if (product == NULL){
                    printf("--------------------------------------------------------------\n");
                    printf("---------- Não será possível inicializar o produto. ----------\n");
                    printf("--------------------------------------------------------------\n");
                }

                printf("--------------------------------------------------------------\n");
                printf("-- Insira os dados do produto que desejas inserir no cofo. ---\n");
                printf("--------------------------------------------------------------\n");

                printf("--------------------------------------------------------------\n");
                printf("-- Nome:                  ------------------------------------\n");
                scanf("%s", &product->name);
                while(getchar() != '\n');
                printf("-- Id                     ------------------------------------\n");
                getUserInput(&product->id);
                printf("-- Quantidade em estoque: ------------------------------------\n");
                getUserInput(&product->amtStock);
                printf("-- Preço:                 ------------------------------------\n");
                scanf("%f", &product->price);
                while(getchar() != '\n');
                printf("--------------------------------------------------------------\n");

                flagAux = gCofInsert(cofo, (void*)product);

                if (flagAux == TRUE){
                    printf("--------------------------------------------------------------\n");
                    printf("----- O produto de id: '%d' foi adicionado com sucesso. ------\n",
                        product->id);
                    printf("--------------------------------------------------------------\n");
                }
                else if (flagAux == FALSE){
                    printf("--------------------------------------------------------------\n");
                    printf("------- Não foi possível inserir o produto no cofo... --------\n");
                    printf("--------------------------------------------------------------\n");
                }

                break;
            case 3:
                printf("--------------------------------------------------------------\n");
                printf("----- Escolha de que maneira desejas remover o elemento. -----\n");
                printf("--------------------------------------------------------------\n");
                printf("- [1] - Nome  ------------------------------------------------\n");
                printf("- [2] - ID    ------------------------------------------------\n");
                printf("- [3] - Preço ------------------------------------------------\n");
                printf("--------------------------------------------------------------\n");
                getUserInput(&answer);
                switch (answer){
                    case 1:
                        scanf("%s", name);
                        while(getchar() != '\n');
                        product = (Product *)gCofRemove(cofo, (void*)name, &findByName);
                        break;
                    case 2:
                        scanf("%d", &id);
                        while(getchar() != '\n');
                        product = (Product *)gCofRemove(cofo, (void*)&id, &findByID);
                        break;
                    case 3:
                        scanf("%f", &price);
                        while(getchar() != '\n');
                        product = (Product *)gCofRemove(cofo, (void*)&price, &findByPrice);
                        break;
                    default:
                        printf("--------------------------------------------------------------\n");
                        printf("---- Busca por dado inválido! --------------------------------\n");
                        printf("--------------------------------------------------------------\n");
                }

                if (product == NULL){
                    printf("--------------------------------------------------------------\n");
                    printf("---- O produto não foi encontrado... -------------------------\n");
                    printf("--------------------------------------------------------------\n");
                    break;
                }

                printf("--------------------------------------------------------------\n");
                printf("- Produto removido: %s ---------------------------------------\n",
                    product->name);
                printf("- Estoque: %d ------------------------------------------------\n",
                    product->amtStock);
                printf("- Id: %d      ------------------------------------------------\n",
                    product->id);
                printf("- Preço: %.2f   ------------------------------------------------\n",
                    product->price);
                printf("--------------------------------------------------------------\n");

                if (answer == 0)
                    answer = -1;
                break;
            case 4:
                printf("--------------------------------------------------------------\n");
                printf("--- Escolha de que maneira desejas procurar pelo elemento. ---\n");
                printf("--------------------------------------------------------------\n");
                printf("- [1] - Nome  ------------------------------------------------\n");
                printf("- [2] - ID    ------------------------------------------------\n");
                printf("- [3] - Preço ------------------------------------------------\n");
                printf("--------------------------------------------------------------\n");

                getUserInput(&answer);
                switch (answer){
                    case 1:
                        scanf("%s", name);
                        while(getchar() != '\n');
                        product = (Product *)gCofQuery(cofo, (void*)name, &findByName);
                        break;
                    case 2:
                        scanf("%d", &id);
                        while(getchar() != '\n');
                        product = (Product *)gCofQuery(cofo, (void*)&id, &findByID);
                        break;
                    case 3:
                        scanf("%f", &price);
                        while(getchar() != '\n');
                        product = (Product *)gCofQuery(cofo, (void*)&price, &findByPrice);
                        break;
                    default:
                        printf("--------------------------------------------------------------\n");
                        printf("---- Busca por dado inválido! :( -----------------------------\n");
                        printf("--------------------------------------------------------------\n");
                }

                printf("--------------------------------------------------------------\n");
                printf("- Produto: %s ---------------------------------------\n",
                    product->name);
                printf("- Estoque: %d ------------------------------------------------\n",
                    product->amtStock);
                printf("- Id: %d      ------------------------------------------------\n",
                    product->id);
                printf("- Preço: %.2f   ------------------------------------------------\n",
                    product->price);
                printf("--------------------------------------------------------------\n");

                if (answer == 0)
                    answer = -1;
                break;
            case 5:
                printf("Os elementos da coleção são:\n");

                product = (Product*)gCofGetFirst(cofo);

                while(product != NULL){
                    printf("--------------------------------------------------------------\n");
                    printf("- Produto: %s          ----------------------------------------\n",
                        product->name);
                    printf("- Estoque: %d          ----------------------------------------\n",
                        product->amtStock);
                    printf("- Id: %d               ----------------------------------------\n",
                        product->id);
                    printf("- Preço: %.2f          ---------------------------------------\n",
                        product->price);
                    printf("--------------------------------------------------------------\n");
                    product = gCofGetNext(cofo);
                }
                break;
            case 6:
                printf("--------------------------------------------------------------\n");
                printf("--- O cofo será esvaziado! -----------------------------------\n");
                printf("--------------------------------------------------------------\n");
                int i = 0;
                flagAux = gCofEmpty(cofo);
                if (flagAux != 0){
                    printf("--------------------------------------------------------------\n");
                    printf("--- Não foi possível esvaziar o cofo! ------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                else{
                    printf("--------------------------------------------------------------\n");
                    printf("--- O cofo foi esvaziado com sucesso! ------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                break;
            case 7:
                printf("--------------------------------------------------------------\n");
                printf("--- O cofo será destruído! -----------------------------------\n");
                printf("--------------------------------------------------------------\n");
                flagAux = gCofDestroy(cofo);
                if (flagAux == TRUE){
                    printf("--------------------------------------------------------------\n");
                    printf("--- Cofo destruído com sucesso. ------------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                else {
                    printf("--------------------------------------------------------------\n");
                    printf("--- O cofo não pôde ser destruído! ---------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                break;
        }
    } while (answer != 0);
}