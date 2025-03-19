#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"
// #include "asset.c"
    
int showMenu() {

    int opcao;

    printf("Acoes:\n");
    printf("1 - Cadastrar um novo investidor\n");
    printf("2 - Remover um investidor\n");
    printf("3 - Cadastrar uma nova transacao\n");
    printf("4 - Remover uma transacao\n");
    printf("5 - Sair \n\n");

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    return opcao;

}

// 1 - Create Ok!
// 2 - Delete Ok!

// ExistingId function

// Switch function 

// Merge in Investors and Assets functions

// 

int main() {

    int option; 

    option = showMenu();
    char name[50];
    int id;
    char profile[35];

    
    switch(option) {
        case 1: 
        
        printf("Cadastro do Investidor\n\n");                    
        printf("Nome: ");
        scanf(" %s", &name );                     
        printf("Codigo: ");
        scanf("%d", &id);  
        printf("Perfil: ");
        scanf(" %s", &profile );  
        
            loadInvestors();
            createInvestor(id, name, profile);
            printInvestor();
            saveInvestors();
            break;

        case 2: 

            printf("codigo do deletado: ");
            scanf("%d", &id);

            loadInvestors();

            deleteInvestor(id);

            saveInvestors();

            break;

        case 3:
        break;
        case 4:
        break;

    }
    // loadInvestors();
    // // createInvestor(1,"alissu", "conservador");
    // printInvestor();
    // saveInvestors();
    
    return 0;
}
