#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll; 
ll tamano_criba; 
bitset<10467400> bs; 
bool vis[10467400];
vector<ll> primos; 
void criba(ll limite) 
{           
	tamano_criba = limite + 1; 
	bs.set(); 
	bs[0] = bs[1] = 0;           
	for(ll i = 2; i <= tamano_criba; i++)                     
		if(bs[i])                     
		{                               
			for(ll j = i * i; j <= tamano_criba; j += i)                                         
			bs[j] = 0;                               
			primos.push_back(i);                     
		} 
}
vector<ll> factoresPrimos(ll N) 
{           
	vector<ll> factores; 
	ll idx = 0, PF = primos[idx];          
	while(N != 1 && PF * PF <= N) // Probar todos los primos <= sqrt(N)           
	{                     
		while(N % PF == 0)                     
		{                               
			N /= PF;                               
			factores.push_back(PF);                     
		}                     
		PF = primos[++idx]; // Siguiente primo           
	}           
	if(N != 1)                     
		factores.push_back(N);           
	return factores; 
} 
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	ll n;
	cin>>n;
	criba(n+1);
	memset(vis,0,sizeof vis);
	vector<ll> ans=factoresPrimos(n);
	bool cumple=true;
	for(int i=0;i<ans.size();i++)
	{
		if(vis[ans[i]])
		{
			cumple=false;
			break;
		}
		vis[ans[i]]=true;
	}
	if(ans.size()!=3)
		cumple=false;
	if(cumple)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}