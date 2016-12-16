#include<iostream>
using namespace std;
int main()
{
int t,n,c,i,s=0,j,a;
cin>>t;
for(i=0;i<t;i++)
{
s=0;
cin>>n>>c;
for(j=0;j<n;j++)
{
cin>>a;
s+=a;
}
if(c>=s)cout<<"Yes"<<endl;
else 
cout<<"No"<<endl;
}
return 0;
}