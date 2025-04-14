#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/investor.h"
#include "../headers/asset.h"
#include "../headers/association.h"


int showMenu() {

    int opcao;
    printf("\n1 - Cadastrar um novo Investidor\n");
    printf("2 - Remover um Investidor\n");
    printf("3 - Cadastrar um novo Ativo\n");
    printf("4 - Remover um Ativo\n");
    printf("5 - Comprar um Ativo (Associar Ativo a Investidor)\n"); ///MUDAR DEPOIS
    printf("6 - Listar todos Investidores cadastrados\n");
    printf("7 - Listar todos Ativos cadastrados\n");
    printf("8 - Filtrar Ativos por Investidor e Periodo\n");  
    printf("9 - Filtrar Investidores por Ativo e Periodo\n");  
    printf("10 - Sair \n\n");
    

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

            registerInvestor();
            break;

        case 2: 

            printInvestor();

            // Remoção por código da lista de investidores
            int existInvestor = 0;
            while (!existInvestor){
                printf("Codigo do Investidor a ser removido: ");
                scanf("%d", &id);
        
                existInvestor = idInvestorExist(id);
                if(!existInvestor){
                    printf("Nao existe Investidor com esse codigo\n");
                }
            }
    
            // Função para deletar o Investidor da lista
            deleteInvestor(id);
            printf("Investidor removido com sucesso!\n");

            break;
    
        case 3:
        
            registerAsset();
            break;
            
        case 4:

            printAssets();
            // Remoção por código da lista de Ativos
            int existAsset = 0;
            while (!existAsset){
                printf("Codigo do Ativo a ser removido: ");
                scanf("%d", &cod);
        
                existAsset = idAssetExist(cod);
                if(!existAsset){
                    printf("Nao existe Ativo com esse codigo\n");
                }
            }
    
            // Função para deletar o Ativo da lista e da memória
            deleteAsset(cod);
            printf("Ativo removido com sucesso!\n");
            
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
        case 8:
            getAssetsByInvestorAndPeriod();
            break;
        case 9:
            getInvestorsByAssetAndPeriod();
            break;
        
        case 10:
            printf("Fechando programa. \n");
            exit(0);

        default: 
            printf("Digite uma opcao valida \n");
            break;
    }

    saveAssociations();
    saveAssets();
    saveInvestors();
}
