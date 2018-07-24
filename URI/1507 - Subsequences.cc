#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int t,q,con;
	string s,aux;
	cin>>t;

	while(t--)
	{
		cin>>s;
		cin>>q;
		string::iterator it,it2;
		for(int i=0;i<q;i++)
		{
			cin>>aux;
			it2=s.begin();
			con=1;
			for(int e=0;e<aux.size();e++)
			{
				it=std::find(it2,s.end(),aux[e]);
				
				if(it==s.end())
				{
					cout<<"No"<<endl;
					con=0;
					break;
				}
				it2=it+1;
			}
			if(con==1)
				cout<<"Yes"<<endl;				
		}
		
	}
	return 0;
}
