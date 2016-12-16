#include<bits/stdc++.h>
using namespace std;

int n,k;
int p[5000001],s[5000001],a[5000001];

bool success(int x)
{
	int l,r,i,j;
	for(i=1;i<=n;i+=x)
	{
		l=i;
		r=min(n,i+x-1);
		p[l]=a[l];
		s[r]=a[r];
		for(j=l;j<r;j++)
		{
			p[j+1]=__gcd(a[j+1],p[j]);
			s[r+l-j-1]=__gcd(a[r+l-j-1],s[r+l-j]);
		}
	}
	for(i=1;i+x-1<=n;i++)
	{
		if(__gcd(s[i],p[i+x-1])>=k)return 1;
	}
	return 0;
}

int solve()
{
    int l,r,m;
    l=1;
    r=n+1;
    while(l<r)
    {
    	m = (l+r)/2;
    	if(success(m))l=m+1;
    	else r=m;
    }
    return l-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i;
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    cout<<solve()<<endl;
    return 0;
}


// ^_^ \\
