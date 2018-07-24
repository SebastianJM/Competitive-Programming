#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int n,a,is,band(1);
	string s,ingles;
	cin>>n;
	while(n--)
	{
		
		cin>>a;
		is=a;
		vector<string> vs;
		ingles="-";
		band=1;
		for(int i=0;i<a;i++)
		{
			cin>>s;
			if(band)
			{
				
				if(s[0]!='#')
				{
					is=i;
					band=0;
					ingles=s;
				}
				else
					vs.push_back(s);

			}
			else
			{
				cout<<s<<" ";			
			}
		}
		if(ingles!="-")
			cout<<ingles<<" ";
		for(int i=0;i<vs.size();i++)
			cout<<vs[i]<<" ";
		
		cout<<endl;
		
	}
	
	return 0;   
}
