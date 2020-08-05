#include<stdio.h>
//#define N 5
typedef struct knapsac{
float wt;
float val;
float ppw;
}Knapsack;


int max(int a, int b)
{
    return (a > b) ? a : b ;
}

int knapSackdynamic(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
      return K[n][W];
}
void sort (Knapsack a[],int n)
{
   int i,j;
   Knapsack t;
   for(i=0;i<n;i++)
      a[i].ppw=a[i].val/a[i].wt;
   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
           if (a[j].ppw<a[j+1].ppw)
           {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
           }
       }
   }
}

void print (Knapsack a[],int n)
{
    int i;
    printf("            Value:-    ");
    for(i=0;i<n;i++)
        printf("%4.3f   ",a[i].val);
    printf (" \n");
    printf("           Weight:-    ");
    for(i=0;i<n;i++)
        printf("%4.3f  ",a[i].wt);
    printf (" \n");
    printf("Profit per weight:-    ");
    for(i=0;i<n;i++)
        printf("%4.3f       ",a[i].ppw);
    printf (" \n");


}
float fractional (Knapsack a[],int n,float r)
{
    int i;
    float cost;
    for (i=0;i<n;i++)
    {
        if (r>=a[i].wt){
           cost=cost+a[i].val;
           r=r-a[i].wt;
        }
        else
        {
            cost=cost+ ((r/a[i].wt)*a[i].val);
            return cost;

        }
    }
}

void main()
{

   int n=3,ch,i;
   int total =20;
   float cost;
   int result;
   Knapsack a[n];
       a[0].wt=18.0;
       a[0].val=25.0;
       a[1].wt=15.0;
       a[1].val=24.0;
       a[2].wt=10.0;
       a[2].val=15.0;
       int val[] = {25, 24, 15};
    int wt[] = {18, 15, 10};
    printf("Max weight of the Knapsack= %d\n\n\n",total);

    do{
    printf ("\n1.FRACTIONAL KNAPSACK PROBLEM \n2.0/1 KNAPSACK PROBLEM\n0.EXIT\n\nEnter the choice \n\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:  sort (a,n);
                 print(a,n);
                 cost=fractional(a,n,total);
                 printf("\n\nMaximum profit as per fractional knapsack using Greedy Algo will be = %4.3f\n\n\n",cost);
                 break;
        case 2:
                  printf("            Value:-    ");
                   for(i=0;i<n;i++)
                     printf("%4d",val[i]);
                    printf (" \n");
                    printf("           Weight:-    ");
                    for(i=0;i<n;i++)
                       printf("%4d",wt[i]);
                    printf (" \n");
                    result =knapSackdynamic(total,wt,val,n);
                  printf("\n\nMaximum profit as per 0 / 1 knapsack using Dynamic Programming Approach will be = %d\n\n\n",result);
                  break;
        case 0:  printf("\nPROGRAM ENDED\n\n\n\n");
                  break;
        default:printf("Invalid Choice");


    }
    }while (ch);

}

