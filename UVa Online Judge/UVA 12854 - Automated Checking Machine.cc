#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a,b;
	bool cumple;
	while (getline(cin,a))
	{
		getline(cin,b);
		cumple=true;
		for(int i=0;i<a.length();i+=2)
			if(a[i]==b[i])
			{
				cumple=false;
				break;
			}
		cumple?cout<<"Y\n":cout<<"N\n";
	}
	return 0;
}