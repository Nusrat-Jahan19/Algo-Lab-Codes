
#include<stdio.h>
#include<math.h>

int i,j,k,n,dist[100][100];
int min(int,int);

void floydWarshell ()
{
for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    if(i==j)
     dist[i][j]=0;
    else
     dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
 }

int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}

int main()
{
  printf("\n Enter the number of vertices:");
  scanf("%d",&n);
  printf("\n");
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   {
    printf(" dist[%d][%d]:",i,j);
    scanf("%d",&dist[i][j]);
   }
  printf("\n Matrix of input data::\n");
  for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
      printf("%d \t",dist[i][j]);
        printf("\n");
    }

 floydWarshell();


 printf("\n The shortest path matrix::\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",dist[i][j]);
    printf("\n");
 }

 printf("\n Shortest distances between every pair of vertices\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   if(i!=j)
    printf("\n <%d,%d>=%d",i,j,dist[i][j]);
  }

}

