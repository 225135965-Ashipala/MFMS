#include <stdio.h>
#include <string.h>

#define MAX 50

//Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char department[50];
    double salary;
    double housing;
    double transport;
};

//function Prototypes
void addEmployee(struct Employee employees[], int *count);
void displayEmployees(struct Employee employees[], int count);
void searchEmployee(struct Employee employees[], int count);

int main(){
    struct Employee employees[MAX];
    int count = 0;
    int choice;

    //Use loop to display the menu until user exits
    do{
        printf("\n============\n");
        printf(" EMPLOYEE MANAGEMENT\n");
        printf("================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("============\n");

        // Ask user to thier user menu choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Direct the user based on their selection
        if (choice == 1){
            addEmployee(employees, &choice);
        }
        else if (choice == 2){
            displayEmployees(employees, count);
        }
        else if (choice == 3){
            searchEmployee(employees, count);
        }else if (choice == 4){
            printf("Goodbye!");
        }
        else {
            printf("Invalid choice.");
        }
    } while (choice != 4);

    return 0;
}

//Function to add a new employee
void addEmployee(struct Employee employees[], int *count){
    //Check if the employee list is full
    if (*count >= MAX){
        printf("\nEmployee list is full!\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    //Ask user to input employee ID
    printf("Enter employee ID: ");
    scanf("%d", &employees[*count].id);
    getchar();

    //Ask user to input employee name
    printf("Enter employee name: ");
    fgets(employees[*count].name, 50, stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = '\0';

    //Ask user to input department
    printf("Enter department: ");
    fgets(employees[*count].department, 50, stdin);
    employees[*count].department[strcspn(employees[*count].department, "\n")] = '\0';

    //Ask user to input basic salary
    printf("Enter basic salary: ");
    scanf("%lf", &employees[*count].salary);

    //Ask user to input housing allowance
    printf("Enter housing allowance: ");
    scanf("%lf", &employees[*count].housing);

    //Ask user to input transport allowance
    printf("Enter transport allowance: ");
    scanf("%lf", &employees[*count].transport);

    //Increment the employee count
    *count = *count + 1;
    printf("\nEployee added successfully!\n");
}

//Function to display all employees
void displayEmployees(struct Employee employees[], int count){
    int i;
    printf("\n--- Employee List ---\n");

    //Check if there are any records to display
    if (count == 0){
        printf("No employees found.\n");
    }
    else {
        //Loop through and display each employee's details
        for (i = 0; i < count; i++) {
            printf("\nEmployee %d\n", 1 + 1);
            printf("ID: %d\n", employees[i].id);
            printf("Name:%s\n",employees[i].name);
            printf("Department: %s\n, employees[i].department");
            printf("Basic Salary: N$ %.2f\n", employees[i].salary);
            printf("Housing Allowance: N$ %.2f\n, employees[i].housing");
            printf("Transport Allowance: N$ %.2f\n", employees[i].transport);

            //Calculate and display total salary
            printf("Total Salary: N$ %.2lf\n", employees[i].salary + employees[i].housing + employees[i].transport);
        }
    }
}

//Function to search for a specific employee by ID
void searchEmployee(struct Employee employees[], int count){
    int id;
    int i;
    int found = 0;

    printf("\n--- Search Employee --\n");

    //Ask user to input the taget employee ID
    printf("Enter employee ID: ");
    scanf("%d", id);

    //To look for a matching ID in the system
    for (i = 0; i < count; i++){
        if (employees[i].id == id){
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].department);
            printf("Basic Salary: N$%.2f\n", employees[i].salary);
            printf("Housing Allowance: N$ %.2f\n", employees[i].housing);
            printf("TransportAllowance: N$ %.2f\n", employees[i].transport);

            //Calcultae and display total salary for the found employee
            printf("Tota Slary: N$ %.2f\n", employees[i].salary + employees[i].housing + employees[i].transport);
            found = 1;
        }
    }

    //Display error message if no match was found
    if (found = 0){
        printf("\nEmployee not found.\n");
    }
}