#include<iostream>
#include<vector>
#include<cstdio>
#define getx getchar
#define pc putchar
using namespace std;

inline void out(int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
    }
    
inline void inp(int &n)
{
	n=0;
	char ch=getx();
	int sign=1;
	while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getx();}
	while(ch>='0'&&ch<='9')
	{
		n=(n<<3)+(n<<1)+ch-'0';
		ch=getx();
	}
	n=n*sign;
}
 
void merge(vector<int> &a,int l,int m,int r)
{
	int i=l,j=m+1;
	vector<int> s;
	while(i<=m&&j<=r)
	{
		if(a[i]<a[j])
		{
			s.push_back(a[i]);
			i++;
		}
		else
		{
			s.push_back(a[j]);
			j++;
		}
	}
	if(i==m+1)
	{
		while(j<=r)
		{
			s.push_back(a[j]);
			j++;
		}
	}
	else
	{
		while(i<=m)
		{
			s.push_back(a[i]);
			i++;
		}
	}
	for(i=l;i<=r;i++)a[i]=s[i-l];
}
 
void mergesort(vector<int> &a,int l,int r)
{
	if(l>=r)return;
	int m;
	m=(l+r)/2;
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	merge(a,l,m,r);
}
 
 
int main()
{
	vector<int> a;
	int i,t,e;
	inp(t);
	while(t--)
	{
		inp(i);
		a.push_back(i);
	}
	e=a.size()-1;
	mergesort(a,0,e);
	for(i=0;i<=e;i++)out(a[i]);
	return 0;
} 
