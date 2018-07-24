#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

const int MAX = 1e5; // Número máximo de elementos
int t[MAX * 2+3];      // Segment Tree (raíz -> 1)
int n;               // Número de elementos

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline int gcd(const int a,const int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

inline void build() // Construye el árbol
{
   for(int i = n - 1; i > 0; i--)
      t[i] = t[i << 1] + t[i << 1 | 1];
}

inline void update(int i, int val) // i debe estar en [0, N-1]
{
   for(t[i += n] = val; i >>= 1; )
      t[i] = gcd(t[i << 1] , t[i << 1 | 1]);
}

inline int query() // Query en el rango [l,r]
{
	int res=gcd(t[0],t[1]);
    return res>0?res:1;
}

int main()
{
	use_io_optimizations();
	char c;	
	int aux;
	map<int,int> mp;
	map<int,int> pos;
	map<int,int>::iterator it;
	pair<int,int> pi;

	cin>>n;
	memset(t,0,2*n);
	
	for(int i=n;i<2*n;i++)
	{
		cin>>c;
		cin>>aux;
		if(c=='+')
		{
			it=mp.find(aux);
			if(it==mp.end())
			{
				pi.first=aux;
				pi.second=1;
				mp.insert(pi);
				update(i-n,aux);
				pos[aux]=i;
			}
			else
				it->second++;
		}
		else
		{					
			if(mp[aux]>1)
				mp[aux]--;
			else
			{
				it=mp.find(aux);
				mp.erase(it);
				update(pos[aux]-n,0);
			}

		}
		cout<<query()<<endl;;
	}
	return 0;   
}




