#include <stdio.h>
#include "budget.h"

void addBudget(Budget budgets[], int *budgetCount)
{
    if (*budgetCount >= MAX_BUDGETS)
    {
        printf("Maximum number of budgets reached.\n");
        return;
    }

    printf("Enter department name: ");
    scanf("%29s", budgets[*budgetCount].department);

    printf("Enter allocated budget: ");
    scanf("%f", &budgets[*budgetCount].allocatedBudget);

    printf("Enter expenditure: ");
    scanf("%f", &budgets[*budgetCount].expenditure);

    (*budgetCount)++;

    printf("Budget added successfully.\n");
}

void displayBudgets(Budget budgets[], int budgetCount)
{
    if (budgetCount == 0)
    {
        printf("No budgets available.\n");
        return;
    }

    printf("\n--- Budgets ---\n");

    for (int i = 0; i < budgetCount; i++)
    {
        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: %.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: %.2f\n", budgets[i].expenditure);
    }
}

void updateBudget(Budget budgets[], int budgetCount)
{
    int index;

    if (budgetCount == 0)
    {
        printf("No budgets available.\n");
        return;
    }

    printf("Enter budget number to update (1-%d): ", budgetCount);
    scanf("%d", &index);

    if (index < 1 || index > budgetCount)
    {
        printf("Invalid budget number.\n");
        return;
    }

    index--;

    printf("Enter new allocated budget: ");
    scanf("%f", &budgets[index].allocatedBudget);

    printf("Enter new expenditure: ");
    scanf("%f", &budgets[index].expenditure);

    printf("Budget updated successfully.\n");
}

void calculateRemainingBudget(Budget budgets[], int budgetCount)
{
    if (budgetCount == 0)
    {
        printf("No budgets available.\n");
        return;
    }

    printf("\n--- Remaining Budgets ---\n");

    for (int i = 0; i < budgetCount; i++)
    {
        float remaining;

        remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

        printf("%s: %.2f\n",
               budgets[i].department,
               remaining);
    }
}