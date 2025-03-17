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

    // for (int i = 0; i < numInvestors; i++)
    // {
    //     printf("%d %s", investorsList[i]->id, investorsList[i]->name);
    // }
    

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
    FILE *investorsFile = fopen("../files/investors.txt", "r");
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
    FILE *investorsFile = fopen("../files/investors.txt", "w");
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
   
    // system("cls");
    printf("***************************\n\n");
    for (int i = 0; i < numInvestors; i++){   
        Investor *investor = investorsList[i];
        printf("nome: %s\ncodigo: %d\nperfil: %s\n\n", investor->name, investor->id, investor->profile);
        printf("***************************\n\n");
    }
    
}