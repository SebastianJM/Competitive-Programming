#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%4==0 || n%7==0 || n%47==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    
	int aux;
	while(n>0)
	{
		aux=n%10;
		if(aux!=4 && aux!=7)
		{
			cout<<"NO";
			return 0;
		}
		n/=10;
	}
    cout<<"YES"<<endl;
    return 0;
}