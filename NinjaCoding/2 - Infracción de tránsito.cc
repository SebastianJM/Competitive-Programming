#include <iostream>
using namespace std;

int main()
{
    int m,v;
	while(true)
	{
		cin>>m>>v;
		if(m==0 && v==0)
			return 0;
		cout<<v-m<<endl;
	}
    return 0;
}