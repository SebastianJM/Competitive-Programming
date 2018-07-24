#include <bits/stdc++.h>
#include <ext/rope>        // header for rope
using namespace std;
using namespace __gnu_cxx; // namespace for rope

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	rope<char> v,cur; // v: Cuerda    
	string s,c,z;     // s: Cadena a leer
	int p,t,k,l;
	cin>>t;
	while (t--) 
	{
		cin >> s;
		v.clear();  // Limpiar cuerda
		for (int i = 0; i < (int)s.size(); i++)
			v.push_back(s[i]); // Insertar letras a la cuerda
		while(1)
		{
			cin >> c;
			if(c[0]=='E')
				break;
			if(c[0]=='I')
			{
				cin>>z>>p;
				cur.clear();
				for(int i=0;i<z.size();i++)
					cur.push_back(z[i]);
				v.insert(v.mutable_begin() + p, cur);    // Insertar substring
			}
			else
			{
				//cout<<"UDAJ"<<endl;
				cin>>k>>l;
				l-=k;
				for(rope<char>::iterator it=v.mutable_begin()+k; it!=v.mutable_end() && l>=0; l--,it++)
					cout <<*it;  // Imprime string
				cout << '\n';
			}
		}
	
	}
	return 0;
}