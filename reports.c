#include <stdio.h>
#include "reports.h"


/* ---------- Employee Report ----------
   Total employees, average / highest / lowest total salary.
   Total salary for one employee = basic + housing + transport. */
void employeeReport(Employee employees[], int employeeCount)
{
    int i;
    float total, highest, lowest, current;
    float average;

    printf("\n========================================\n");
    printf("            EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (employeeCount == 0)
    {
        printf("No employees have been recorded yet.\n");
        return;
    }

    total = 0;
    /* start with the first employee's salary as the initial
       highest/lowest, then compare against the rest */
    highest = employees[0].basicSalary + employees[0].housingAllowance
              + employees[0].transportAllowance;
    lowest = highest;

    for (i = 0; i < employeeCount; i++)
    {
        current = employees[i].basicSalary
                 + employees[i].housingAllowance
                 + employees[i].transportAllowance;

        total = total + current;

        if (current > highest)
        {
            highest = current;
        }

        if (current < lowest)
        {
            lowest = current;
        }
    }

    average = total / employeeCount;

    printf("Total Employees : %d\n", employeeCount);
    printf("Average Salary  : N$%.2f\n", average);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
}


/* ---------- Budget Report ----------
   Total allocated, total expenditure, remaining, and a list of
   departments that have exceeded their allocated budget. */
void budgetReport(Budget budgets[], int budgetCount)
{
    int i;
    float totalAllocated, totalExpenditure, totalRemaining;
    float remaining;
    int exceededCount;

    printf("\n========================================\n");
    printf("             BUDGET REPORT\n");
    printf("========================================\n");

    if (budgetCount == 0)
    {
        printf("No department budgets have been recorded yet.\n");
        return;
    }

    totalAllocated = 0;
    totalExpenditure = 0;
    exceededCount = 0;

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated = totalAllocated + budgets[i].allocatedBudget;
        totalExpenditure = totalExpenditure + budgets[i].expenditure;
    }

    totalRemaining = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalExpenditure);
    printf("Total Remaining Budget : N$%.2f\n", totalRemaining);

    printf("\nDepartments that have EXCEEDED their budget:\n");
    printf("----------------------------------------\n");

    for (i = 0; i < budgetCount; i++)
    {
        remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("Department: %-15s Allocated: N$%.2f  Expenditure: N$%.2f  Over by: N$%.2f\n",
                   budgets[i].department,
                   budgets[i].allocatedBudget,
                   budgets[i].expenditure,
                   -remaining);
            exceededCount++;
        }
    }

    if (exceededCount == 0)
    {
        printf("None. All departments are within budget.\n");
    }
}


/* ---------- Supplier Report ----------
   Simple listing of every supplier currently stored. */
void supplierReport(Supplier suppliers[], int supplierCount)
{
    int i;

    printf("\n========================================\n");
    printf("            SUPPLIER REPORT\n");
    printf("========================================\n");

    if (supplierCount == 0)
    {
        printf("No suppliers have been recorded yet.\n");
        return;
    }

    printf("Total Suppliers: %d\n\n", supplierCount);

    for (i = 0; i < supplierCount; i++)
    {
        printf("Supplier ID : %d\n", suppliers[i].supplierID);
        printf("Name        : %s\n", suppliers[i].name);
        printf("Email       : %s\n", suppliers[i].email);
        printf("Phone       : %s\n", suppliers[i].phone);
        printf("Town        : %s\n", suppliers[i].town);
        printf("----------------------------------------\n");
    }
}


/* ---------- Asset Report ----------
   Simple listing of every municipal asset currently stored. */
void assetReport(Asset assets[], int assetCount)
{
    int i;
    float totalValue;

    printf("\n========================================\n");
    printf("             ASSET REPORT\n");
    printf("========================================\n");

    if (assetCount == 0)
    {
        printf("No assets have been recorded yet.\n");
        return;
    }

    totalValue = 0;

    for (i = 0; i < assetCount; i++)
    {
        printf("Asset ID       : %d\n", assets[i].assetID);
        printf("Name           : %s\n", assets[i].name);
        printf("Type           : %s\n", assets[i].type);
        printf("Purchase Value : N$%.2f\n", assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
        printf("----------------------------------------\n");

        totalValue = totalValue + assets[i].purchaseValue;
    }

    printf("Total Registered Assets : %d\n", assetCount);
    printf("Total Asset Value       : N$%.2f\n", totalValue);
}


/* ---------- Reports Sub-menu ----------
   Called from the main menu when the user selects "5. Reports".
   Lets the user pick which report to view, or go back. */
void displayReportsMenu(Employee employees[], int employeeCount,
                         Budget budgets[], int budgetCount,
                         Supplier suppliers[], int supplierCount,
                         Asset assets[], int assetCount)
{
    int choice;
    int running;

    running = 1;

    while (running == 1)
    {
        printf("\n========================================\n");
        printf("               REPORTS MENU\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            /* clear bad (non-numeric) input so we don't loop forever */
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
            {
                /* discard the rest of the bad input line */
            }
            continue;
        }

        switch (choice)
        {
            case 1:
                employeeReport(employees, employeeCount);
                break;
            case 2:
                budgetReport(budgets, budgetCount);
                break;
            case 3:
                supplierReport(suppliers, supplierCount);
                break;
            case 4:
                assetReport(assets, assetCount);
                break;
            case 5:
                running = 0;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
}
