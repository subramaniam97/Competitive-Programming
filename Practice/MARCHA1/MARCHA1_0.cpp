#include<iostream>
#include<algorithm>
using namespace std;
int a[20],p=0,q=0;
void fun(int m,int n)
{
	int i,j,k,d,s=0,e;
	i=0;
	while(a[i]<=m&&i<n)
	{		
		i++;
	}
	i--;
	c:
	for(e=0;e<=i;e++)s+=a[e];
	if(s<m)i=-1;
	if(i<0)
	{
	    if(p==0)cout<<"No"<<endl;
		return;
	}
	for(j=i;j>=0;j--)
	{
		if(a[j]==m)
		{
			cout<<"Yes"<<endl;
			q=1;
			return;
		}	
		else
		{
			d=m-a[j];
			if(s<m)goto a;
			p++;
			fun(d,j);
			p--;
			if(p!=0&&j!=0&&q!=1){i--;goto c;}
			a:
			if(q==1)break;
			if(p!=0)return;
		}
	}
	if(p==0&&j<0)cout<<"No"<<endl;
}
int main()
{
	int t,m,i,n;
	cin>>t;
	while(t--)
	{
	    p=0;
	    q=0;
		cin>>n>>m;
		for(i=0;i<n;i++)cin>>a[i];
		stable_sort(a,a+n);
		fun(m,n);
	}
	return 0;
} 