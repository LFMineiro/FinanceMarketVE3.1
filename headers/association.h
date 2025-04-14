#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include "investor.h"
#include "asset.h"

typedef struct _association{
    int id;
    char nameInvestor[35];
    char nameAsset[15];
    char period[6];

} Association;

Association* createAssociation(int id,const char* nameInvestor, const char* nameAsset, const char* period);
void deleteAssociation(int id);
void loadAssociations();
void saveAssociations();
void registerAssociation();
void getAssetsByInvestorAndPeriod();
void getInvestorsByAssetAndPeriod();
int idAssociationExist(int id);

#endif