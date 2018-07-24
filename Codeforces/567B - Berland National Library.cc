#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	char ir;
	int n,aux;
	cin>>n;
	set<int> ss;
	set<int>::iterator it;
	vector<int> vec;
	cin>>ir;
	cin>>aux;
	if(ir=='-')
		vec.push_back(-1);
	else
		ss.insert(aux);
	for(int i=1;i<n;i++)
	{
		cin>>ir;
		cin>>aux;
		if(ir=='-')
		{
			it=ss.find(aux);
			if(it!=ss.end())
			{
				ss.erase(aux);
				vec.push_back(-1);
			}
			else
				vec.push_back(-1);
		}
		else
		{

			if(!vec.empty())
			{
				ss.insert(aux);
				vec.pop_back();
			}
			else
				ss.insert(aux);
		}
	}
	cout<<ss.size()+vec.size();
	
	return 0;
}


