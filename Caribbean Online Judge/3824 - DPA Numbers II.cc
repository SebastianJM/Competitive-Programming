#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sieve_size; // Tamaño de la criba
bitset<1000010> bs; // 10^7 + espacio extra
vector<ll> primes; // Lista de números primos
void sieve(ll n) // n: Tamaño de la criba
{
sieve_size = n; // Guardar el tamaño de la criba
 bs.set(); // Marcar todos los números como primos..
 bs[0] = bs[1] = 0; // Excepto el 0 y 1
for(ll i = 2; i <= n; i++) // Para cada número..
 if(bs[i]) // Si está marcado como primo..
 {
 for(ll j = i * i; j <= n; j += i) // Para c/uno de sus múltiplos..
 bs[j] = 0; // Marcarlo como no primo
 primes.push_back(i); // Agregarlo a la lista de números primos
 }
} 
vector<ll> primeFactors(ll N)
{
 vector<ll> factors; // Lista de factores primos
 ll idx = 0, PF = primes[idx];
 while(N != 1 && PF * PF <= N) // Probar todos los primos <= sqrt(N)
 {
 while(N % PF == 0) { N /= PF; factors.push_back(PF); }
 PF = primes[++idx]; // Siguiente primo
 }
 if(N != 1) factors.push_back(N);
 return factors;
} 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    vector<ll> primos;
    map<ll,int> mp;
    ll n,con,ans;
    cin>>t;
    sieve(1000004);
    while(t--)
    {
        cin>>n;
        mp.clear();
        primos=primeFactors(n);
        for(int i=0;i<primos.size();i++)
            mp[primos[i]]++;
        ans=1LL;
        for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            con=1LL;
            for(int i=1;i<=(*it).second;i++)
                con+=pow((*it).first,i);
            ans*=con;
        }
        ans-=n;
        if(ans<n)
            cout<<"deficient\n";
        else if(ans==n)
            cout<<"perfect\n";
        else
            cout<<"abundant\n";
    }
	return 0;
}