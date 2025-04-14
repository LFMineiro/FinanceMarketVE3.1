#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/association.h"
#include "../headers/menu.h"

    
int main() {
    
    int option; 

    printf("========================================\n");
    printf("  Bem-vindo ao Sistema de Investimentos  \n");
    printf("========================================\n\n");

    while(1){
        option = showMenu();
        processOption(option);
    }

    return 0;
}
