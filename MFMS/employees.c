#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Employee structure
struct Employee {
    char id[20];
    char name[50];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double grossSalary;
};

// Function declarations
void calculateSalary(struct Employee *emp);
void addEmployee(struct Employee empList[], int *count);
void displayEmployees(struct Employee empList[], int count);
void searchEmployee(struct Employee empList[], int count);
void employeeMenu(struct Employee empList[], int *count);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do {
        printf("\n=================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("===================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management (Under Construction)\n");
        printf("3. Supplier Management (Under Construction)\n");
        printf("4. Asset Management (Under Construction)\n");
        printf("5. Reports (Under Construction)\n");
        printf("6. Exit\n");
        printf("------------------------------------\n");
        
        // ask user for input menu choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;
            case 2:
                printf("\n[Budget Management module will be added by Student 2]\n");
                break;
            case 3:
                printf("\n[Supplier Management module will be added by Student 3]\n");
                break;
            case 4:
                printf("\n[Asset Management module will be added by Student 4]\n");
                break;
            case 5:
                printf("\n[Reports module will be added by Student 5]\n");
                break;
            case 6:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Automatically calculates gross salary based on basic and allowances
void calculateSalary(struct Employee *emp) {
    emp->grossSalary = emp->basicSalary + emp->housingAllowance + emp->transportAllowance;
}

// Adds a new employee to the system
void addEmployee(struct Employee empList[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Maximum employee limit reached!\n");
        return;
    }

    struct Employee newEmp;

    // ask user for input employee id
    printf("\nEnter Employee ID: ");
    scanf("%19s", newEmp.id);
    getchar(); // Clear newline from buffer

    // ask user for input employee name
    printf("Enter Employee Name: ");
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = 0; // Remove trailing newline

    // ask user for input department
    printf("Enter Department: ");
    fgets(newEmp.department, sizeof(newEmp.department), stdin);
    newEmp.department[strcspn(newEmp.department, "\n")] = 0; // Remove trailing newline

    // ask user for input basic salary
    printf("Enter Basic Salary: ");
    scanf("%lf", &newEmp.basicSalary);

    // ask user for input housing allowance
    printf("Enter Housing Allowance: ");
    scanf("%lf", &newEmp.housingAllowance);

    // ask user for input transport allowance
    printf("Enter Transport Allowance: ");
    scanf("%lf", &newEmp.transportAllowance);

    // calculate gross salary before saving
    calculateSalary(&newEmp);

    // Add to array and increment counter
    empList[*count] = newEmp;
    (*count)++;

    printf("\nEmployee added successfully!\n");
}

// Displays all current employees in a tabular format
void displayEmployees(struct Employee empList[], int count) {
    if (count == 0) {
        printf("\nNo employees found in the system.\n");
        return;
    }

    printf("\n=========================================================================================================\n");
    printf("%-10s | %-20s | %-15s | %-12s | %-12s | %-12s | %-12s\n", 
           "ID", "Name", "Department", "Basic Sal", "Housing All", "Trans All", "Gross Sal");
    printf("=========================================================================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10s | %-20s | %-15s | %-12.2f | %-12.2f | %-12.2f | %-12.2f\n",
               empList[i].id, 
               empList[i].name, 
               empList[i].department, 
               empList[i].basicSalary, 
               empList[i].housingAllowance, 
               empList[i].transportAllowance, 
               empList[i].grossSalary);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}

// Searches for an employee using their unique ID
void searchEmployee(struct Employee empList[], int count) {
    if (count == 0) {
        printf("\nNo employees to search.\n");
        return;
    }

    char searchId[20];
    
    // ask user for input employee id to search
    printf("\nEnter Employee ID to search: ");
    scanf("%19s", searchId);

    for (int i = 0; i < count; i++) {
        if (strcmp(empList[i].id, searchId) == 0) {
            printf("\n--- Employee Found ---\n");
            printf("ID: %s\n", empList[i].id);
            printf("Name: %s\n", empList[i].name);
            printf("Department: %s\n", empList[i].department);
            printf("Basic Salary: $%.2f\n", empList[i].basicSalary);
            printf("Housing Allowance: $%.2f\n", empList[i].housingAllowance);
            printf("Transport Allowance: $%.2f\n", empList[i].transportAllowance);
            printf("Gross Salary: $%.2f\n", empList[i].grossSalary);
            return;
        }
    }

    printf("\nEmployee with ID '%s' not found.\n", searchId);
}

// Sub-menu specifically for handling Employee Management options
void employeeMenu(struct Employee empList[], int *count) {
    int choice;
    do {
        printf("\n-----------------------------------------\n");
        printf(" EMPLOYEE MANAGEMENT SUB-MENU \n");
        printf("-----------------------------------------\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Return to Main Menu\n");
        printf("-----------------------------------------\n");
        
        // ask user for input sub-menu choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(empList, count);
                break;
            case 2:
                displayEmployees(empList, *count);
                break;
            case 3:
                searchEmployee(empList, *count);
                break;
            case 4:
                printf("\nReturning to Main Menu...\n");
                break;
            default:
                printf("\nInvalid choice! Please select 1-4.\n");
        }
    } while (choice != 4);
}
