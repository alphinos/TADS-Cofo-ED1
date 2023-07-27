#include "nQueens.h"
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    clock_t start_t, end_t;
    double total_t;
    start_t = clock();

    int nQueens;

    colorPrintNTimes('-', ROW_LEN, 1, BOLD_RED);
    printf( BOLD_RED "------------ | Por favor, informe quantas rainhas desejas criar. | -------------" COLOR_RESET "\n");
    colorPrintNTimes('-', ROW_LEN, 1, BOLD_RED);

    printf( BOLD_RED );
    scanf("%d" , &nQueens);
    printf(COLOR_RESET);
    printf("\n");

    table *tab = createTable(nQueens);

    unsigned long iter = fulfillMap(tab);

    if ( iter == -1 ){
        printf( BOLD_RED "Não foi possível resolver o problema das N rainhas!" COLOR_RESET "\n");
        return 1;
    }

    printf( BOLD_RED "Quantidade de iterações: %lu." COLOR_RESET "\n", iter);
    printf("\n");

    blockStr *bMap = getStrTab( tab );

    printf("\n");
    colorPrintNTimes('-', ROW_LEN, 1, BOLD_RED);
    colorPrintNTimes('-', ROW_LEN, 1, BOLD_RED);
    printfBlock(bMap, 1, BOLD_RED, 1, 0);
    colorPrintNTimes('-', ROW_LEN, 1, BOLD_RED);
    colorPrintNTimes('-', ROW_LEN, 1, BOLD_RED);
    printf("\n");

    destroyTable(tab);
    emptyBlockSTR(bMap);
    destroyBlockSTR(bMap);

    end_t = clock();
    total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n");
    printf( BOLD_RED "Tempo total de execução do programa: %f." COLOR_RESET "\n", total_t);

    return 0;
}