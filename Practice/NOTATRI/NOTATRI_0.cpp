#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n=1,i,j,d,s,m;
    vector<int> a;
    vector<int>::iterator p;
    while(n!=0)
    {
        a.clear();
        
        s=0;
        cin>>n;
        if(n==0)break;
        for(i=0;i<n;i++){cin>>m; a.push_back(m);}
        sort(a.begin(),a.end());
        for(i=2;i<n;i++)
        {
            for(j=0;j<i-1;j++)
            {
                d=a[i]-a[j];
                p=lower_bound(a.begin()+j+1,a.begin()+i,d);
                p--;
                s+=(p-(a.begin()+j));
            }
        }
        cout<<s<<endl;
    }
    
	return 0;
}
