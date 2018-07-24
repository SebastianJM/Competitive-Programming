#include <iostream>
#include <string>
using namespace std;

int main()
{
	string st,aux;
	int n,can;
	cin>>st;
	cin>>n;
	if(st.length()%n==0)
		can=st.length()/n;
	else
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		aux=string(st.begin()+can*i,st.begin()+can*(i+1));
		if(aux==string(aux.rbegin(),aux.rend()))
			continue;
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}