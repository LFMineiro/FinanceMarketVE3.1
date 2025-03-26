#ifndef ASSET_H
#define ASSET_H

typedef struct _asset {
    int id;
    char type[15];
    char ticker[15];
    float price;
    char risk;
} Asset;

Asset *createAsset(int id, const char *type, const char *ticker, float price, const char risk);
void deleteAsset(int id);
void loadAssets();
void saveAssets();
void registerAsset();
Asset* searchAsset(int id);
void printAssets();

#endif