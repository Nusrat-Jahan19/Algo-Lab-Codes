#include <bits/stdc++.h>
using namespace std;

int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];
int max(int,int);

void lcs()
{
        m=strlen(x);
        n=strlen(y);
        for(i=0;i<=m;i++)
            c[i][0]=0;
        for(i=0;i<=n;i++)
            c[0][i]=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                {
                 if(x[i-1]==y[j-1])
                 {
                  c[i][j]=c[i-1][j-1]+1;
                  b[i][j]='c';
                  }
                  else if(c[i-1][j]>=c[i][j-1])
                  {
                  c[i][j]=c[i-1][j];
                  b[i][j]='u';
                  }
                  else
                  {
                   c[i][j]=c[i][j-1];
                   b[i][j]='l';
                 }
                }
}

void printlcs(int i,int j)
{
                if(i==0 || j==0)
                                return;
                if(b[i][j]=='c')
                {
                                printlcs(i-1,j-1);
                                cout<<x[i-1];
                }
                else if(b[i][j]=='u')
                                printlcs(i-1,j);
                else
                                printlcs(i,j-1);
}

int lcslength( int m, int n)
{
   if (m == 0 || n == 0)
      return 0;
   if (x[m - 1] == y[n - 1])
      return 1 + lcslength( m - 1, n - 1);
   else
      return max(lcslength( m, n - 1), lcslength( m - 1, n));
}

int max(int a,int b)
{
 if(a>b)
  return(a);
 else
  return(b);
}

int main()
{
    cout<<"\nEnter 1st sequence:";
    cin>>x;
    cout<<"Enter 2nd sequence:";
    cin>>y;
    cout<<"The Longest Common Subsequence is: ";
    lcs();
    printlcs(m,n);
    cout<<"\nThe Length of Longest Common Subsequence is: "
    <<lcslength(m,n);
    return 0;

}
