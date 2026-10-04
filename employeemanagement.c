#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[50];
    float basic_salary;
    float house_allowance;
    float transport_allowance;
	char town[50];

    
};

 int addEmployee(struct Employee emp[],
 int employee_count);
 int displayEmployee(const struct Employee emp[],
 int employee_count);
 int searchEmployee(const struct Employee emp[],
 int employee_count);
 int calculateSalary(const struct Employee emp[],
 int employee_count);
 int displayMunicipalityTowns(const struct Employee emp[],
 int employee_count);
 void displayMenu();
 void employeeMenu();

#endif // EMPLOYEES_H
