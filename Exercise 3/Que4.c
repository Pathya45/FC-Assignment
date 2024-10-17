#include<stdio.h>
int next_char(char ch, int n)
{
    for(int i=1; i<=n;i++)
    {printf("%c",ch+i);
    }
}
void main()
{
    char ch;
    int n;
    printf("enter a charchter :");
    scanf("%c", & ch);
    printf("how manytimes to display :");
    scanf("%d",&n);

    next_char(ch,n);
}