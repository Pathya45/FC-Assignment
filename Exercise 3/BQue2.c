#include<stdio.h>
#include<ctype.h>
int check_char(char ch)
{
    if(isalpha(ch))
    {
        return 1;

    }
    else if(isdigit(ch))
    {
        return 2;

    }
    else 
    {
        return 3;
    }
}
int main()
{
    char ch;
    int result;
    int alphaCount = 0, digitCount =0 , specialCount =0;

    printf("enter charchters, press ctrl+d to stop\n");
    while((ch= getchar())!= EOF)
    {
        result = check_char(ch);
        if(result == 1)
        {
            printf("charchter %c is an alphabet", ch);
            alphaCount ++;
        }
        else if(result == 2)
        {
            printf("charchter %c is a digit\n", ch);
            digitCount ++;
        }
        else if(result == 3)
        {
            printf(" charchter %c is a special symbol\n",ch);
            specialCount ++;
        }
    }

    printf("alphabet count = %d \n digit count = %d \n special count = %d \n",alphaCount, digitCount, specialCount);
    
}