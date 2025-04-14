#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/association.h"
#include "../headers/menu.h"

    
int main() {
    
    int option; 

    option = showMenu();
    processOption(option);
        // char period[7];
        // printf("Em qual periodo foi comprado (2025.1, 2025.2, 2024.1): ");
        // scanf("%s", period);
        // printf(" %c", period[4]);

    return 0;
}
