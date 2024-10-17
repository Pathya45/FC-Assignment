#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void search_city(char **cities, int n, char *city)
{
    int found =0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(cities[i], city)== 0)
        {
            printf(" \n city '%s' foundat position %d ", city ,i+1);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\n city '%s' not found", city);
    }
}

void display_longest_city(char **cities, int n)
{
    int maxLength =0;
    char *longestCity = NULL;
    for(int i=0;i<n;i++){
        if(strlen(cities[i])> maxLength){
            maxLength = strlen(cities[i]);
            longestCity= cities[i];
        }
    }
    if(longestCity != NULL){
        printf("\n the longest city name is %s\n", longestCity);
    }
}

void sortCities(char **cities, int n){
    char *temp;
    
    for(int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(cities[i],cities[j])>0){
                temp = cities[i];
                cities[i]=cities[j];
                cities[j]=temp;
            }
        }
    }
    printf("\n sorted list of cities:");
    for(int i =0;i<n;i++)
    {
        printf(" %s \n", cities[i]);
    }
}


int main(){
    int n; 
    char **cities;
    char cityToSearch[100];

    printf("enter the no. of cities:");
    scanf("%d", &n);

    cities=(char **)malloc(n *sizeof(char *));
    for(int i=0;i<n;i++){
        cities[i]=(char *)malloc(100 * sizeof(char));
    }

    printf("enter the names of %d cities : \n",n);
    for(int i=0; i<n; i++){
        printf("city %d", i+1);
        scanf("%s", cities[i]);
    }

    printf("\n enter the city to search :");
    scanf(" %s", cityToSearch);
    search_city(cities, n, cityToSearch);

    display_longest_city(cities,n);
    sortCities(cities, n);
    for(int i=0; i<n;i++){
        free(cities[i]);
    }
    free(cities);
    return 0;
}