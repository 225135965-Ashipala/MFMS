# Municipal Financial Management System (MFMS)

Project: Project A – Foundation System

## Group Members and github resposnibilities
200710052                Testing, documentation and Git coordination
223059056-Hamupolo       Supplier management
225135965-Ashipala       Asset management
224095501-SINDERE        Employee management   
218089104-nuugulu        budget management
225017156-Hafenanye      Reports
224072455-andreas        Functions, integration and validation
## Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C console
application developed as the foundation version of a financial management
system for a municipality. It allows municipal staff to manage employee
records, departmental budgets, suppliers, and municipal assets, and to
generate summary reports across all four areas.

This is Project A — the foundation stage, built using the core C
programming concepts covered in Weeks 1–8 of the course (I/O, variables,
operators, decisions, loops, arrays, strings, and functions). Project A will
be extended and refactored in Project B.

## System Features

- **Main Menu** — central navigation to all modules
- **Employee Management** — add, display, search employees; calculate
  salary (basic + housing allowance + transport allowance)
- **Budget Management** — record departmental allocated budget and
  expenditure; calculate remaining budget; flag departments that have
  exceeded their allocation
- **Supplier Management** — add, display, search, update and delete
  suppliers (ID, name, email, phone, town)
- **Asset Management** — register municipal assets (vehicles, computers,
  buildings, equipment); display and update asset records
- **Reports** — Employee Report (total/average/highest/lowest salary),
  Budget Report (total allocated, total expenditure, remaining, departments
  over budget), Supplier Report, and Asset Report (with total registered
  value)
- **Input validation** — rejects negative salaries/budgets, handles invalid
  menu choices, checks for empty required fields

## Project Structure


MFMS/
├── main.c
├── employees.c / employees.h
├── budget.c     / budget.h
├── suppliers.c  / suppliers.h
├── assets.c     / assets.h
├── reports.c    / reports.h
└── README.md


## Compilation Instructions

Requires `gcc` (any ANSI C / C99-compliant compiler).

From inside the `MFMS/` folder, compile all source files together:

```bash
gcc -o mfms main.c employees.c budget.c suppliers.c assets.c reports.c -Wall
```

This produces an executable named `mfms.exe`.

## How to Run

```bash
mfms.exe      # Windows
```

Follow the on-screen menu to navigate between Employee Management, Budget
Management, Supplier Management, Asset Management, and Reports.

## Individual Responsibilities

See the table under **Group Members and responsibilities** above, and each member's individual
Contribution Record submitted separately on elearning for full detail on
functions written, testing performed, and GitHub activity.

## Known Limitations (Project A)

This is a foundation version; data is not saved between runs (no file or
  database persistence yet) — planned for Project B.
