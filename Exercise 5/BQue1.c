#include<stdio.h>

void mergeArrays(int a1[], int n1, int a2[], int n2, int a3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a1[i] < a2[j]) {
            a3[k++] = a1[i++];
        } else {
            a3[k++] = a2[j++];
        }
    }

    while (i < n1) {
        a3[k++] = a1[j++];
    }

    while (j < n2) {
        a3[k++] = a2[j++];
    }
}

int main() {
    int a1[] = {10, 25, 90};
    int n1 = sizeof(a1) / sizeof(a1[0]);

    int a2[] = {9, 16, 22, 26, 10, 26, 90, 100};
    int n2 = sizeof(a2) / sizeof(a2[0]);

    int a3[n1 + n2];

    mergeArrays(a1, n1, a2, n2, a3);

    printf("Merged Array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d", a3[i]);
    }
    printf("\n");

    return 0;
}