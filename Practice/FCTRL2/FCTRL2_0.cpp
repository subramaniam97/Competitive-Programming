#include<iostream>
 using namespace std;
 int main()
 {
 int t,i,n,a[160],j,temp,x,k;
 cin>>t;
 for(i=0;i<t;i++)
 {
 temp=0;
 cin>>n;
 x=n;
 for(j=0;j<=158;j++)
 {
 a[j]=x%10;
 x=x/10;  
 }
 for(k=1;k<n;k++)
 {
 for(j=0;j<=158;j++)
 {
 x=((a[j])*k)+temp;
 a[j]=x%10;
 temp=x/10;
 }
 }
for(j=158;j>=0;j--)
{
if(a[j]==0)continue;
else
{
for(j;j>=0;j--)cout<<a[j];
}
break;
}
cout<<endl;
}
 return 0;
 } 
