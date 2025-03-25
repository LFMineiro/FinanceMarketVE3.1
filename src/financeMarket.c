#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/menu.h"
    
int main() {

    int option; 

    option = showMenu();
    processOption(option);

    return 0;
}
