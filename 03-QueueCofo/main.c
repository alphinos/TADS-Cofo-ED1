#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "IO.h"
#include <string.h>

int getUserInput(int *answer){
    scanf("%d", answer);
    while(getchar() != '\n');
}

// I'm assuming that only integers are on the 
void main(void){
    Queue *queue;
    void *temp;
    int *intElm;
    char *charElm;
    float *floatElm;

    int answer;
    int flagAux = -1;
    int menuTxt = 37;

    char stdColor[] = GREEN;
    int format = 0;
    int jump = 1;

    do {
        colorPrintNTimes('-', ROW_LEN, jump, stdColor);
        fcprint("[0] - Sair do programa!", format, stdColor, jump, menuTxt);
        fcprint("[1] - Criar fila!", format, stdColor, jump, menuTxt);
        fcprint("[2] - Inserir na fila!", format, stdColor, jump, menuTxt);
        fcprint("[3] - Remover  do início da fila!", format, stdColor, jump, menuTxt);
        fcprint("[4] - Qual o elemento da frente?", format, stdColor, jump, menuTxt);
        fcprint("[5] - A fila está vazia?", format, stdColor, jump, menuTxt);
        fcprint("[6] - Destruir fila!", format, stdColor, jump, menuTxt);
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
                fcprint("Quantos elementos queres que caibam na fila?", format, stdColor, jump, 46);
                printf("%s--- Resposta: ", stdColor);
                answer = -1;
                getUserInput(&answer);
                printf("%s", COLOR_RESET);
                queue = qCreate(answer);
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
                        getUserInput(intElm);
                        qEnQueue((void*)&intElm, queue);
                        break;
                    case 1:
                        scanf("%c", charElm);
                        while(getchar() != '\n');
                        qEnQueue((void*)&charElm, queue);
                        break;
                    case 2:
                        scanf("%f", floatElm);
                        while(getchar() != '\n');
                        qEnQueue((void*)&floatElm, queue);
                        break;
                }
                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            case 3:
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                fcprint("Removendo o primeiro da fila!", format, stdColor, jump, 46);
                answer = *(int *)qDeQueue(queue);
                printf("%s--- Item removido: ", stdColor);
                printf("%d |||||\n", answer);
                printf("%s", COLOR_RESET);
                colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                break;
            case 4:
                intElm = (int *)qFirst(queue);
                if (intElm != NULL){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    printf("%s--- Resposta: ", stdColor);
                    printf("- %d |||||\n", *intElm);
                    printf("%s", COLOR_RESET);
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                } else {
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                    fcprint("Não foi possível retornar o valor da frente", format, stdColor, jump, 46);
                    colorPrintNTimes('-', ROW_LEN, jump, RED);

                }
                break;
            case 5:
                if (qIsEmpty(queue) == TRUE){
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
                if (qIsEmpty(queue) == FALSE){
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    fcprint("Esvaziando fila...", format, stdColor, jump, 0);
                    while (qDeQueue(queue) != NULL );
                    colorPrintNTimes('-', ROW_LEN, jump, stdColor);
                    qDestroy(queue);
                } else {
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                    fcprint("Tchau Tchau :(", format, RED, jump, 0);
                    colorPrintNTimes('-', ROW_LEN, jump, RED);
                }
                break;
        }

    } while (answer != 0);
}