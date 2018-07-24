#include <iostream>
using namespace std;

int main() 
{
	int p1,p2,p3;
	for(int i=2;i<=200;i++)
	{
		p1=i*i*i;
		for(int a1=2;a1<i-2;a1++)
		{
			p2=a1*a1*a1;
			for(int a2=a1+1;a2<i-1;a2++)
			{
				p3=a2*a2*a2;
				for(int a3=a2+1;a3<i;a3++)
					if(p1==p2+p3+a3*a3*a3)
						cout<<"Cube = "<<i<<", Triple = ("<<a1<<","<<a2<<","<<a3<<")"<<endl;
			}
		}
	}
	return 0;
}