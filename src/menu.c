#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/association.h"


int showMenu() {

    int opcao;

    printf("Acoes:\n");
    printf("1 - Cadastrar um novo Investidor\n");
    printf("2 - Remover um Investidor\n");
    printf("3 - Cadastrar um novo Ativo\n");
    printf("4 - Remover um Ativo\n");
    printf("5 - Comprar um Ativo\n"); ///MUDAR DEPOIS
    printf("5 - Listar todos Investidores cadastrados\n");
    printf("6 - Listar todos Ativos cadastrados\n");
    printf("7 - Sair \n\n");
    

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    printf("\n\n");

    return opcao;

}
void processOption(int option) {
        
    // Variaveis para criaçao do Investidor
    int id;

    // Variaveis para criacao do Ativo
    int cod;
    
    loadAssets();
    loadInvestors();
    loadAssociations();

    switch(option) {
        
        case 1: 

            // Form de Criação
            registerInvestor();
            break;

        case 2: 

            // Remoção por código da lista de investidores
            printf("codigo do deletado: ");
            scanf("%d", &id);
    
            // Função para deletar o Investidor da lista
            deleteInvestor(id);
            break;
    
        case 3:
        
            registerAsset();
            break;
            
        case 4:

            // Remoção por código da lista de Ativos
            printf("codigo do deletado: ");
            scanf(" %d", &cod);
    
            // Função para deletar o Ativo da lista e da memória
            deleteAsset(cod);
            
            break;

        case 5:
            registerAssociation();
            break;

        case 6: 
            printInvestor();
            break;
        case 7:
            printAssets();
            break;
        default: 
            printf("digite uma opção valida");
            break;
    }

    saveAssociations();
    saveAssets();
    saveInvestors();
}
