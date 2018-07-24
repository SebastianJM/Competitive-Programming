#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<pair<string,int>> psi;

int main()
{
    int n;
	string s;
	psi vec;
	pair<string,int> aux;
	vec.clear();
	cin>>n;
	cin>>s;
	aux.first=s;
	aux.second=1;
	vec.push_back(aux);
	for(int i=1;i<n;i++)
	{
		cin>>s;
		for(int e=0;e<vec.size();e++)
		{
			if(vec[e].first==s)
			{
				vec[e].second++;
				break;
			}
			else if(e==vec.size()-1)
			{
				aux.first=s;
				aux.second=1;
				vec.push_back(aux);
				break;
			}
		}
	}
	int res(0);
	for(int i=0;i<vec.size();i++)
		if(vec[i].second>res)
			res=vec[i].second;
	cout<<res;
    return 0;
}