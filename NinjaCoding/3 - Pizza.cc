#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

void llenar()
{
	vec[0]=0;
	vec[1]=1;
	vec[2]=2;
	for(int i=3;i<=2000;i++)
		vec[i]=vec[i-1]+2;
}
int main()
{ 
	int t;
	vec=vector<int>(2001);
	llenar();
	while(true)
	{
		cin>>t;
		if(t==-1)
			return 0;
		cout<<vec[t/5]<<endl;
	}
    return 0;
}


