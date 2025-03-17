#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct _investor {
    int id;
    char name[50];
    char profile[35];
} Investor;

Investor** investorsList = NULL;
int numInvestors = 0;


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

Investor *createInvestor(int id, const char *name, const char *profile ) {
    Investor *investor = (Investor *) calloc(1, sizeof(Investor));
    
    strcpy(investor->name, name);
    investor->id = id;
    strcpy(investor->profile, profile);
    
    //adiciona à lista
    numInvestors++;
    Investor** tempList = (Investor**)realloc(investorsList, numInvestors*sizeof(Investor));
    investorsList = tempList;
    investorsList[numInvestors - 1] = investor;

    return investor;
}

void deleteInvestor(int id){
    for (int i = 0; i < numInvestors; i++)
    {
        if(investorsList[i]->id == id){
            
            free(investorsList[i]);
            for (int j = i; j < numInvestors - 1; j++)
            {
                investorsList[j] = investorsList[j+1];
            }

            numInvestors--;
            break;
        }
    }
    
}

void loadInvestors(){
    FILE *investorsFile = fopen("files/investors.txt", "r");
    if(!investorsFile){
        printf("Erro ao ler arquivo");
        exit(1);
    }
    
    int tempId;
    char tempName[50];
    char tempProfile[35];

    while (fscanf(investorsFile, "%d;%[^;];%[^;];", &tempId, tempName, tempProfile) == 3){
        //printf("-%d-%s-%s-", tempId, tempName, tempProfile);

        createInvestor(tempId, tempName, tempProfile);
    }

    fclose(investorsFile);
}

void saveInvestors(){
    FILE *investorsFile = fopen("files/investors.txt", "w");
    if(!investorsFile){
        printf("Erro ao ler arquivo");
        exit(1);
    }
    
    for (int i = 0; i < numInvestors; i++){   
        Investor *investor = investorsList[i];
        fprintf(investorsFile,"%d;%s;%s;\n", investor->id, investor->name, investor->profile);
    }

    fclose(investorsFile);
}

void printInvestor() {
    system("cls");
    printf("***************************\n\n");
    for (int i = 0; i < numInvestors; i++){   
        Investor *investor = investorsList[i];
        printf("nome: %s\ncodigo: %d\nperfil: %s\n\n", investor->name, investor->id, investor->profile);
        
    }
    printf("***************************\n");
    
}

typedef struct _asset {
    int id;
    char type[15];
    char ticker[15];
    float price;
    char risk;
} Asset;

Asset **assetsList = NULL;
int numAssets = 0;

Asset *createAsset(int id, const char *type, const char *ticker, float price, const char risk) {
    // alocar dinamicamente
    Asset *asset = (Asset *)calloc(1, sizeof(Asset));
    
    strcpy(asset->ticker, ticker);
    strcpy(asset->type, type);
    asset->risk = risk;
    asset->price = price;
    asset->id = id;

    // adicionar a lista
    numAssets++;
    Asset **tempList = (Asset **) realloc(assetsList, numAssets*sizeof(Asset));
    assetsList = tempList;
    assetsList[numAssets - 1] = asset;
    
    return asset;
}

/*
        Aqui no delete tem q ser visto se memoria foi completamente desalocada 
*/
void deleteAsset(int id) {
    for(int i = 0; i<numAssets; i++) {
        if(assetsList[i]->id == id) {
            free(assetsList[i]);
            for(int j = i; j < numAssets - 1; j++) {
                assetsList[j] = assetsList[j+1];
            }
        }
        numAssets--;
        break;
    }

}
void loadAssets() {
    FILE *assetsFile = fopen("files/assets.txt", "r");
    if(!assetsFile) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    
    int tempId;
    char tempTicker[50];
    char tempType[35];
    char tempRisk;
    float tempPrice;
    
    while(fscanf(assetsFile, "%d;%[^;];%[^;];%c;%f", &tempId, tempTicker, tempType, &tempRisk, &tempPrice) == 5) {
        createAsset(tempId, tempType,  tempTicker, tempPrice, tempRisk);
    }

    fclose(assetsFile);
}

void saveAssets() {
    FILE *assetsFile = fopen("files/assets.txt", "w");
    if(!assetsFile) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    for(int i = 0; i < numAssets; i++) {
        Asset *asset = assetsList[i];

        // 0001;PETR4;ACTION;L;32.23

        fprintf(assetsFile, "%d;%s;%s;%c;%0.2f\n", asset->id, asset->ticker, asset->type, asset->risk, asset->price);
    }
}

void printAssets() {
    system("cls");
    printf("Ativos\n*****************\n\n");
    for(int i = 0; i< numAssets; i++) {
        Asset *asset = assetsList[i];
        printf("Ticker: %s\nCodigo: %d\nTipo: %s; Risco: %c; Preco Atual: %0.2f\n ", asset->ticker, asset->id,  asset->type, asset->risk, asset->price );
        printf("\n*****************\n");
    }
    
}
    
int main() {

    // loadInvestors();
    
    loadAssets();

    // createAsset(3, "Acao", "BBAS3", 28.01, 'M');
    // createAsset(2, "Acao", "PETR4", 32.23, 'L');
    
    // deleteAsset(2);
    // deleteAsset(3);

    // printInvestor();
    
    // deleteInvestor(3);
    
    printAssets();
    
    saveAssets();
    // saveInvestors();
    return 0;
}
