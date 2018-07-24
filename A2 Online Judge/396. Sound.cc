#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

int vec[100002];
void valores(int n)
{
	vec[1]=0;
	for(int i=2;i<=n;i++)
		vec[i]=vec[i-1]+i-1;
}

int main()
{
	map<string,int> m;
	map<string,int>::iterator it;
	pair<string,int> psi;
	int n;
	string s;
	cin>>n;
	valores(n+1);
	while(n--)
	{
		cin>>s;
		string aux("-");
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>=65&&s[i]<=90)
				aux.push_back(i);
		}
		it=m.find(aux);
		if(it==m.end())
		{
			psi.first=aux;
			psi.second=1;
			m.insert(psi);
		}
		else
		{
			it->second++;
		}
	}
	n=0;
	for(it=m.begin();it!=m.end();it++)
		n+=vec[it->second];
	cout<<n;

	return 0;   
}
