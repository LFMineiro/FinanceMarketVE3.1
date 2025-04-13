#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/investor.h"

// typedef struct _investor {
//     int id;
//     char name[50];
//     char profile[35];
// } Investor;

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

void registerInvestor(){
    char name[50];
    int id;
    int num_profile = -1;
    char available_profiles[3][35] = {"Conservador", "Moderado", "Agressivo"};

    printf("Cadastro do Investidor\n\n");
    printf("Nome: ");
    scanf(" %s", name );
    printf("Codigo: ");
    scanf("%d", &id);
    
    while (num_profile < 0 || num_profile > 2){
        printf("Perfil: \n[0] - Conservador\n[1] - Moderado\n[2] - Agressivo\n");
        scanf("%d", &num_profile);  
    }
    
    int existe = idInvestorExist(id);
    if(!existe){
        createInvestor(id, name, available_profiles[num_profile]); 
        printf("Investidor criado com sucesso!\n");
    }
    else printf("Ja existe o codigo");

}
Investor* searchInvestor(int id){
    for (int i = 0; i < numInvestors; i++)
    {
        if(investorsList[i]->id == id){
            
            return investorsList[i];
        }
    }
}
void printInvestor() {
    printf("\n=========== LISTA DE INVESTIDORES ===========\n\n");

    for (int i = 0; i < numInvestors; i++) {
        Investor *investor = investorsList[i];
        printf("+-----------------------------------------+\n");
        printf("| Nome   : %-30.30s |\n", investor->name);
        printf("| Codigo : %-30.05d |\n", investor->id);
        printf("| Perfil : %-30.30s |\n", investor->profile);
        printf("+-----------------------------------------+\n\n");
    }
}

int idInvestorExist(int id) {
    for(int i = 0; i<numInvestors; i++) {
        if(investorsList[i]->id == id) {
            return 1;
        }
    }
    return 0;
}