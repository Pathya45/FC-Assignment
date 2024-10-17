#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 

#define TV 1 
#define MOBILE 2 
#define CAMERA 3 
 

struct TV { 
    int size; 
    int type;  
}; 
 

struct Mobile { 
    int type;  
    char model[20]; 
}; 
 

struct Camera { 
    int resolution; 
    char model[20]; 
}; 
 

struct Item { 
    int id; 
    char companyName[50]; 
    int code; 
    float cost; 
    union { 
        struct TV tv; 
        struct Mobile mobile; 
        struct Camera camera; 
    } details; 
}; 
 

void displayAllItems(struct Item *items, int n); 
void searchItem(struct Item *items, int n, int id); 
void sortItemsByCost(struct Item *items, int n); 
void displayItem(struct Item item); 
const char* getItemType(int code); 
 
int main() { 
    int n, choice, id; 
    struct Item *items; 
 
   
    printf("Enter the number of items: "); 
    scanf("%d", &n); 
 

    items = (struct Item*) malloc(n * sizeof(struct Item)); 
 

    for (int i = 0; i < n; i++) { 
        printf("\nEnter details for item %d\n", i + 1); 
        printf("Item ID: "); 
        scanf("%d", &items[i].id); 
        printf("Company Name: "); 
        scanf("%s", items[i].companyName); 
        printf("Item Type (1-TV, 2-Mobile, 3-Camera): "); 
        scanf("%d", &items[i].code); 
        printf("Cost: "); 
        scanf("%f", &items[i].cost); 
 
        
        switch (items[i].code) { 
            case TV: 
                printf("TV Size: "); 
                scanf("%d", &items[i].details.tv.size); 
                printf("TV Type (1-CRT, 2-LCD, 3-Plasma): "); 
                scanf("%d", &items[i].details.tv.type); 
                break; 
            case MOBILE: 
                printf("Mobile Type (1-GSM, 2-CDMA): "); 
                scanf("%d", &items[i].details.mobile.type); 
                printf("Mobile Model Number: "); 
                scanf("%s", items[i].details.mobile.model); 
                break; 
            case CAMERA: 
                printf("Camera Resolution: "); 
                scanf("%d", &items[i].details.camera.resolution); 
                printf("Camera Model Number: "); 
                scanf("%s", items[i].details.camera.model); 
                break; 
            default: 
                printf("Invalid item type.\n"); 
                i--; 
        } 
    } 
 

    do { 
        printf("\nMenu:\n"); 
        printf("1. Display All Items\n"); 
        printf("2. Search for Specific Item by ID\n"); 
        printf("3. Sort Items by Cost\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                displayAllItems(items, n); 
                break; 
            case 2: 
                printf("Enter the Item ID to search: "); 
                scanf("%d", &id); 
                searchItem(items, n, id); 
                break; 
            case 3: 
                sortItemsByCost(items, n); 
                printf("\nItems sorted by cost.\n"); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 4); 
 
   
    free(items); 
 
    return 0; 
} 
 

void displayAllItems(struct Item *items, int n) { 
    printf("\nDisplaying all items:\n"); 
    for (int i = 0; i < n; i++) { 
        displayItem(items[i]); 
    } 
} 
 

void searchItem(struct Item *items, int n, int id) { 
    int found = 0; 
    for (int i = 0; i < n; i++) { 
        if (items[i].id == id) { 
            printf("\nItem found:\n"); 
            displayItem(items[i]); 
            found = 1; 
            break; 
        } 
    } 
    if (!found) { 
        printf("\nItem with ID %d not found.\n", id); 
    } 
} 
 

void sortItemsByCost(struct Item *items, int n) { 
    struct Item temp; 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (items[i].cost > items[j].cost) { 
                temp = items[i]; 
                items[i] = items[j]; 
                items[j] = temp; 
            } 
        } 
    } 
} 
 

void displayItem(struct Item item) { 
    printf("\nID: %d\n", item.id); 
    printf("Company Name: %s\n", item.companyName); 
    printf("Type: %s\n", getItemType(item.code)); 
    printf("Cost: %.2f\n", item.cost); 
 
     
    switch (item.code) { 
        case TV: 
            printf("TV Size: %d\n", item.details.tv.size); 
            printf("TV Type: %s\n", item.details.tv.type == 1 ? "CRT" : item.details.tv.type == 2 ? "LCD" : 
"Plasma"); 
            break; 
        case MOBILE: 
            printf("Mobile Type: %s\n", item.details.mobile.type == 1 ? "GSM" : "CDMA"); 
            printf("Mobile Model: %s\n", item.details.mobile.model); 
            break; 
        case CAMERA: 
            printf("Camera Resolution: %d\n", item.details.camera.resolution); 
            printf("Camera Model: %s\n", item.details.camera.model); 
            break; 
        default: 
            printf("Unknown item type.\n"); 
    } 
} 
 

const char* getItemType(int code) { 
    switch (code) { 
        case TV: 
            return "TV"; 
        case MOBILE: 
            return "Mobile Phone"; 
        case CAMERA: 
            return "Camera"; 
        default: 
            return "Unknown"; 
    } 
}