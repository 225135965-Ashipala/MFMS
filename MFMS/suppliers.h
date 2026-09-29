#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50

/* ---------- Supplier Data Structure ---------- */

typedef struct
{
    int supplierID;
    char name[50];
    char email[50];
    char phone[20];
    char town[30];

} Supplier;


/* ---------- Supplier Management Functions ---------- */

void addSupplier(Supplier suppliers[], int *supplierCount);

void displaySuppliers(Supplier suppliers[], int supplierCount);

void searchSupplier(Supplier suppliers[], int supplierCount);

void updateSupplier(Supplier suppliers[], int supplierCount);

void deleteSupplier(Supplier suppliers[], int *supplierCount);

void displaySupplierMenu(Supplier suppliers[], int *supplierCount);

#endif