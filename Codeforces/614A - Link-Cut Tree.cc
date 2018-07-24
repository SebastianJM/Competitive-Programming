#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ull ll_log(ull base, ull x) {
    return (log(x) / log(base));
}
ull expon(ull x,ull k)
{
	ull aux=x;
	x=1;
	for(int i=1;i<k;i++)
		x*=aux;
	return x;
}
int main() 
{
	bool ins=false;
	ull ans,l,r,k,log_base;
	cin>>l>>r>>k;
	log_base=ll_log(k,l);
	if(expon(k,log_base)<l)
		log_base++;
	ans=expon(k,log_base);
	if(ans>=l && ans<=r)
	{
		cout<<ans;
		ins=true;
	}
	for(;ans<=ULLONG_MAX/k;)
	{
		ans*=k;
		if(ins)
			cout<<" ";
		if(ans>=l && ans<=r)
			cout<<ans;
		else
			break;
		ins=true;
	}
	if(!ins)
		cout<<-1;
	cout<<endl;
	return 0;
}