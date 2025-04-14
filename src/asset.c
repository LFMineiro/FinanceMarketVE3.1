#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/asset.h"

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

void deleteAsset(int id) {
    for(int i = 0; i<numAssets; i++) {
        if(assetsList[i]->id == id) {
            free(assetsList[i]);
            for(int j = i; j < numAssets - 1; j++) {
                assetsList[j] = assetsList[j+1];
            }
            numAssets--;
            break;
        }
    }

}

void loadAssets() {
    assetsList = NULL;
    numAssets = 0;
    FILE *assetsFile = fopen("./files/assets.txt", "r");
    if(!assetsFile) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    
    int tempId;
    char tempTicker[50];
    char tempType[35];
    char tempRisk;
    float tempPrice;
    
    while(fscanf(assetsFile, "%d;%[^;];%[^;];%c;%f;", &tempId, tempTicker, tempType, &tempRisk, &tempPrice) == 5) {
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

        fprintf(assetsFile, "%d;%s;%s;%c;%0.2f;\n", asset->id, asset->ticker, asset->type, asset->risk, asset->price);
    }

    fclose(assetsFile);
}

void registerAsset(){
    
    int num_type = -1;
    char available_types[5][15] = {"Acao", "Titulo", "Cripto", "CDB", "LCI"};
    char ticker[15];
    float price;
    int num_risk = -1;
    char availeble_risks[3] = {'L', 'M', 'H'};
    
    printf("Cadastro do Ativo\n\n");                    
    printf("Ticker (Ex: PETR4): ");
    scanf(" %s", ticker );   
    
    while(num_type < 0 || num_type > 4){
        printf("[0] - Acao\n[1] - Titulo\n[2] - Cripto\n[3] - CDB\n[4] - LCI\n");
        printf("Tipo: ");
        scanf("%d", &num_type); 
    }

    printf("Preco Atual: ");
    scanf("%f", &price );   
    
    while( num_risk < 0 || num_risk > 2){
        printf("[0] - Low\n[1] - Medium\n[2] - High\n");
        printf("Risco: ");       
        scanf(" %d", &num_risk); 
    }

    // Cadastrar o Ativo
    int id = 1;
    if(assetsList) id = assetsList[numAssets - 1]->id + 1;
    createAsset(id, available_types[num_type], ticker, price, availeble_risks[num_risk]);       
    printf("Ativo criado com sucesso!\n");
    
}

Asset* searchAsset(int id){
    for (int i = 0; i < numAssets; i++)
    {
        if(assetsList[i]->id == id){
            
            return assetsList[i];
        }
    }
}


void printAssets() {
    printf("\n%-6s | %-10s | %-15s | %-5s | %-10s\n", 
        "Cod", "Ticker", "Tipo", "Risco", "Preco");
    printf("--------------------------------------------------------------\n");

    for(int i = 0; i < numAssets; i++) {
        Asset *asset = assetsList[i];
        printf("%04d   | %-10.8s | %-15.12s | %-5c | %8.2f\n", 
            asset->id, asset->ticker, asset->type, asset->risk, asset->price);
    }
}


int idAssetExist(int id) {
    for(int i = 0; i<numAssets; i++) {
        if(assetsList[i]->id == id) {
            return 1;
        }
    }
    return 0;
}