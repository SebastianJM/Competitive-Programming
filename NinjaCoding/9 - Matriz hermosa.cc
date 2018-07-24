#include <iostream>

using namespace std;

int main()
{ 
	int c,f,t,matriz[5][5];
	cin>>t;
	while(t--)
	{
		for(int i=0;i<5;i++)
			for(int e=0;e<5;e++)
			{
				cin>>matriz[i][e];
				if(matriz[i][e]==1)
				{
					c=i;
					f=e;
				}
			}
			c>2?c-=2:c=2-c;
			f>2?f-=2:f=2-f;
			cout<<c+f<<endl;
	}
    return 0;
}
