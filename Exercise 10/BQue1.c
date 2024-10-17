#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_NAME_LEN 100 
 
struct Student { 
    int roll_no; 
    char name[MAX_NAME_LEN]; 
    float percentage; 
}; 
 
void createFile(const char *filename) { 
    FILE *file = fopen(filename, "wb"); 
    if (file == NULL) { 
        perror("Error creating file"); 
        exit(1); 
    } 
 
    struct Student student; 
    for (int i = 0; i < 5; i++) { 
        printf("Enter roll number, name and percentage for student %d:\n", i + 1); 
        printf("Roll Number: "); 
        scanf("%d", &student.roll_no); 
        printf("Name: "); 
        scanf("%s", student.name); 
        printf("Percentage: "); 
        scanf("%f", &student.percentage); 
        fwrite(&student, sizeof(struct Student), 1, file); 
    } 
 
    fclose(file); 
} 
 
void mergeFiles(const char *file1, const char *file2, const char *outputFile) { 
    FILE *f1 = fopen(file1, "rb"); 
    FILE *f2 = fopen(file2, "rb"); 
    FILE *out = fopen(outputFile, "wb"); 
     
    if (f1 == NULL || f2 == NULL || out == NULL) { 
        perror("Error opening file"); 
        exit(1); 
    } 
 
    struct Student s1, s2; 
    int read1 = fread(&s1, sizeof(struct Student), 1, f1); 
    int read2 = fread(&s2, sizeof(struct Student), 1, f2); 
 
    while (read1 == 1 && read2 == 1) { 
        if (s1.percentage <= s2.percentage) { 
            fwrite(&s1, sizeof(struct Student), 1, out); 
            read1 = fread(&s1, sizeof(struct Student), 1, f1); 
        } else { 
            fwrite(&s2, sizeof(struct Student), 1, out); 
            read2 = fread(&s2, sizeof(struct Student), 1, f2); 
        } 
    } 
 
    while (read1 == 1) { 
        fwrite(&s1, sizeof(struct Student), 1, out); 
        read1 = fread(&s1, sizeof(struct Student), 1, f1); 
    } 
 
    while (read2 == 1) { 
        fwrite(&s2, sizeof(struct Student), 1, out); 
        read2 = fread(&s2, sizeof(struct Student), 1, f2); 
    } 
 
    fclose(f1); 
    fclose(f2); 
    fclose(out); 
} 
 
void displayFile(const char *filename) { 
    FILE *file = fopen(filename, "rb"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        exit(1); 
    } 
 
    struct Student student; 
    printf("Contents of %s:\n", filename); 
    while (fread(&student, sizeof(struct Student), 1, file) == 1) { 
        printf("Roll No: %d, Name: %s, Percentage: %.2f\n", student.roll_no, student.name, 
student.percentage); 
    } 
 
    fclose(file); 
} 
 
int main(int argc, char *argv[]) { 
    if (argc != 4) { 
        printf("Usage: %s <file1> <file2> <output_file>\n", argv[0]); 
        return 1; 
    } 
 
    createFile(argv[1]); 
    createFile(argv[2]); 
    mergeFiles(argv[1], argv[2], argv[3]); 
 
    displayFile(argv[1]); 
    displayFile(argv[2]); 
    displayFile(argv[3]); 
 
    return 0; 
} 