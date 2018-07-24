#include <iostream>

using namespace std;

int main()
{
	int n,aux,par,impar,pp(0),pi(0);
	par=impar=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>aux;		
		if(aux%2)
		{
			impar++;
			pi=i+1;
		}
		else
		{
			par++;
			pp=i+1;
		}
		
	}
	if(par>=2)			
		cout<<pi;						
	
	else if(impar>=2)
		cout<<pp;

	
	return 0;
}
