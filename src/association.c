#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/association.h"
#include "../headers/investor.h"
#include "../headers/asset.h"

Association** associationsList = NULL;
int numAssociations = 0;

void registerAssociation(){
    char nameInvestor[35];
    char nameAsset[15];
    char period[7];
    
    int idInvestor;
    int codAsset;

    int existAssociation = 1;
    int existInvestor = 0;
    int existAsset = 0;
    int isPeriodValid = 1;

	printAssets();

    while (!existAsset){
        printf("Qual o codigo do ativo comprado: ");
        scanf("%d", &codAsset);

        existAsset = idAssetExist(codAsset);
        if(!existAsset){
            printf("Nao existe Ativo com esse codigo\n");
        }
    }
    
    Asset *tempAtivo = searchAsset(codAsset);  
    strcpy(nameAsset, tempAtivo->ticker);

	printInvestor();

    while (!existInvestor){
        printf("Qual o codigo do investidor que comprou o ativo: ");
        scanf("%d", &idInvestor);

        existInvestor = idInvestorExist(idInvestor);
        if(!existInvestor){
            printf("Nao existe Investidor com esse codigo\n");
        }
    }

    Investor *tempInvestor = searchInvestor(idInvestor);

    // Validação do Periodo da Compra
	while(isPeriodValid){
        printf("Em qual periodo foi comprado (2025.1, 2025.2, 2024.1): ");
	    scanf("%s", period);

        if(period[4] == '.' && (period[5] == '1' || period[5] == '2')) 
            isPeriodValid = 0;
        else 
            printf("\n========== Digite um periodo valido ========== \n");
    }

    int id = 1;
    if(associationsList) id = associationsList[numAssociations - 1]->id + 1;
	createAssociation(id, tempInvestor->name, tempInvestor->profile, tempAtivo->ticker, tempAtivo->type, tempAtivo->risk, tempAtivo->price, period);

    printf("Associacao criada!\n");
}

Association* createAssociation(int id,const char* nameInvestor, const char* profileInvestor, const char* nameAsset, const char* type, const char risk, float price, char* period){
    Association *association = (Association *) calloc(1, sizeof(Association));
    
    association->id = id;
    strcpy(association->nameInvestor, nameInvestor);
    strcpy(association->profile, profileInvestor);

    strcpy(association->nameAsset, nameAsset);
    strcpy(association->type, type);
    association->risk = risk;
    association->price = price;
    strcpy(association->period, period);

    //adiciona à lista
    numAssociations++;
    Association** tempList = (Association**)realloc(associationsList, numAssociations*sizeof(Association));
    associationsList = tempList;
    associationsList[numAssociations - 1] = association;
}

void deleteAssociation(int id){
    for (int i = 0; i < numAssociations; i++){
        if(associationsList[i]->id == id){ 
            free(associationsList[i]);
            for (int j = i; j < numAssociations - 1; j++){
                associationsList[j] = associationsList[j+1];
            }

            numAssociations--;
            break;
        }
    }
    
}
void loadAssociations(){
    associationsList = NULL;
    numAssociations = 0;

    FILE *associationsFile = fopen("files/associations.txt", "r");
    if(!associationsFile){
        printf("Erro ao carregar arquivo");
        exit(1);
    }
    
    int tempId;
    char tempNameInvestor[35];
    char profile[35];
    char tempNameAsset[15];
    char type[15];
    float price;
    char risk;
    char tempPeriod[7];

    while (fscanf(associationsFile, "%d;%[^;];%[^;];%[^;];%[^;];%c;%f;%[^;];",&
        tempId, tempNameInvestor, profile, tempNameAsset, type, &risk, &price, tempPeriod) == 8){

        createAssociation(tempId, tempNameInvestor, profile, tempNameAsset, type, risk, price, tempPeriod);
    }

    fclose(associationsFile);
}
void saveAssociations(){
    FILE *associationsFile = fopen("files/associations.txt", "w");
    if(!associationsFile){
        printf("Erro ao salvar arquivo");
        exit(1);
    }
    
    for (int i = 0; i < numAssociations; i++){   
        Association *association = associationsList[i];
        fprintf(associationsFile,"%d;%s;%s;%s;%s;%c;%f;%s;\n", association->id,
             association->nameInvestor, association->profile, association->nameAsset,
             association->type, association->risk, association->price, association->period);
    }

    fclose(associationsFile);
}

