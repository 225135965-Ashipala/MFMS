#ifndef REPORTS_H
#define REPORTS_H

/* ---------- Size limits (kept simple with fixed-size arrays) ---------- */
#define MAX_EMPLOYEES  50
#define MAX_BUDGETS    20
#define MAX_SUPPLIERS  50
#define MAX_ASSETS     50

/* ---------- Shared data structures ----------
   NOTE: These structs should match the ones your teammates use in
   employees.h, budget.h, suppliers.h and assets.h. Agree on the field
   names as a group so everyone's struct definitions line up exactly. */

typedef struct {
    int   employeeID;
    char  name[50];
    char  department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

typedef struct {
    char  department[30];
    float allocatedBudget;
    float expenditure;
} Budget;

typedef struct {
    int  supplierID;
    char name[50];
    char email[50];
    char phone[20];
    char town[30];
} Supplier;

typedef struct {
    int   assetID;
    char  name[50];
    char  type[30];
    float purchaseValue;
    char  department[30];
    char  condition[20];
} Asset;

/* ---------- Reports module function prototypes ---------- */
void displayReportsMenu(Employee employees[], int employeeCount,
                         Budget budgets[], int budgetCount,
                         Supplier suppliers[], int supplierCount,
                         Asset assets[], int assetCount);

void employeeReport(Employee employees[], int employeeCount);
void budgetReport(Budget budgets[], int budgetCount);
void supplierReport(Supplier suppliers[], int supplierCount);
void assetReport(Asset assets[], int assetCount);

#endif
