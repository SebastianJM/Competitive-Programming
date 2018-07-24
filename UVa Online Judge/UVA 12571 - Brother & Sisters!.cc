#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,q,a,i,e;
	vector<int> ns,uso;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		ns=vector<int>(n);
		uso=vector<int>(233,-1);
		for(i=0;i<n;i++)
			cin>>ns[i];
		for(i=0;i<q;i++)
		{
			cin>>a;
			if(uso[a]==-1)
			{
				int maxi=-1;
				for(e=0;e<n;e++)
					maxi=max(maxi,a & ns[e]);
				uso[a]=maxi;
				cout<<maxi<<"\n";
			}
			else
				cout<<uso[a]<<"\n";
		}
	}
	return 0;
}