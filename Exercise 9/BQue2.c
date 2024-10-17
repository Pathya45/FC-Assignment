#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
void sortString(char *str, int order) { 
    int n = strlen(str); 
    char temp; 
 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if ((order == 0 && str[i] > str[j]) || (order == 1 && str[i] < str[j])) { 
                temp = str[i]; 
                str[i] = str[j]; 
                str[j] = temp; 
            } 
        } 
    } 
} 
 
int main(int argc, char *argv[]) { 
    if (argc != 3) { 
        printf("Error: Please provide exactly 2 arguments (string and an integer 0 or 1).\n"); 
        return 1; 
    } 
 
    char *str = argv[1]; 
    int order = atoi(argv[2]); 
 
    if (order != 0 && order != 1) { 
        printf("Error: The second argument must be 0 (ascending) or 1 (descending).\n"); 
        return 1; 
    } 
 
    sortString(str, order); 
    printf("Sorted string: %s\n", str); 
 
    return 0; 
} 