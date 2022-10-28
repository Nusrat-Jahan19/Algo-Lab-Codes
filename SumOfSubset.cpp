#include <stdio.h>

int count=0,m,w[10],x[10];

void SumofSub(int s,int k,int r)
{
   int i;
   x[k]=1;
   if((s+w[k])==m)
    {
       printf("Solution of Subset : %d\n",++count);
       for(i=0;i<=k;i++)
       {
         if(x[i]==1)
         printf("%d\n",w[i]);
       }
     }
  else if(s+w[k]+w[k+1]<=m)
       SumofSub(s+w[k],k+1,r-w[k]);
    if((s+r-w[k]>=m)&&(s+w[k+1])<=m)
    {
      x[k]=0;
      SumofSub(s,k+1,r-w[k]);
    }
}

int main()
{
    int sum=0,i,n;
    printf("\nEnter no of elements:");
    scanf("%d",&n);
    printf("Enter the elements in ascending order:::\n");
    for(i=0; i<n; i++)
    scanf("%d",&w[i]);
    printf("Enter the required sum:");
    scanf("%d",&m);
    for(i=0; i<n; i++)
    sum +=w[i];
    if(sum < m)
     {
        printf("No solution exits\n");

     }
    printf("The solution is:::\n");
    SumofSub(0,0,sum);
    return 0;

}

