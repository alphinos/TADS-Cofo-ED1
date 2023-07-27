#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "IO.h"
#include <string.h>

int getUserInput(int *answer){
    scanf("%d", answer);
    while(getchar() != '\n');
}

void main(void){
    Stack *stack;
    int intElm;
    char charElm;
    float floatElm;

    int answer;
    int flagAux = -1;
    int menuTxt = 33;

    char stdColor[] = YELLOW;
    int format = 2;
    int jump = 1;

    do {
        colorPrintNTimes('-', ROW_LEN, jump, stdColor);
        fcprint("[0] - Sair do programa!", format, stdColor, jump, menuTxt);
        fcprint("[1] - Criar pilha!", format, stdColor, jump, menuTxt);
        fcprint("[2] - Inserir na pilha!", format, stdColor, jump, menuTxt);
        fcprint("[3] - Remover  do topo da pilha!", format, stdColor, jump, menuTxt);
        fcprint("[4] - Qual o elemento do topo?", format, stdColor, jump, menuTxt);
        fcprint("[5] - A pilha está vazia?", format, stdColor, jump, menuTxt);
        fcprint("[6] - Destruir pilha!", format, stdColor, jump, menuTxt);
        colorPrintNTimes('-', ROW_LEN, jump, stdColor);

        printf("%s--- Resposta: ", stdColor);
        answer = -1;
        getUserInput(&answer);
        printf("%s", COLOR_RESET);
        switch (answer){
            case 0:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Tchau Tchau :(", format, stdColor, jump, 0);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            case 1:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Quantos elementos queres que caibam na pilha?", format, stdColor, jump, 46);
                printf("%s--- Resposta: ", stdColor);
                answer = -1;
                getUserInput(&answer);
                printf("%s", COLOR_RESET);
                stack = stkCreate(answer);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            case 2:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Qual tipo de elemento desejas inserir?", format, stdColor, jump, 46);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("[0] - Inteiro", format, stdColor, jump, 46);
                fcprint("[1] - Caractere", format, stdColor, jump, 46);
                fcprint("[2] - Ponto flutuante", format, stdColor, jump, 46);
                answer = -1;
                printf("%s", stdColor);
                getUserInput(&answer);
                switch (answer){
                    case 0:
                        getUserInput(&intElm);
                        stkPush((void*)&intElm, stack);
                        break;
                    case 1:
                        scanf("%c", charElm);
                        while(getchar() != '\n');
                        stkPush((void*)&charElm, stack);
                        break;
                    case 2:
                        scanf("%f", floatElm);
                        while(getchar() != '\n');
                        stkPush((void*)&floatElm, stack);
                        break;
                }
                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            case 3:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Removendo o topo da pilha!", format, stdColor, jump, 46);
                answer = *(int *)stkPop(stack);
                printf("%s--- Item removido: ", stdColor);
                printf("%d |||||\n", answer);
                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            case 4:
                answer = *(int *)stkTop(stack);
                if (stkTop(stack) != NULL){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    printf("%s--- Resposta: ", stdColor);
                    printf("- %d |||||\n", answer);
                    printf("%s", COLOR_RESET);
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                } else {
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                    fcprint("Não foi possível retornar o valor do topo", format, stdColor, jump, 46);
                    colorPrintNTimes('-', ROW_LEN, jump, RED);

                }
                break;
            case 5:
                if (isStkEmpty(stack) == TRUE){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    fcprint("Está vazia!", format, stdColor, jump, 46);
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                } else {
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                    fcprint("Não está vazia.", format, RED, jump, 46);
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                }
                break;
            case 6:
                if (isStkEmpty(stack) == TRUE){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    fcprint("Esvaziando pilha...", format, stdColor, jump, 0);
                    while (stkPop(stack) != NULL );
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                } else {
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                    fcprint("Tchau Tchau :(", format, RED, jump, 0);
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                }
                break;
        }

    } while (answer != 0);
}