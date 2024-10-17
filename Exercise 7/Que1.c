#include<stdio.h>
#include<string.h>

int main() {
    char str[100], ch;
    int i, count = 0, j;

    printf("Enter the String:");
    fgets(str, 100, stdin);

    printf("Enter the Character:");
    scanf("%c", &ch);

    for(i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count ++;
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
    printf("Number of occurrence of '%c': %d\n", ch,count);

    printf("Remaining string: %s", str);

    return 0;
}