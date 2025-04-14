#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/association.h"
#include "../headers/menu.h"

    
int main() {
    
    int option; 
    char isContinue = 'S';

    printf("========================================\n");
    printf("  Bem-vindo ao Sistema de Investimentos  \n");
    printf("========================================\n\n");

    while(isContinue == 's' || isContinue == 'S'){
        option = showMenu();
        processOption(option);
            printf("Voce deseja continuar?\n[S]-Sim [N]-Nao \n");
            scanf(" %c", &isContinue);
        
        while (isContinue != 'S' && isContinue != 's' &&
            isContinue != 'N' && isContinue != 'n') {
                printf("Resposta invalida. Tente novamente.\n[S] - Sim  [N] - Nao\n");
                scanf(" %c", &isContinue);
     }
        
    }

    return 0;
}
