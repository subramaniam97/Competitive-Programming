#include <iostream>

using namespace std;



int main() {

	// your code goes here

	long long int t,i,n,a[50001],min;

	cin>>t;

	while(t--)

	{

	    cin>>n;

	    for(i=0;i<n;i++)cin>>a[i];

	    min=a[0];

	    for(i=0;i<n;i++)

	    {

	        if(a[i]<min)min=a[i];

	    }

	    min*=(n-1);

	    cout<<min<<endl;
	}
	return 0;

}

