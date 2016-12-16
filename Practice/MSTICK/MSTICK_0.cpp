#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll MOD = 1000000007;
 
ll tree[400001];
ll tree1[400001];
ll a[100001];
 
ll mid(ll a,ll b)
{
	return (a+(b-a)/2);
}
 
ll cst(ll s,ll e,ll i)
{
		int m;
		if(s==e)
		{
			tree[i]=a[s];
			return a[s];
		}
		m=mid(s,e);
		tree[i]=min(cst(s,m,2*i+1),cst(m+1,e,2*i+2));
		return tree[i];
}
ll cst1(ll s,ll e,ll i)
{
		ll m;
		if(s==e)
		{
			tree1[i]=a[s];
			return a[s];
		}
		m=mid(s,e);
		tree1[i]=max(cst1(s,m,2*i+1),cst1(m+1,e,2*i+2));
		return tree1[i];
}
 
ll q_min(ll s,ll e,ll l,ll r,ll i)
{
	ll m;
    if(r<s||l>e||s>e)return INT_MAX;
 
	if(l<=s&&r>=e)return tree[i];
	m=mid(s,e);
	return min(q_min(s,m,l,r,2*i+1),q_min(m+1,e,l,r,2*i+2));
}
ll q_max(ll s,ll e,ll l,ll r,ll i)
{
	ll m;
    if(r<s||l>e||s>e)return 0;
 
	if(l<=s&&r>=e)return tree1[i];
	m=mid(s,e);
	return max(q_max(s,m,l,r,2*i+1),q_max(m+1,e,l,r,2*i+2));
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
	ll t,n,q,i,x,y,m1,m2,m3;
	double r,c;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
        cin>>q;
        cst(0,n-1,0);
        cst1(0,n-1,0);
        while(q--)
        {
            m3=0;
            cin>>x>>y;
            m1=q_min(0,n-1,x,y,0);
            m2=q_max(0,n-1,x,y,0);
            if(x!=0)
            m3=q_max(0,n-1,0,x-1,0);
            if(y!=n-1)
            m3=max(m3,q_max(0,n-1,y+1,n-1,0));
            r=m1;
            m2=m2-m1;
            if(m2&1)
            {
                m2>>=1;
                c=m2;
                c+=0.5;
            }
            else
            {
                m2>>=1;
                c=m2;
            }
            r+=max(c,(double)m3);
        
            printf("%.1f\n",r);
        }
 
 
 
	return 0;
}