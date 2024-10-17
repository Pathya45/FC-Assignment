#include <stdio.h> 
#include <string.h> 
 
struct Student { 
    int roll_number; 
    char name[50]; 
    float marks[3]; 
    float percentage; 
}; 
 

void calculatePercentage(struct Student *student) { 
    student->percentage = (student->marks[0] + student->marks[1] + student->marks[2]) / 3; 
} 
 

void acceptDetails(struct Student *students, int n) { 
    for (int i = 0; i < n; i++) { 
        printf("Enter details for student %d\n", i + 1); 
        printf("Roll Number: "); 
        scanf("%d", &students[i].roll_number); 
        printf("Name: "); 
        scanf(" %[^\n]", students[i].name); 
        printf("Enter marks for 3 subjects: "); 
        for (int j = 0; j < 3; j++) { 
            scanf("%f", &students[i].marks[j]); 
        } 
        calculatePercentage(&students[i]);
    } 
} 
 

void displayAll(struct Student *students, int n) { 
    for (int i = 0; i < n; i++) { 
        printf("\nRoll Number: %d\n", students[i].roll_number); 
        printf("Name: %s\n", students[i].name); 
        printf("Marks: %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], 
students[i].marks[2]); 
        printf("Percentage: %.2f%%\n", students[i].percentage); 
    } 
} 
 

void searchStudent(struct Student *students, int n, int roll_number) { 
    for (int i = 0; i < n; i++) { 
        if (students[i].roll_number == roll_number) { 
            printf("Student found:\n"); 
            printf("Roll Number: %d\n", students[i].roll_number); 
            printf("Name: %s\n", students[i].name); 
            printf("Percentage: %.2f%%\n", students[i].percentage); 
            return; 
        } 
    } 
    printf("Student with roll number %d not found.\n", roll_number); 
} 
 

void modifyStudent(struct Student *students, int n, int roll_number) { 
    for (int i = 0; i < n; i++) { 
        if (students[i].roll_number == roll_number) { 
            printf("Enter new details for student %d\n", roll_number); 
            printf("Name: "); 
            scanf(" %[^\n]", students[i].name); 
            printf("Enter marks for 3 subjects: "); 
            for (int j = 0; j < 3; j++) { 
                scanf("%f", &students[i].marks[j]); 
            } 
            calculatePercentage(&students[i]); 
            printf("Details modified successfully.\n"); 
            return; 
        } 
    } 
    printf("Student with roll number %d not found.\n", roll_number); 
} 
 

void displayAbovePercentage(struct Student *students, int n, float percentage) { 
    int found = 0; 
    for (int i = 0; i < n; i++) { 
        if (students[i].percentage > percentage) { 
            printf("\nRoll Number: %d\n", students[i].roll_number); 
            printf("Name: %s\n", students[i].name); 
            printf("Percentage: %.2f%%\n", students[i].percentage); 
            found = 1; 
        } 
    } 
    if (!found) { 
        printf("No students found with percentage above %.2f%%\n", percentage); 
    } 
} 
 

void displayMaxPercentage(struct Student *students, int n) { 
    int maxIndex = 0; 
    for (int i = 1; i < n; i++) { 
        if (students[i].percentage > students[maxIndex].percentage) { 
            maxIndex = i; 
        } 
    } 
    printf("\nStudent with the maximum percentage:\n"); 
    printf("Roll Number: %d\n", students[maxIndex].roll_number); 
    printf("Name: %s\n", students[maxIndex].name); 
    printf("Percentage: %.2f%%\n", students[maxIndex].percentage); 
} 
 
int main() { 
    int n, choice, roll_number; 
    float percentage; 
 
   
    printf("Enter the number of students: "); 
    scanf("%d", &n); 
 
   
    struct Student students[n]; 
 
    
    acceptDetails(students, n); 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Search for a student by roll number\n"); 
        printf("2. Modify student details\n"); 
        printf("3. Display all student details\n"); 
        printf("4. Display students with percentage greater than a specified value\n"); 
        printf("5. Display student with the maximum percentage\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter roll number to search: "); 
                scanf("%d", &roll_number); 
                searchStudent(students, n, roll_number); 
                break; 
 
            case 2: 
                printf("Enter roll number to modify: "); 
                scanf("%d", &roll_number); 
                modifyStudent(students, n, roll_number); 
                break; 
 
            case 3: 
                displayAll(students, n); 
                break; 
 
            case 4: 
                printf("Enter percentage to display students above this value: "); 
                scanf("%f", &percentage); 
                displayAbovePercentage(students, n, percentage); 
                break; 
 
            case 5: 
                displayMaxPercentage(students, n); 
                break; 
 
            case 6: 
                printf("Exiting program...\n"); 
                break; 
 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
} 
 

 
