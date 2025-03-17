#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "investor.c"
#include "asset.c"
    
int showMenu() {

    int opcao;

    printf("Acoes:\n");
    printf("1 - Cadastrar um novo investidor\n");
    printf("2 - Remover um investidor\n");
    printf("3 - Cadastrar uma nova transacao\n");
    printf("4 - Remover uma transacao\n\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    return opcao;

}

int main() {

    loadInvestors();
    
    loadAssets();

    // createInvestor(10, "rebeca", "moderado");
    //createAsset(3, "Acao", "BBAS3", 28.01, 'M');
    //createAsset(2, "Acao", "PETR4", 32.23, 'L');
    
    //deleteInvestor(5);
    // deleteAsset(3);

    //printInvestor();
    
    // deleteInvestor(3);

    printAssets();
    
    saveAssets();

    //showMenu();

    saveInvestors();
    return 0;
}
