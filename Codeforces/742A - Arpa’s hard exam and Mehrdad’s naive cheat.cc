#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int a=8,b=1,n;
	bool v[10];
	memset(v,false,sizeof v);
	vector<int> ans;
	while(1)
	{
		b*=a;
		if(v[b%10])
			break;
		v[b%10]=true;
		ans.push_back(b%10);
	}

	cin>>n;
	if(n>0)
		cout<<ans[(n-1)%ans.size()];
	else
		cout<<1<<endl;
	return 0;
}