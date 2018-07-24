#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> pi;
typedef vector<pi> vpi;
int main() 
{
	freopen("buffcraft.in","r",stdin);
	freopen("buffcraft.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,c,p,z;
	long long ca,cb,sa,sb,c_ans;
	double s_ans;
	vpi a,b;
	cin>>n>>k>>c>>p;
	for(int i=0;i<c;i++){
		cin>>z;
		a.push_back(make_pair(z,i+1));
	}
	for(int i=0;i<p;i++){
		cin>>z;
		b.push_back(make_pair(z,i+1));
	}
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	ca=sa=0;
	for(int i=0;i<c && i<k;i++)
	{
		ca++;
		sa+=a[i].first;
	}
	cb=sb=0;
	for(int i=0;i<p && i<k-ca;i++)
	{
		cb++;
		sb+=b[i].first;
	}
	c_ans=ca;
	s_ans=((double)n+(double)sa)*(100.0+(double)sb)/100.0;
	int t=ca;
	for(int i=1;i<=t;i++)
	{
		sa-=a[ca-i].first;
		
		if(cb+i-1<p)
			sb+=b[cb+i-1].first;
		else 
			break;
		if(s_ans<((double)n+(double)sa)*(100.0+(double)sb)/100.0)
		{
			s_ans=((double)n+(double)sa)*(100.0+(double)sb)/100.0;
			c_ans=ca-i;
		}
	}
	if(k>c+p)
		k=c+p;
	cout<<c_ans<<" "<<k-c_ans<<"\n";
	for(int i=0;i<c_ans;i++)
		cout<<(i>0?" ":"")<<a[i].second;
	cout<<"\n";
	for(int i=0;i<k-c_ans;i++)
		cout<<(i>0?" ":"")<<b[i].second;
	return 0;
}