// Discente: Carlos Eduardo Veras Gomes

#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

#define TRUE 1
#define FALSE 0

#define MARGIN_L 14

void printNtimes(char c, int n, int jump){
    for (int i = 0; i < n; i++){
        printf("%c", c);
    }
    if (jump == TRUE)
        printf("\n");
}

void printTAD(){
    printNtimes('-', 38, 0);
    printf(" TAD ");
    printNtimes('-', 37, 1);
}

void printMainMenu(){
    printNtimes('-', 80, 1);

    printTAD();

    printNtimes('-', 20, 0);
    printf(" O que você gostaria de executar agora? ");
    printNtimes('-', 20, 1);

    printNtimes('-', 3, 0);
    printf(" Digite o número correspondente à instrução a ser executada e seja feliz! ");
    printNtimes('-', 3, 1);

    printNtimes('-', 80, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 0 - Sair do TAD ");
    printNtimes(' ', 25, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 1 - Criar o cofo");
    printNtimes(' ', 25, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 2 - Inserir inteiro no cofo ");
    printNtimes(' ', 13, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 3 - Remover inteiro do cofo ");
    printNtimes(' ', 13, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 4 - Achar a chave no cofo ");
    printNtimes(' ', 15, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 5 - Destruir o cofo ");
    printNtimes(' ', 21, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', MARGIN_L, 0);
    printf(" 6 - Mostrar elementos presentes no cofo ");
    printNtimes(' ', 1, 0);
    printNtimes('-', 24, 1);

    printNtimes('-', 80, 1);
}

void printCreateInterface(){
    printNtimes('-', 80, 1);

    printTAD();

    printNtimes('-', 80, 1);

    printNtimes('-', MARGIN_L + 2, 0);
    printf(" Quantos elementos desejas que caibam no cofo? ");
    printNtimes('-', 17, 1);

    printNtimes('-', 80, 1);
}

void printInsertInterface(){
    printNtimes('-', 80, 1);

    printTAD();

    printNtimes('-', 80, 1);

    printNtimes('-', MARGIN_L + 6, 0);
    printf(" Qual elemento desejas inserir no cofo? ");
    printNtimes('-', 20, 1);

    printNtimes('-', 80, 1);
}

void printRemoveInterface(){
    printNtimes('-', 80, 1);

    printTAD();

    printNtimes('-', 80, 1);

    printNtimes('-', MARGIN_L + 6, 0);
    printf(" Qual elemento desejas remover do cofo? ");
    printNtimes('-', 20, 1);

    printNtimes('-', 80, 1);
}

void printQueryInterface(){
    printNtimes('-', 80, 1);

    printTAD();

    printNtimes('-', 80, 1);

    printNtimes('-', MARGIN_L + 1, 0);
    printf(" Qual elementos desejas verificar se está no cofo? ");
    printNtimes('-', MARGIN_L, 1);

    printNtimes('-', 80, 1);
}

void printDestroyInterface(){
    printNtimes('-', 80, 1);

    printTAD();

    printNtimes('-', 80, 1);

    printNtimes('-', MARGIN_L + 8, 0);
    printf(" Desejas realmente destruir o cofo? ");
    printNtimes('-', MARGIN_L + 8, 1);

    printNtimes('-', MARGIN_L + 7, 0);
    printf(" Digite '1' para sim ou '0' para não! ");
    printNtimes('-', MARGIN_L + 7, 1);

    printNtimes('-', 80, 1);
}

int getUserInput(){
    int answer;

    printNtimes('|', MARGIN_L, 0);

    printNtimes(' ', 2, 0);
    scanf("%d", &answer);
    while(getchar() != '\n');

    return answer;
}

void main(void){
    Cofo *cofo;
    int elemento, status;
    int answer = -1;
    int InterfaceAns = -1;
    int flag = 0;

    do {
        printMainMenu();
        answer = getUserInput();

        switch (answer){
            case 1:
                do {
                    printCreateInterface();
                    InterfaceAns = getUserInput();
                    cofo = cofCreate(InterfaceAns);
                    if (cofo == NULL){
                        printf("Deu ruim :D\n");
                    }
                    printNtimes('-', MARGIN_L + 10, 0);
                    printf(" [Aperte Enter para continuar] ");
                    printNtimes('-', MARGIN_L + 11, 1);
                } while(getchar() != '\n');
                break;
            case 2:
                do {
                    printInsertInterface();
                    InterfaceAns = getUserInput();
                    flag = cofInsert(cofo, InterfaceAns);
                    if (!flag){
                        printf("Deu ruim :D\n");
                    }
                    printNtimes('-', MARGIN_L + 10, 0);
                    printf(" [Aperte Enter para continuar] ");
                    printNtimes('-', MARGIN_L + 11, 1);
                } while(getchar() != '\n');
                break;
            case 3:
                do {
                    printRemoveInterface();
                    InterfaceAns = getUserInput();
                    flag = cofRemove(cofo, InterfaceAns);
                    if (!flag){
                        printf("Deu ruim :D\n");
                    }
                    printNtimes('-', MARGIN_L + 10, 0);
                    printf(" [Aperte Enter para continuar] ");
                    printNtimes('-', MARGIN_L + 11, 1);
                } while(getchar() != '\n');
                break;
            case 4:
                do {
                    printQueryInterface();
                    InterfaceAns = getUserInput();
                    flag = cofQuery(cofo, InterfaceAns);
                    if (!flag){
                        printf("Deu ruim :D\n");
                    }
                    printNtimes('-', MARGIN_L + 10, 0);
                    printf(" [Aperte Enter para continuar] ");
                    printNtimes('-', MARGIN_L + 11, 1);
                } while(getchar() != '\n');
                break;
            case 5:
                do {
                    printDestroyInterface();
                    InterfaceAns = getUserInput();
                    if (InterfaceAns == 1){
                        flag = cofDestroy(cofo);
                        if (!flag){
                            printf("Deu ruim :D\n");
                        }
                    } else if (InterfaceAns == 0){
                        printf("Vai destruir nada não :D\n");
                    } else {
                        printf("Deu ruim :D\n");
                    }
                    printNtimes('-', MARGIN_L + 10, 0);
                    printf(" [Aperte Enter para continuar] ");
                    printNtimes('-', MARGIN_L + 11, 1);
                } while(getchar() != '\n');
                break;
            case 6:
                do {
                    printNtimes('-', 80, 1);
                    printNtimes('-', MARGIN_L, 0);
                    printf(" [ ");
                    for (int i = 0; i < cofo->numItens; i++){
                        if (i == cofo->numItens - 1){
                            printf("%d ", cofo->item[i]);
                            break;
                        }
                        printf("%d, ", cofo->item[i]);
                    }
                    printf("]\n");
                    printNtimes('-', 80, 1);
                    printNtimes('-', MARGIN_L + 10, 0);
                    printf(" [Aperte Enter para continuar] ");
                    printNtimes('-', MARGIN_L + 11, 1);
                } while(getchar() != '\n');
        }
    } while (answer != 0);
}