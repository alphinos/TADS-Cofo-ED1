#ifndef _IO_C_
#define _IO_C_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"

void printNTimes( char c, int n, int jump ){
    for (int i = 0; i < n; i++){
        printf("%c", c);
    }
    if (jump == TRUE)
        printf("\n");
}

void colorPrintNTimes( char c, int n, int jump, char color[] ){
        if (color == NULL){
            printNTimes(c, n, jump);
        } else {
            for (int i = 0; i < n; i++){
                printf( "%s%c" COLOR_RESET, color, c);
            }
            printf( COLOR_RESET );
        }
    if (jump == TRUE)
        printf( COLOR_RESET "\n");

        //     printf(color);
        //     printNTimes(c, n, FALSE);
        //     printf( COLOR_RESET );
        // }
}

int fcprint( char string[], int alignment, char color[], int jump, int sizeTxt ){
    if (string == NULL)
        return FALSE;
    if (alignment < 0 || alignment > 2)
        return FALSE;
    if (strlen(string) + 2 >= ROW_LEN)
        return FALSE;
    if (sizeTxt < 0)
        return FALSE;

    Line *line = (Line *) malloc( sizeof(Line) );

    if (line == NULL)
        return FALSE;

    line->rowLength = ROW_LEN;

    char *auxStr = (char *) malloc( sizeof(char) * ( 2 * (strlen(string) ) + 1 + 4));
    auxStr[0] = ' ';
    auxStr[1] = '|';
    auxStr[2] = ' ';
    auxStr[ strlen(string) + 1 ] = '\0';
    strcat(auxStr, string);
    for (int i = 0; i < strlen(string); i++){
        auxStr[ 2*i + 3] = string[i];
        auxStr[ 2*i + 1 + 3] = ' '; 
    }
    strcat(auxStr, "| ");

    line->main = auxStr;

    line->mainLength = strlen(auxStr);
    int totalMargin = 0;
    if (sizeTxt == 0){
        totalMargin = ROW_LEN - line->mainLength;
    } else {
        totalMargin = ROW_LEN - sizeTxt -1 ;
    }
    if (alignment == 1){
        line->leftMargin = totalMargin / 2;
        line->rightMargin = totalMargin / 2;
        line->rightMargin += totalMargin % 2;
    } else if (alignment == 0){
        if (totalMargin > 2){
            line->leftMargin = 3;
            line->rightMargin = totalMargin - line->leftMargin;
        } else {
            line->leftMargin = 1;
            line->rightMargin = 1;
        }
    } else if (alignment == 2) {
        if (totalMargin > 2){
            line->rightMargin = 3;
            line->leftMargin = totalMargin - line->rightMargin;
        } else {
            line->leftMargin = 1;
            line->rightMargin = 1;
        }
    }

    auxStr = (char *) malloc( sizeof(char) * ROW_LEN + 1);
    auxStr[ROW_LEN - 1] = '\0';
    line->marginChar = MARGIN_CHAR;

    for (int i = 0; i < line->leftMargin; i++){
        auxStr[i] = line->marginChar;
    }

    for (int i = 0; i < line->mainLength; i++){
        auxStr[ line->leftMargin + i ] = line->main[i];
    }

    int ctt = 0;
    if ( sizeTxt != 0 ){
        ctt = sizeTxt - line->mainLength + 1;
        if (ctt == 6){
            ctt = 7;
        }

        for (int i = 0; i < ctt; i++){
            auxStr[ line->leftMargin + line->mainLength + i ] = SPACE;
        }
    }

    for (int i = 0; i < line->rightMargin; i++){
        auxStr[ line->leftMargin + line->mainLength + ctt + i] = line->marginChar;
    }

    line->content = auxStr;

    if (color == NULL){
        printf(line->content);
    } else {
        printf("%s", color);
        printf(line->content);
        printf("%s", COLOR_RESET);
    }

    if (jump == 1){
        printf("\n");
        return TRUE;
    }
    return TRUE;
}


#endif