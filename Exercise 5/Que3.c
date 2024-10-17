#include<stdio.h>

int search(int arr[10], int key, int n){
    for(int i=0; i<n; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

void main(){
    int n, key;
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the key which you want to search : ");
    scanf("%d", &key);
    int pos = search(arr, key, n);

    if(pos != -1){
        printf("%d is present at %dth position \n", key, pos);
    }else{
        printf("%d is not present in the array\n", key);
    }
}