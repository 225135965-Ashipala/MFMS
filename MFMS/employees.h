#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

struct Employee {
    char id[20];
    char name[50];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double grossSalary;
};

void calculateSalary(struct Employee *emp);
void addEmployee(struct Employee empList[], int *count);
void displayEmployees(struct Employee empList[], int count);
void searchEmployee(struct Employee empList[], int count);
void employeeMenu(struct Employee empList[], int *count);

#endif
