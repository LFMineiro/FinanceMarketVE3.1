#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/association.h"
#include "../headers/investor.h"
#include "../headers/asset.h"

Association** associationsList = NULL;
int numAssociations = 0;

void registerAssociation(){
    int id;
    char nameInvestor[35];
    char nameAsset[15];
    char period[6];
    
    int idInvestor;
    int codAsset;

    loadInvestor();
	loadAssets();
	
	printAssets();
    printf("Qual o codigo do ativo comprado: ");
    scanf(" %d", &codAsset);
    Asset *tempAtivo = searchAsset(codAsset);  //implementar search
    strcpy(nameAsset, tempAtivo->ticker);
    
	printInvestor() ;
    printf("Qual o codigo do investidor que comprou o ativo: ");
    scanf(" %d", &idInvestor);
    Investor *tempInvestor = searchInvestor(idInvestor);
    strcpy(nameInvestor, tempInvestor->name);
		
	printf("Em qual periodo foi comprado (2025.1, 2025.2, 2024.1): ");
	scanf(" %s", &period);
		
	createAssociation(id, nameInvestor, nameAsset, period);

    printf("Associacao criada!\n");

}

Association* createAssociation(int id,const char* nameInvestor, const char* nameAsset, const char* period){
    Association *association = (Association *) calloc(1, sizeof(Association));
    
    association->id = id;
    strcpy(association->nameInvestor, nameInvestor);
    strcpy(association->nameAsset, nameAsset);
    strcpy(association->period, period);

    //adiciona à lista
    numAssociations++;
    Association** tempList = (Association**)realloc(associationsList, numAssociations*sizeof(Association));
    associationsList = tempList;
    associationsList[numAssociations - 1] = association;
}

void deleteAssociation(int id){
    for (int i = 0; i < numAssociations; i++)
    {
        if(associationsList[i]->id == id){
            
            free(associationsList[i]);
            for (int j = i; j < numAssociations - 1; j++)
            {
                associationsList[j] = associationsList[j+1];
            }

            numAssociations--;
            break;
        }
    }
    
}
void loadAssociations(){
    FILE *associationsFile = fopen("files/associations.txt", "r");
    if(!associationsFile){
        printf("Erro ao carregar arquivo");
        exit(1);
    }
    
    int tempId;
    char tempNameInvestor[35];
    char tempNameAsset[15];
    char tempPeriod[6];

    while (fscanf(associationsFile, "%d;%[^;];%[^;];%[^;];", &tempId, tempNameInvestor, tempNameAsset, tempPeriod) == 4){
        //printf("-%d-%d-%d-%s\n", tempId, tempNameInvestor, tempNameAsset, tempPeriod);

        createAssociation(tempId, tempNameInvestor, tempNameAsset, tempPeriod);
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
        fprintf(associationsFile,"%d;%s;%s;%s;\n", association->id, association->nameInvestor, association->nameAsset, association->period);
    }

    fclose(associationsFile);
}
void printAssociation();