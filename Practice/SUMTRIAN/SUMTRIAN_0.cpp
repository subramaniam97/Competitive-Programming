#include<iostream>
using namespace std;
int main()
{
int i,t,n,j,a[100][100];
cin>>t;
while(t--)
{
for(i=0;i<100;i++)
{
for(j=0;j<100;j++)
{ a[i][j]=0; }
}

cin>>n;
for(i=0;i<n;i++)
   {
        for(j=0;j<=i;j++) { cin>>a[i][j];   }
    }
for(i=n-2;i>=0;i--) 
     {
	for(j=0;j<=i;j++)
	   {
	   	if(a[i+1][j]>a[i+1][j+1])a[i][j]+=a[i+1][j];
	   	else a[i][j]+=a[i+1][j+1];
	   }
     }
     cout<<a[0][0]<<endl;
}
return 0;
}