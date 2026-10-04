#ifndef REPORTS_H
#define REPORTS_H

/* ---------- Size limits ---------- */
#define MAX_EMPLOYEES  50
#define MAX_BUDGETS    20
#define MAX_SUPPLIERS  50
#define MAX_ASSETS     50


typedef struct {
    char   id[20];
    char   name[50];
    char   department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double grossSalary;
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

/* Reports module function prototypes */
void displayReportsMenu(Employee employees[], int employeeCount,
                         Budget budgets[], int budgetCount,
                         Supplier suppliers[], int supplierCount,
                         Asset assets[], int assetCount);

void employeeReport(Employee employees[], int employeeCount);
void budgetReport(Budget budgets[], int budgetCount);
void supplierReport(Supplier suppliers[], int supplierCount);
void assetReport(Asset assets[], int assetCount);

#endif

