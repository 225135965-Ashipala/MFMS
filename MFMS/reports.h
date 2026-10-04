#ifndef REPORTS_H
#define REPORTS_H

/* Each module owns its own struct and MAX_ limit, so the reports module
   simply includes the other headers instead of redefining them. */
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void displayReportsMenu(struct Employee employees[], int employeeCount,
                        Budget budgets[], int budgetCount,
                        Supplier suppliers[], int supplierCount,
                        Asset assets[], int assetCount);

void employeeReport(struct Employee employees[], int employeeCount);
void budgetReport(Budget budgets[], int budgetCount);
void supplierReport(Supplier suppliers[], int supplierCount);
void assetReport(Asset assets[], int assetCount);

#endif
