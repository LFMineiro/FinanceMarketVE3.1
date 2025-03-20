#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/asset.h"

// typedef struct _asset {
//     int id;
//     char type[15];
//     char ticker[15];
//     float price;
//     char risk;
// } Asset;

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
    
    while(fscanf(assetsFile, "%d;%[^;];%[^;];%c;%f", &tempId, tempTicker, tempType, &tempRisk, &tempPrice) == 5) {
        createAsset(tempId, tempType,  tempTicker, tempPrice, tempRisk);
    }

    fclose(assetsFile);
}

void saveAssets() {
    FILE *assetsFile = fopen("./files/assets.txt", "w");
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
    //system("cls");
    printf("Ativos\n*****************\n\n");
    for(int i = 0; i< numAssets; i++) {
        Asset *asset = assetsList[i];
        printf("Ticker: %s\nCodigo: %d\nTipo: %s\nRisco: %c\nPreco Atual: %0.2f\n ", asset->ticker, asset->id,  asset->type, asset->risk, asset->price );
        printf("\n*****************\n\n");
    }
    
}