#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/association.h"
#include "../headers/menu.h"

/*
    POR FAVOR SENHOR MONITOR, LEIA O README PRA VER O ENUNCIADO
*/

int main() {
    
    int option; 
    char isContinue = 'S';

    printf("========================================\n");
    printf("  Bem-vindo ao Sistema de Investimentos  \n");
    printf("========================================\n\n");

    while(isContinue == 's' || isContinue == 'S'){
        option = showMenu();
        processOption(option);

        printf("\nVoce deseja continuar?\n[S]-Sim\n");
        scanf(" %c", &isContinue);
        
    }

    printf("\nFechando programa. \n");


    return 0;
}
