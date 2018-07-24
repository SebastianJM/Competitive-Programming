#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,a,pri=1;
	string car;
	cin>>t;
	while(t--)
	{
		if(!pri)
			cout<<endl;
		pri=0;
		cin>>n;
		vector<vector<int>> precio;
		map<int,string> carros;
		for(int i=0;i<n;i++)
		{
			precio.push_back(vector<int>(3));
			cin>>car;
			carros[i]=car;
			cin>>precio[i][0]>>precio[i][1];
			precio[i][2]=i;
		}
		sort(precio.begin(),precio.end());
		cin>>n;
		int sum=0;
		string res;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			sum=0;
			for(int e=0;e<precio.size() && precio[e][0]<=a && sum<=1;e++)
				if(precio[e][1]>=a)
				{
					sum++;
					res=carros[precio[e][2]];
				}
			cout<<(sum==1?res:"UNDETERMINED")<<endl;
		}
		
	}

	return 0;
}