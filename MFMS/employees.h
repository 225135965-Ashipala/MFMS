#ifndef EMPLOYEE_H
#define EMPLOYEE_H

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

extern struct Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

void calculateSalary(struct Employee *emp);
void addEmployee(); void displayEmployees(); void searchEmployee(); void employeeMenu();

#endif
