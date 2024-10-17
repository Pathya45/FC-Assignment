#include<stdio.h>
#include<ctype.h>
int main()
{
    char ch;
    int n;
    
    printf("enter a variable=");
    scanf("%c",&ch);
    do{
    printf("\n 1: is alphabet");
    printf("\n 2: is digit");
    printf("\n 3: is in lower case");
    printf("\n 4: is in upper case");
    printf("\n 5: convert to upper");
    printf("\n 6: convert6 to lower");
    printf("\n 7 : exit");
    printf("\nenter choice:");
    scanf("%d",&n);
    switch(n){
    case 1: if(isalpha(ch))
    {
        printf("\nalphabet");
    }
    break;
    case 2: if(isdigit(ch))
    {
        printf("\ndigit");
    }
    else printf("\nnot a digit");
    break;
    case 3: if(islower(ch))
    {
        printf("\nlower case");
    }
    break;
    case 4: if(isupper(ch))
    {printf("\nupper case");
    }
    break;
    case 5: printf("%c",toupper(ch));
    break;
    case 6: printf("%c",tolower(ch));
    break;
    }
    }while(n!=7);

}