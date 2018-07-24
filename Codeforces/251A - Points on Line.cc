#include <bits/stdc++.h>

using namespace std;

long long combinatoria(long long a,long long b)
{
	return a*(a-1)/2;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,d;
	cin>>n>>d;
	vector<long long> vec=vector<long long>(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	long long r=0;
	int a,s;

	for(int i=0;i<n-2;)
	{
		a=vec[i]+d;
		s=(upper_bound(vec.begin(),vec.end(),a)-vec.begin());
			//cout<<s<<endl;
		if(vec[s-1]>a)
			s--;
		
		if(s-1-i>=2)

			r+=combinatoria(s-1-i,2);
		i++;
			
	}
	cout<<r;
	return 0;
}