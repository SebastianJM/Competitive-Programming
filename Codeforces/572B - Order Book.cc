#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int n,o,a,b;
	char tipo;
	map<int,int> B;
	map<int,int> S;
	map<int,int>::iterator it;
	map<int,int>::reverse_iterator itt;
	cin>>n>>o;
	while(n--)
	{
		cin>>tipo>>a>>b;
		if(tipo=='B')
		{
			if(B.find(a)!=B.end())
				B[a]+=b;
			else if(B.size()<o)
			{
				B[a]=b;
			}
			else
			{
				it=B.begin();
				if(it->first<a)
				{
					B.erase(it);
					B[a]=b;
				}
			}
		}
		else
		{
			if(S.find(a)!=S.end())
				S[a]+=b;
			else if(S.size()<o)
			{
				S[a]=b;
			}
			else
			{
				itt=S.rbegin();
				if(itt->first>a)
				{
					it=S.find(itt->first);
					S.erase(it);
					S[a]=b;
				}
			}
		}
	}
	
	for(itt=S.rbegin();itt!=S.rend();itt++)
		cout<<"S "<<itt->first<<" "<<itt->second<<endl;
	for(itt=B.rbegin();itt!=B.rend();itt++)
		cout<<"B "<<itt->first<<" "<<itt->second<<endl;
	
	return 0;
}