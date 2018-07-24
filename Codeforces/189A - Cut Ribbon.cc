#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> num(3),vec(4005,-1);
	int n;
	cin>>n>>num[0]>>num[1]>>num[2];
	vec[0]=0;
	for(int i=0;i<=n;i++)
		for(int e=0;e<3;e++)
			if(vec[i]>=0 && i+num[e]<=n)
				vec[i+num[e]]=max(vec[i+num[e]],vec[i]+1);
	cout<<vec[n]<<endl;	
}