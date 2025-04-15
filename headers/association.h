#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include "investor.h"
#include "asset.h"

typedef struct _association{
    int id;
    char nameInvestor[35];
    char profile[35];
    char nameAsset[15];
    char type[15];
    char risk;
    float price;
    char period[6];

} Association;

//Association* createAssociation(int id,const char* nameInvestor, const char* nameAsset, const char* period);
Association* createAssociation(int id,const char* nameInvestor, const char* profileInvestor, const char* nameAsset, const char* type, const char risk, float price, char* period);
void deleteAssociation(int id);
void loadAssociations();
void saveAssociations();
void registerAssociation();
void getAssetsByInvestorAndPeriod();
void getInvestorsByAssetAndPeriod();
int idAssociationExist(int id);

#endif