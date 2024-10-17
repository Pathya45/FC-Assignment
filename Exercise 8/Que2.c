#include <stdio.h> 
#include <string.h> 
 
#define MAX_EMPLOYEES 100 
 

struct Employee { 
    int id; 
    char name[50]; 
    float salary; 
}; 
 

void searchByName(struct Employee employees[], int n, char name[]); 
void searchById(struct Employee employees[], int n, int id); 
void displayAll(struct Employee employees[], int n); 
void displaySalaryGreaterThan(struct Employee employees[], int n, float salary); 
void displayMaxSalaryEmployee(struct Employee employees[], int n); 
 
int main() { 
    struct Employee employees[MAX_EMPLOYEES]; 
    int n, choice, id; 
    char name[50]; 
    float salary; 

    printf("Enter the number of employees: "); 
    scanf("%d", &n); 
 
 
    for (int i = 0; i < n; i++) { 
        printf("Enter details for employee %d\n", i + 1); 
        printf("ID: "); 
        scanf("%d", &employees[i].id); 
        printf("Name: "); 
        scanf("%s", employees[i].name); 
        printf("Salary: "); 
        scanf("%f", &employees[i].salary); 
    } 
 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Search by Name\n"); 
        printf("2. Search by ID\n"); 
        printf("3. Display All Employees\n"); 
        printf("4. Display Employees with Salary greater than X\n"); 
        printf("5. Display Employee with Maximum Salary\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter the name to search: "); 
                scanf("%s", name); 
                searchByName(employees, n, name); 
                break; 
            case 2: 
                printf("Enter the ID to search: "); 
                scanf("%d", &id); 
                searchById(employees, n, id); 
                break; 
            case 3: 
                displayAll(employees, n); 
                break; 
            case 4: 
                printf("Enter salary threshold: "); 
                scanf("%f", &salary); 
                displaySalaryGreaterThan(employees, n, salary); 
                break; 
            case 5: 
                displayMaxSalaryEmployee(employees, n); 
                break; 
            case 6: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
} 
 

void searchByName(struct Employee employees[], int n, char name[]) { 
    int found = 0; 
    for (int i = 0; i < n; i++) { 
        if (strcmp(employees[i].name, name) == 0) { 
            printf("Employee Found: ID = %d, Name = %s, Salary = %.2f\n", employees[i].id, 
employees[i].name, employees[i].salary); 
            found = 1; 
        } 
    } 
    if (!found) { 
        printf("Employee with name %s not found.\n", name); 
    } 
} 
 
 
void searchById(struct Employee employees[], int n, int id) { 
    int found = 0; 
    for (int i = 0; i < n; i++) { 
        if (employees[i].id == id) { 
            printf("Employee Found: ID = %d, Name = %s, Salary = %.2f\n", employees[i].id, 
employees[i].name, employees[i].salary); 
            found = 1; 
        } 
    } 
    if (!found) { 
        printf("Employee with ID %d not found.\n", id); 
    } 
} 
 

void displayAll(struct Employee employees[], int n) { 
    printf("\nAll Employees:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("ID = %d, Name = %s, Salary = %.2f\n", employees[i].id, employees[i].name, 
employees[i].salary); 
    } 
} 
 

void displaySalaryGreaterThan(struct Employee employees[], int n, float salary) { 
    printf("\nEmployees with salary greater than %.2f:\n", salary); 
    for (int i = 0; i < n; i++) { 
        if (employees[i].salary > salary) { 
            printf("ID = %d, Name = %s, Salary = %.2f\n", employees[i].id, employees[i].name, 
employees[i].salary); 
        } 
    } 
} 
 

void displayMaxSalaryEmployee(struct Employee employees[], int n) { 
    int maxIndex = 0; 
    for (int i = 1; i < n; i++) { 
        if (employees[i].salary > employees[maxIndex].salary) { 
            maxIndex = i; 
        } 
    } 
    printf("\nEmployee with maximum salary: ID = %d, Name = %s, Salary = %.2f\n", 
employees[maxIndex].id, employees[maxIndex].name, employees[maxIndex].salary); 
} 