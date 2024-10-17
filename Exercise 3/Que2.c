#include<stdio.h>
#include<math.h>

int main()
{
   double x1,y1,x2,y2,ans;
   int ch;
   printf("\n enter point A:");
   scanf("%lf %lf",&x1,&y1);
   printf("\n enter point B:");
   scanf("%lf %lf",&x2,&y2);
   printf("\n 1. distance:");
   printf("\n 2. slope:");
   printf("\n 3. quadrant:");
   printf("\n 4. exit:");
   while(ch!=4)
{
   printf("\n enter a choice:");
   scanf("%d",&ch);
    switch(ch){
         case 1: ans=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                 ans= sqrt(ans);
                 printf("\n distance is %lf",ans);
                 break;
         case 2: ans=(y2-y1)/(x2-x1);
                 printf("\n slope is %lf ",ans);
                 break;
         case 3: if(x1>0 && x2>0 && y1>0 && y2>0)
                 printf("\n in same quadrant and in first quadrant");
                 break;         
}
}   
}