#include <iostream>
using namespace std;
 
int main() 
{
	int n,r1,r2,it;
	while(1)
	{
		cin>>n;
		if(!n)
			return 0;
		r1=r2=0,it=1;
		for(int i=0;i<32;i++)
			if(n & (1<<i))
			{
				if(it>0)
					r1|=(1<<i);
				else
					r2|=(1<<i);
				it*=-1;
			}
		cout<<r1<<" "<<r2<<endl;
	}
	return 0;
}