void getAssetsByInvestorAndPeriod() {
    int numAux = 0;

    int id;
    char period[7];
    char nameInvestor[50];
    
    int existInvestor = 0;
    int isPeriodValid = 1;
	
    printInvestor();
	
    while (!existInvestor){
        printf("Voce deseja ver a carteira de qual investidor: ");
	    scanf("%d", &id);

        existInvestor = idInvestorExist(id);
        if(!existInvestor){
            printf("Nao existe Investidor com esse codigo\n");
        }
    }

	while(isPeriodValid){
        printf("\nEm qual periodo foi comprado (2025.1, 2025.2, 2024.1): ");
	    scanf("%s", period);

        if(period[4] == '.' && (period[5] == '1' || period[5] == '2')) 
            isPeriodValid = 0;
        else 
            printf("\n========== Digite um periodo valido ========== \n");
    }
	
    //obtem o nome do investidor que foi passado pelo codigo
	Investor *tempInv = searchInvestor(id);
	strcpy(nameInvestor, tempInv->name);
    
    printf("\n======== CARTEIRA DO INVESTIDOR ========\n");
    printf("Investidor: %s\n", nameInvestor);
    printf("Periodo: %s\n", period);
    printf("-------------------------------------------\n");
	
	for(int i = 0; i < numAssociations; i++) {  

        /*  Percorre a lista e filtra pelo nome do investidor   
            e por periodo, que foram passados pelo usuario */

		if(strcmp(associationsList[i]->nameInvestor, nameInvestor) == 0 && strcmp(associationsList[i]->period, period) == 0) {
            numAux++;

            printf("\n%-10s | %-15s | %-5s | %-10s\n", 
                "Ticker", "Tipo", "Risco", "Preco");
            printf("--------------------------------------------------------------\n");

            printf("%-10.8s | %-15.12s | %-5c | %8.2f\n", 
                associationsList[i]->nameAsset, associationsList[i]->type, associationsList[i]->risk, associationsList[i]->price);
		}
        
	}

    if(numAux == 0) printf("Esse Investidor nao possui Ativos nesse periodo\n");                 
    else if(numAux == 1) printf("\nEsse Investidor tem %d ativo no periodo %s\n ", numAux, period);
    else printf("\nEsse Investidor tem %d ativos no periodo %s\n ", numAux, period);
	
}

void getInvestorsByAssetAndPeriod() {
    int numAux = 0;

    int id;
    char period[7];
    char nameAsset[35];

    int existAsset = 0;
	int isPeriodValid = 1;
    
    printAssets();

    while (!existAsset){
	    printf("Qual o codigo do ativo que voce quer verificar os investidores: ");
        scanf("%d", &id);

        existAsset = idAssetExist(id);
        if(!existAsset){
            printf("Nao existe Ativo com esse codigo\n");
        }
    }
	
	while(isPeriodValid){
        printf("\nEm qual periodo foi comprado (2025.1, 2025.2, 2024.1): ");
	    scanf("%s", period);

        if(period[4] == '.' && (period[5] == '1' || period[5] == '2')) 
            isPeriodValid = 0;
        else 
            printf("\n========== Digite um periodo valido ========== \n");
    }
	
    //obtem o nome do ativo que foi passado pelo codigo
	Asset *tempAsset = searchAsset(id);
	strcpy(nameAsset, tempAsset->ticker);
    
    printf("\n=========== INVESTIDORES DO ATIVO ===========\n");
    printf("Ativo: %s\nPeriodo: %s\n", nameAsset, period);
    printf("-------------------------------------------\n");

	for(int i = 0; i < numAssociations; i++) {  
        /*  Percorre a lista e filtra pelo nome do investidor   
            e por periodo, que foram passados pelo usuario */

		if(strcmp(associationsList[i]->nameAsset, nameAsset) == 0 && strcmp(associationsList[i]->period, period) == 0) {
            numAux++;                
            printf("+-----------------------------------------+\n");
            printf("| Nome   : %-30.30s |\n", associationsList[i]->nameInvestor);
            printf("| Perfil : %-30.30s |\n", associationsList[i]->profile);
            printf("+-----------------------------------------+\n\n");
        }
                
    }
    if(numAux == 0) printf("Esse Ativo nao possui investidores nesse periodo"); 
    else if(numAux == 1) printf("\nEsse Ativo tem %d Investidor no periodo %s\n ", numAux, period);
    else printf("\nEsse Ativo tem %d Investidores no periodo %s\n ", numAux, period);
	
}

int idAssociationExist(int id) {
    for(int i=0; i< numAssociations; i++) {
        if(associationsList[i]->id == id) 
            return 1;
        }
        return 0;
        
}

