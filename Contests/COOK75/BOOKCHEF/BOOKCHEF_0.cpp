#include<bits/stdc++.h>
using namespace std;

int a[100005], z[100005];
int n, m;

vector<pair<int, string> > p;
vector<pair<int, string> > q;

int main()
{
    int x, y;
    string s;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        z[a[i]]=1;
    }

    while(m--)
    {
        cin>>x>>y>>s;
        if(z[x] == 1)
            p.push_back(make_pair(y, s));
		else
            q.push_back(make_pair(y, s));
	}

	sort(p.begin(),p.end());
	sort(q.begin(),q.end());
	reverse(p.begin(),p.end());
	reverse(q.begin(),q.end());

	for(int i = 0; i < p.size(); i++)
        cout<<p[i].second<<endl;

	for(int i = 0; i < q.size(); i++)
        cout<<q[i].second<<endl;

    return 0;
}
