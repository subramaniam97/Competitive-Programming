#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

ll MOD = 1000000007;

ll raise(ll b, ll exp)
{
    ll r=1;
    while(exp)
    {
        if(exp&1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        exp>>=1;
    }
    return r;
}

double sq_dist(int x1,int y1,int x2,int y2)
{
    return (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    int type,t,x1,y1,x2,y2,x3,y3;
    cin>>type;
    cin>>t;
    while(t--)
    {
        int d1,d2,d3;
        bool sca=0,iso=0;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        d1 = sq_dist(x1,y1,x2,y2);
        d2 = sq_dist(x1,y1,x3,y3);
        d3 = sq_dist(x3,y3,x2,y2);
        if(d1==d2||d1==d3||d2==d3)
        {
            iso = 1;
        }
        else
        {
            sca = 1;
        }
    if(type==1)
    {
        (sca==1)?cout<<"Scalene triangle\n":cout<<"Isosceles triangle\n";
    }
    else
    {
            if((d1+d2<d3)||(d1+d3<d2)||(d2+d3<d1))
            {
                (sca==1)?cout<<"Scalene obtuse triangle\n":cout<<"Isosceles obtuse triangle\n";
            }
            else if(d1+d2==d3||d1+d3==d2||d2+d3==d1)
            {
                (sca==1)?cout<<"Scalene right triangle\n":cout<<"Isosceles right triangle\n";
            }
            else
            {
                (sca==1)?cout<<"Scalene acute triangle\n":cout<<"Isosceles acute triangle\n";
            }
        }
    }
    return 0;
}


// ^_^ \\
