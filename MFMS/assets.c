#include <stdio.h>
#include "assets.h"

void addAsset(Asset assets[], int *assetCount)
{
    if (*assetCount >= MAX_ASSETS)
    {
        printf("\nMaximum number of assets reached.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             ADD ASSET\n");
    printf("========================================\n");

    printf("Enter asset ID: ");
    scanf("%d", &assets[*assetCount].assetID);

    printf("Enter asset name: ");
    scanf(" %49[^\n]", assets[*assetCount].name);

    printf("Enter asset type: ");
    scanf(" %29[^\n]", assets[*assetCount].type);

    printf("Enter purchase value: N$");
    scanf("%f", &assets[*assetCount].purchaseValue);

    printf("Enter department: ");
    scanf(" %29[^\n]", assets[*assetCount].department);

    printf("Enter condition: ");
    scanf(" %19[^\n]", assets[*assetCount].condition);

    (*assetCount)++;

    printf("\nAsset added successfully!\n");
}

void displayAssets(Asset assets[], int assetCount)
{
    int i;

    printf("\n========================================\n");
    printf("          REGISTERED ASSETS\n");
    printf("========================================\n");

    if (assetCount == 0)
    {
        printf("No assets have been recorded yet.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("Asset ID       : %d\n", assets[i].assetID);
        printf("Name           : %s\n", assets[i].name);
        printf("Type           : %s\n", assets[i].type);
        printf("Purchase Value : N$%.2f\n", assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
        printf("----------------------------------------\n");
    }
}

void updateAsset(Asset assets[], int assetCount)
{
    int choice;

    if (assetCount == 0)
    {
        printf("\nNo assets have been recorded yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             UPDATE ASSET\n");
    printf("========================================\n");

    displayAssets(assets, assetCount);

    printf("Enter asset number to update: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > assetCount)
    {
        printf("Invalid asset number.\n");
        return;
    }

    choice--;

    printf("\nUpdating asset: %s\n", assets[choice].name);

    printf("Enter new asset name: ");
    scanf(" %49[^\n]", assets[choice].name);

    printf("Enter new asset type: ");
    scanf(" %29[^\n]", assets[choice].type);

    printf("Enter new purchase value: N$");
    scanf("%f", &assets[choice].purchaseValue);

    printf("Enter new department: ");
    scanf(" %29[^\n]", assets[choice].department);

    printf("Enter new condition: ");
    scanf(" %19[^\n]", assets[choice].condition);

    printf("\nAsset updated successfully!\n");
}