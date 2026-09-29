#include <stdio.h>
#include "budget.h"

int main()
{
    Budget budgets[MAX_BUDGETS];
    int budgetCount = 0;
int choice;

do
{
    printf("\n===== BUDGET MANAGEMENT =====\n");
    printf("1. Add Budget\n");
    printf("2. Display Budgets\n");
    printf("3. Update Budget\n");
    printf("4. Calculate Remaining Budget\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            addBudget(budgets, &budgetCount);
            break;

        case 2:
            displayBudgets(budgets, budgetCount);
            break;

        case 3:
            updateBudget(budgets, budgetCount);
            break;

        case 4:
            calculateRemainingBudget(budgets, budgetCount);
            break;

        case 5:
            printf("Exiting Budget Management...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

} while (choice != 5);
    return 0;
}