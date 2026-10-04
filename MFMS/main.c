#include <stdio.h>
#include "validation.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

static void displayMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}

int main(void)
{
    /* All data lives here and is passed to each module. */
    struct Employee employees[MAX_EMPLOYEES];
    Budget          budgets[MAX_BUDGETS];
    Supplier        suppliers[MAX_SUPPLIERS];
    Asset           assets[MAX_ASSETS];

    int employeeCount = 0, budgetCount = 0, supplierCount = 0, assetCount = 0;
    int choice;

    do {
        displayMenu();
        choice = getInt("Enter your choice: ", 1, 6);

        switch (choice) {
            case 1: employeeMenu(employees, &employeeCount);        break;
            case 2: budgetMenu(budgets, &budgetCount);              break;
            case 3: displaySupplierMenu(suppliers, &supplierCount); break;
            case 4: assetMenu(assets, &assetCount);                 break;
            case 5: displayReportsMenu(employees, employeeCount,
                                       budgets, budgetCount,
                                       suppliers, supplierCount,
                                       assets, assetCount);         break;
            case 6: printf("\nGoodbye.\n");                         break;
        }
    } while (choice != 6);

    return 0;
}
