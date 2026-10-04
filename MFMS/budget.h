#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 20

typedef struct
{
    char department[30];
    float allocatedBudget;
    float expenditure;
} Budget;

void addBudget(Budget budgets[], int *budgetCount);
void displayBudgets(Budget budgets[], int budgetCount);
void updateBudget(Budget budgets[], int budgetCount);
void calculateRemainingBudget(Budget budgets[], int budgetCount);

void budgetMenu(Budget budgets[], int *budgetCount);

#endif