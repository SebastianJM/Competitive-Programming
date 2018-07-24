#include <bits/stdc++.h>

using namespace std;

vector<int> base(int b,int n)
{
	vector<int> rr;
	while(n)
	{
		rr.push_back(n%b);
		n/=b;
	}
	reverse(rr.begin(),rr.end());
	return rr;
}
vector<int> calculo(int base,vector<int> a,vector<int> b)
{
	vector<int> res;
	int ia=a.size()-1,ib=b.size()-1;
	while(ia>=0 || ib>=0)
	{
		if(ia<0)
			res.push_back(b[ib--]);
		else if(ib<0)
			res.push_back(a[ia--]);
		else
			res.push_back((a[ia--]+b[ib--])%base);
	}
	reverse(res.begin(),res.end());
	return res;
}
long long decimal(int base,vector<int> vec)
{
	int res=0,it=1;
	for(int i=vec.size()-1;i>=0;i--)
	{
		res+=vec[i]*it;
		it*=base;
	}
	return res;
}
int main()
{
	int t,a,b,n1,n2;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n1>>n2;
		vector<int> v1(base(b,n1)),v2(base(b,n2));
		cout<<a<<" "<<decimal(b,calculo(b,v1,v2))<<endl;
	}
	return 0;
}