#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _investor {
    int id;
    char name[50];
    char profile[35];
} Investor;


Investor *createInvestor(int id, const char *name, const char *profile ) {
    Investor *investor = (Investor *) calloc(1, sizeof(Investor));

    strcpy(investor->name, name);
    investor->id = id;
    strcpy(investor->profile, profile);

    return investor;
}

void printInvestor(const Investor *investor) {
    printf("nome: %s\ncodigo: %d\nperfil: %s\n\n", investor->name, investor->id, investor->profile);
}

void *deleteInvestor(Investor *investor) {
    
}


int main() {
    
    Investor *investidor1 = createInvestor(12, "Luiz", "Conservador");

    printInvestor(investidor1);



    return 0;
}
