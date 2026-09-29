#include <stdio.h>
#include <string.h>
#include "suppliers.h"


/* ---------- Add Supplier ---------- */

void addSupplier(Supplier suppliers[], int *supplierCount)
{
    if (*supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier list is full.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             ADD SUPPLIER\n");
    printf("========================================\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &suppliers[*supplierCount].supplierID);

    while (getchar() != '\n')
    {
        /* Clear input buffer */
    }

    printf("Enter Supplier Name: ");
    fgets(suppliers[*supplierCount].name,
          sizeof(suppliers[*supplierCount].name), stdin);

    suppliers[*supplierCount].name[
        strcspn(suppliers[*supplierCount].name, "\n")
    ] = '\0';


    printf("Enter Email: ");
    fgets(suppliers[*supplierCount].email,
          sizeof(suppliers[*supplierCount].email), stdin);

    suppliers[*supplierCount].email[
        strcspn(suppliers[*supplierCount].email, "\n")
    ] = '\0';


    printf("Enter Phone: ");
    fgets(suppliers[*supplierCount].phone,
          sizeof(suppliers[*supplierCount].phone), stdin);

    suppliers[*supplierCount].phone[
        strcspn(suppliers[*supplierCount].phone, "\n")
    ] = '\0';


    printf("Enter Town: ");
    fgets(suppliers[*supplierCount].town,
          sizeof(suppliers[*supplierCount].town), stdin);

    suppliers[*supplierCount].town[
        strcspn(suppliers[*supplierCount].town, "\n")
    ] = '\0';


    (*supplierCount)++;

    printf("\nSupplier added successfully.\n");
}


/* ---------- Display Suppliers ---------- */

void displaySuppliers(Supplier suppliers[], int supplierCount)
{
    int i;

    printf("\n========================================\n");
    printf("           SUPPLIER LIST\n");
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


/* ---------- Search Supplier ---------- */

void searchSupplier(Supplier suppliers[], int supplierCount)
{
    int id;
    int i;
    int found = 0;

    printf("\n========================================\n");
    printf("           SEARCH SUPPLIER\n");
    printf("========================================\n");

    if (supplierCount == 0)
    {
        printf("No suppliers have been recorded yet.\n");
        return;
    }

    printf("Enter Supplier ID: ");
    scanf("%d", &id);

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID == id)
        {
            printf("\nSupplier Found\n");
            printf("----------------------------------------\n");

            printf("Supplier ID : %d\n", suppliers[i].supplierID);
            printf("Name        : %s\n", suppliers[i].name);
            printf("Email       : %s\n", suppliers[i].email);
            printf("Phone       : %s\n", suppliers[i].phone);
            printf("Town        : %s\n", suppliers[i].town);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier with ID %d was not found.\n", id);
    }
}


/* ---------- Update Supplier ---------- */

void updateSupplier(Supplier suppliers[], int supplierCount)
{
    int id;
    int i;
    int found = 0;

    printf("\n========================================\n");
    printf("           UPDATE SUPPLIER\n");
    printf("========================================\n");

    if (supplierCount == 0)
    {
        printf("No suppliers have been recorded yet.\n");
        return;
    }

    printf("Enter Supplier ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID == id)
        {
            while (getchar() != '\n')
            {
                /* Clear input buffer */
            }

            printf("Enter new Supplier Name: ");

            fgets(suppliers[i].name,
                  sizeof(suppliers[i].name), stdin);

            suppliers[i].name[
                strcspn(suppliers[i].name, "\n")
            ] = '\0';


            printf("Enter new Email: ");

            fgets(suppliers[i].email,
                  sizeof(suppliers[i].email), stdin);

            suppliers[i].email[
                strcspn(suppliers[i].email, "\n")
            ] = '\0';


            printf("Enter new Phone: ");

            fgets(suppliers[i].phone,
                  sizeof(suppliers[i].phone), stdin);

            suppliers[i].phone[
                strcspn(suppliers[i].phone, "\n")
            ] = '\0';


            printf("Enter new Town: ");

            fgets(suppliers[i].town,
                  sizeof(suppliers[i].town), stdin);

            suppliers[i].town[
                strcspn(suppliers[i].town, "\n")
            ] = '\0';


            printf("\nSupplier updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier with ID %d was not found.\n", id);
    }
}


/* ---------- Delete Supplier ---------- */

void deleteSupplier(Supplier suppliers[], int *supplierCount)
{
    int id;
    int i;
    int j;
    int found = 0;

    printf("\n========================================\n");
    printf("           DELETE SUPPLIER\n");
    printf("========================================\n");

    if (*supplierCount == 0)
    {
        printf("No suppliers have been recorded yet.\n");
        return;
    }

    printf("Enter Supplier ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *supplierCount; i++)
    {
        if (suppliers[i].supplierID == id)
        {
            /* Move the remaining suppliers one position left */

            for (j = i; j < *supplierCount - 1; j++)
            {
                suppliers[j] = suppliers[j + 1];
            }

            (*supplierCount)--;

            printf("\nSupplier deleted successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier with ID %d was not found.\n", id);
    }
}


/* ---------- Supplier Management Menu ---------- */

void displaySupplierMenu(Supplier suppliers[], int *supplierCount)
{
    int choice;
    int running = 1;

    while (running == 1)
    {
        printf("\n========================================\n");
        printf("        SUPPLIER MANAGEMENT MENU\n");
        printf("========================================\n");

        printf("1. Add Supplier\n");
        printf("2. View Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Update Supplier\n");
        printf("5. Delete Supplier\n");
        printf("6. Back to Main Menu\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n')
            {
                /* Clear invalid input */
            }

            continue;
        }

        switch (choice)
        {
            case 1:
                addSupplier(suppliers, supplierCount);
                break;

            case 2:
                displaySuppliers(suppliers, *supplierCount);
                break;

            case 3:
                searchSupplier(suppliers, *supplierCount);
                break;

            case 4:
                updateSupplier(suppliers, *supplierCount);
                break;

            case 5:
                deleteSupplier(suppliers, supplierCount);
                break;

            case 6:
                running = 0;
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    }
}