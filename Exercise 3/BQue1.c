#include<stdio.h>

int is_prime(int num) {
    for(int i = 2; i <=num; i++) {
        if(num%i == 0)
        return 0;
    }
}

int main() {
    int num;
    for(int j = 0; j <= 10; j++) {
        if(is_prime(j)) {
            printf("Number %d is Prime\n",j);
        }
    }
}