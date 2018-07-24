#include <bits/stdc++.h>

using namespace std;

int main() 
{
	vector<pair<float,float> > pos;
	int n,t,c=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		pos=vector<pair<float,float> >(n,pair<float,float>(0.0,0.0));
		for(int i=0;i<n;i++)
			cin>>pos[i].first>>pos[i].second;
		sort(pos.begin(),pos.end());
		float maxi=0.0;
		for(int i=1;i<n;i++)
			maxi=max(maxi,(abs(pos[i].second-pos[i-1].second))/(abs(pos[i].first-pos[i-1].first)));
		cout<<"Case #"<<c++<<": ";
		printf("%.2f\n",maxi);
		
	}
	return 0;
}