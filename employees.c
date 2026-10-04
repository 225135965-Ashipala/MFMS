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

int addEmployee(struct Employee emp[], int employee_count);
int displayEmployee(const struct Employee emp[], int employee_count);
int searchEmployee(const struct Employee emp[], int employee_count);
int calculateSalary(const struct Employee emp[], int employee_count);
int displayMunicipalityTowns(const struct Employee emp[], int employee_count);
void displayMenu();
void employeeMenu();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice = 0;
    do {
        printf("=======================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("=======================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        switch (choice) {
            case 1:
                employeeMenu();
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                printf("Module under development.\n\n");
                break;
            case 6:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Wrong Choice. Try again.\n\n");
        }
    } while (choice != 6);
}

void employeeMenu() {
    int choice = 0;
    int employee_count = 0;
    static struct Employee emp[10];
    static int total_employees = 0;
    do {
        printf("\n=====================\n");
        printf("EMPLOYEE MANAGEMENT\n");
        printf("=====================\n");
        printf("1. Add an employee\n");
        printf("2. Display employees\n");
        printf("3. Search for an employee\n");
        printf("4. Calculate employee salary information\n");
        printf("5. Display Municipality's Towns\n");
        printf("6. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of employees to add: ");
                scanf("%d", &employee_count);
                total_employees = addEmployee(emp, total_employees);
                break;
            case 2:
                displayEmployee(emp, total_employees);
                break;
            case 3:
                searchEmployee(emp, total_employees);
                break;
            case 4:
                calculateSalary(emp, total_employees);
                break;
            case 5:
                displayMunicipalityTowns(emp, total_employees);
                break;
            case 6:
                return;
            default:
                printf("Wrong Choice. Try again.\n");
        }
    } while (choice != 6);
}

int addEmployee(struct Employee emp[], int employee_count) {
    int n;
    printf("Enter how many records to append: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", employee_count + 1);
        printf("ID: ");
        scanf("%d", &emp[employee_count].id);
        getchar();
        printf("Name: ");
        scanf("%49[^\n]", emp[employee_count].name);
        getchar();
        printf("Department: ");
        scanf("%49[^\n]", emp[employee_count].department);
        getchar();
        printf("Basic Salary: ");
        scanf("%f", &emp[employee_count].basic_salary);
        printf("House Allowance: ");
        scanf("%f", &emp[employee_count].house_allowance);
        printf("Transport Allowance: ");
        scanf("%f", &emp[employee_count].transport_allowance);
        getchar();
        printf("Town: ");
        scanf("%49[^\n]", emp[employee_count].town);
        getchar();
        employee_count++;
    }
    printf("Employees added successfully!\n");
    return employee_count;
}

int displayEmployee(const struct Employee emp[], int employee_count) {
    if (employee_count == 0) {
        printf("\nNo employees added yet.\n");
        return 0;
    }
    printf("\n==========================================\n");
    printf("EMPLOYEE LIST\n");
    printf("==========================================\n");
    for (int i = 0; i < employee_count; i++) {
        printf("ID: %d | Name: %s | Dept: %s | Basic: %.2f | House Allowance: %.2f | Transport Allowance: %.2f | Municipality Town: %s\n", 
               emp[i].id, emp[i].name, emp[i].department, emp[i].basic_salary, emp[i].house_allowance, emp[i].transport_allowance, emp[i].town);
    }
    return employee_count;
}

int searchEmployee(const struct Employee emp[], int employee_count) {
    if (employee_count == 0) {
        printf("\nNo records to search.\n");
        return 0;
    }
    int searchChoice;
    int searchResultCount = 0;
    printf("\n=====================\n");
    printf("SEARCH EMPLOYEE\n");
    printf("=====================\n");
    printf("1. Search by ID\n");
    printf("2. Search by Department\n");
    printf("3. Search by Town\n");
    printf("Enter choice: ");
    scanf("%d", &searchChoice);
    
    if (searchChoice == 1) {
        int searchId;
        printf("Enter Employee ID: ");
        scanf("%d", &searchId);
        for (int i = 0; i < employee_count; i++) {
            if (emp[i].id == searchId) {
                printf("\nEmployee(s)' ID Found\n");
                printf("\n===============================================================\n");
                printf("ID: %d | Name: %s | Dept: %s | Town: %s | Salary: %.2f\n", 
                       emp[i].id, emp[i].name, emp[i].department, emp[i].town, emp[i].basic_salary);
                searchResultCount++;
                break;
            }
        }
    } 
    else if (searchChoice == 2) {
        char searchDept[50];
        printf("Enter Department Name: ");
        scanf("%s", searchDept);
        for (int i = 0; i < employee_count; i++) {
            if (strcasecmp(emp[i].department, searchDept) == 0) {
                printf("\nEmployee(s)' Department Found\n");
                printf("\n===============================================================\n");
                printf("ID: %d | Name: %s | Dept: %s | Town: %s | Salary: %.2f\n", 
                       emp[i].id, emp[i].name, emp[i].department, emp[i].town, emp[i].basic_salary);
                searchResultCount++;
            }
        }
    } 
    else if (searchChoice == 3) {
        char searchTown[50];
        printf("Enter Town Name: ");
        scanf("%s", searchTown);
        for (int i = 0; i < employee_count; i++) {
            if (strcasecmp(emp[i].town, searchTown) == 0) {
                printf("\nEmployee(s)' Municipality Town Found\n");
                printf("\n===============================================================\n");
                printf("ID: %d | Name: %s | Dept: %s | Town: %s | Salary: %.2f\n", 
                       emp[i].id, emp[i].name, emp[i].department, emp[i].town, emp[i].basic_salary);
                searchResultCount++;
            }
        }
    } 
    else {
        printf("Invalid choice.\n");
        return 0;
    }
    if (searchResultCount == 0) {
        printf("Not found.\n");
    } else {
        printf("\nTotal found: %d\n", searchResultCount);
    }
    return searchResultCount;
}

int calculateSalary(const struct Employee emp[], int employee_count) {
    if (employee_count == 0) {
        printf("\nNo employees added for salary calculation.\n");
        return 0;
    }
    printf("\n==========================================\n");
    printf("EMPLOYEE SALARY CALCULATIONS\n");
    printf("==========================================\n");
    for (int i = 0; i < employee_count; i++) {
        float gross = emp[i].basic_salary + emp[i].house_allowance + emp[i].transport_allowance;
        printf("ID: %d | Name: %s | Gross Salary: %.2f\n", emp[i].id, emp[i].name, gross);
    }
    return employee_count;
}

int displayMunicipalityTowns(const struct Employee emp[], int employee_count) {
    if (employee_count == 0) {
        printf("\nNo Municipality towns added yet.\n");
        return 0;
    }
    printf("\n==========================================\n");
    printf("REGISTERED MUNICIPALITY TOWNS \n");
    printf("==========================================\n");
    for (int i = 0; i < employee_count; i++) {
        printf("- %s (Employee: %s)\n", emp[i].town, emp[i].name);
    }
    return employee_count;
}
