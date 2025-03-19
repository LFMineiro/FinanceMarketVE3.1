#ifndef INVESTOR_H
#define INVESTOR_H

typedef struct {
    int id;
    char name[50];
    char profile[35];
} Investor;

Investor* createInvestor(int id, const char *name, const char *profile);
void deleteInvestor(int id);
void loadInvestors();
void saveInvestors();
void printInvestor();

#endif