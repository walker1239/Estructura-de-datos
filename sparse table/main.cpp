#include <iostream>
#include <math.h>
using namespace std;

int a[100];
int n;
int sparse[100][100];
//func
void matrix()
{
 int i,j;
 int c=2;
 int l=c-1;
 for(i=0;i<n;i++){
    sparse[i][0]=i;
 }
 for(j=1;c<=n;j++)
    {
      l=c-1;
     for(i=0;l<n;i++)
        {
          if(a[ sparse[i][j-1] ]<a[ sparse[i+(1<<(j-1))][j-1] ])
              sparse[i][j]=sparse[i][j-1];
          else
              sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        l++;
        }
    c=c*2;
    }
}
int query(int l,int r)
{
 int len=r-l+1;
 int k=log2(len);
 return min(a[sparse[l][k]],a[sparse[l+len-(1<<k)][k]]);
}
//main

int main()
{
 cin>>n;
 for(int i=0;i<n;i++)
    cin>>a[i];
 matrix();
 cout<<query(0,5)<<endl;
 cout<<query(10,13)<<endl;
  return 0;    
}
