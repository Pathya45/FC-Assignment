#include<stdio.h>

void print(int arr[], int n){
    printf("Array Elements Are\n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void accept(int arr[], int n){
    printf("Enter the Array elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            } 
        }
    }
}

void main(){
    int arr[10], n;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    accept(arr, n);
    print(arr, n);
    sort(arr, n);
    printf("Array After sorting\n");
    print(arr, n);
}   