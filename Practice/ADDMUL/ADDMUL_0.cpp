#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll MOD = 1000000007;

ll m_lazy[400001];
ll s_lazy[400001];
ll tree[400001];
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
		tree[i]=(cst(s,m,2*i+1)+cst(m+1,e,2*i+2))%MOD;
		return tree[i];
}

ll q_sum(ll s,ll e,ll l,ll r,ll i)
{
	ll m;
    if(r<s||l>e||s>e)return 0;
	if(m_lazy[i]!=1||s_lazy[i]!=0)
    {
        tree[i]=((tree[i]*m_lazy[i])%MOD+(e-s+1)*s_lazy[i])%MOD;
        if(s!=e)
        {
            m_lazy[2*i+1]=(m_lazy[2*i+1]*m_lazy[i])%MOD;
            m_lazy[2*i+2]=(m_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]*m_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]+s_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]+s_lazy[i])%MOD;
        }
        m_lazy[i]=1;
        s_lazy[i]=0;
    }

	if(l<=s&&r>=e)return tree[i];
	m=mid(s,e);
	return (q_sum(s,m,l,r,2*i+1)+q_sum(m+1,e,l,r,2*i+2))%MOD;
}

void s_update(ll s,ll e,ll l,ll r,ll i,ll val)
{
	ll m;

	if(s_lazy[i]!=0||m_lazy[i]!=1)
    {
        tree[i]=(tree[i]*m_lazy[i]+(e-s+1)*s_lazy[i])%MOD;
        if(s!=e)
        {
             m_lazy[2*i+1]=(m_lazy[2*i+1]*m_lazy[i])%MOD;
            m_lazy[2*i+2]=(m_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]*m_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]+s_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]+s_lazy[i])%MOD;
        }
        m_lazy[i]=1;
        s_lazy[i]=0;
    }
    if(r<s||l>e||s>e)return;
	if(l<=s&&r>=e)
    {
        tree[i]=(tree[i]+((e-s+1)*val)%MOD)%MOD;
        if(s!=e)
        {
            s_lazy[2*i+1]=(s_lazy[2*i+1]+val)%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]+val)%MOD;
        }
        return;
    }
	m=mid(s,e);
	s_update(s,m,l,r,2*i+1,val);
	s_update(m+1,e,l,r,2*i+2,val);
	tree[i]=(tree[2*i+1]+tree[2*i+2])%MOD;
}

void m_update(ll s,ll e,ll l,ll r,ll i,ll val)
{
	ll m;
    if(m_lazy[i]!=1||s_lazy[i]!=0)
    {
        tree[i]=(tree[i]*m_lazy[i]+(e-s+1)*s_lazy[i])%MOD;
        if(s!=e)
        {
            m_lazy[2*i+1]=(m_lazy[2*i+1]*m_lazy[i])%MOD;
            m_lazy[2*i+2]=(m_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]*m_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]+s_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]+s_lazy[i])%MOD;
        }
        m_lazy[i]=1;
        s_lazy[i]=0;
    }
    if(r<s||l>e||s>e)return;
	if(l<=s&&r>=e)
    {
       tree[i]=(tree[i]*val)%MOD;
        if(s!=e)
        {
            m_lazy[2*i+1]=(m_lazy[2*i+1]*val)%MOD;
            m_lazy[2*i+2]=(m_lazy[2*i+2]*val)%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]*val)%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]*val)%MOD;
        }
        return;
    }
	m=mid(s,e);
	m_update(s,m,l,r,2*i+1,val);
	m_update(m+1,e,l,r,2*i+2,val);
	tree[i]=(tree[2*i+1]+tree[2*i+2])%MOD;
}

void r_update(ll s,ll e,ll l,ll r,ll i,ll val)
{
	ll m;
    if(m_lazy[i]!=1||s_lazy[i]!=0)
    {
        tree[i]=(((tree[i]*m_lazy[i])%MOD)+(e-s+1)*s_lazy[i])%MOD;
        if(s!=e)
        {
            m_lazy[2*i+1]=(m_lazy[2*i+1]*m_lazy[i])%MOD;
            m_lazy[2*i+2]=(m_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]*m_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]*m_lazy[i])%MOD;
            s_lazy[2*i+1]=(s_lazy[2*i+1]+s_lazy[i])%MOD;
            s_lazy[2*i+2]=(s_lazy[2*i+2]+s_lazy[i])%MOD;
        }
        m_lazy[i]=1;
        s_lazy[i]=0;
    }
    if(r<s||l>e||s>e)return;
	if(l<=s&&r>=e)
    {
       tree[i]=((e-s+1)*val)%MOD;
        if(s!=e)
        {
            m_lazy[2*i+1]=m_lazy[2*i+2]=0;
            s_lazy[2*i+1]=s_lazy[2*i+2]=(val%MOD);
        }
        return;
    }
	m=mid(s,e);
	r_update(s,m,l,r,2*i+1,val);
	r_update(m+1,e,l,r,2*i+2,val);
	tree[i]=(tree[2*i+1]+tree[2*i+2])%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
	ll t,n,q,i,c,x,y,v;

        memset(a,0,sizeof(a));
        memset(tree,0,sizeof(tree));
        memset(s_lazy,0,sizeof(s_lazy));
        for(i=0;i<400001;i++)m_lazy[i]=1;
        cin>>n>>q;
        for(i=0;i<n;i++)cin>>a[i];
        cst(0,n-1,0);
        while(q--)
        {
            cin>>c;
            if(c==1)
            {
                cin>>x>>y>>v;
                s_update(0,n-1,x-1,y-1,0,v);
            }
            else if(c==2)
            {
                cin>>x>>y>>v;
                m_update(0,n-1,x-1,y-1,0,v);
            }
            else if(c==3)
            {
                cin>>x>>y>>v;
                r_update(0,n-1,x-1,y-1,0,v);
            }
            else
            {
                cin>>x>>y;
                cout<<q_sum(0,n-1,x-1,y-1,0)<<endl;
            }
        }



	return 0;
}


