#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/menu.h"
#include "../headers/investor.h"
#include "../headers/asset.h"


int showMenu() {

    int opcao;

    printf("Acoes:\n");
    printf("1 - Cadastrar um novo investidor\n");
    printf("2 - Remover um investidor\n");
    printf("3 - Cadastrar uma nova transacao\n");
    printf("4 - Remover uma transacao\n");
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

    char name[50];
    int id;
    char profile[35];

    // Variaveis para criacao do Ativo

    int cod;
    char type[15];
    char ticker[15];
    float price;
    char risk;

    
    switch(option) {
        
        case 1: 

            // Form de Criação
            
            printf("Cadastro do Investidor\n\n");                    
            printf("Nome: ");
            scanf(" %s", name );                     
            printf("Codigo: ");
            scanf("%d", &id);  
            printf("Perfil: ");
            scanf(" %s", profile );  
    
            // Função para Cadastro do Investidor
            
            loadInvestors();
            createInvestor(id, name, profile);
            printInvestor(); 
            saveInvestors();
            
            break;

        case 2: 

            // Remoção por código da lista de investidores
    
            printf("codigo do deletado: ");
            scanf("%d", &id);
    
            // Função para deletar o Investidor da lista
    
            loadInvestors();
            deleteInvestor(id);
            saveInvestors();
    
            break;
    
        case 3:
        
            printf("Cadastro do Ativo\n\n");                    
            printf("Ticker: ");
            scanf(" %s", ticker );                     
            printf("Codigo: ");
            scanf("%d", &cod);  
            printf("Tipo: ");
            scanf(" %s", type ); 
    
            // Automatizar talvez com uma api, era muito o caso a partir daqui
    
            printf("Preco Atual: ");
            scanf("%f", &price );   
            printf("Risco (L, M or H): ");
            scanf(" %c", &risk ); 
    
            // Cadastrar o Ativo
    
            loadAssets();
            createAsset(cod, type, ticker, price, risk);
            printAssets();
            saveAssets();
            break;
            
        case 4:

            // Remoção por código da lista de Ativos
    
            printf("codigo do deletado: ");
            scanf(" %d", &cod);
    
            // Função para deletar o Ativo da lista e da memória
    
            loadAssets();
            deleteAsset(cod);
            printAssets();
            saveAssets();
            
            break;

        case 5: 
            loadInvestors();
            printInvestor();
            break;
        case 6:
            loadAssets();
            printAssets();
            break;
        default: 
            printf("digite uma opção valida");
            break;
    }
}
