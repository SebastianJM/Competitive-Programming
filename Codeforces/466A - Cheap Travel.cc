#include <iostream>
#include <algorithm>
using namespace std;

int n,a,b,m,total(0);
int valor(int con)
{
	if(a*m>b)
	{
		if(con==n)
			return total;
		else if(con>n)
			return min(total-b+(n-(con-m))*a,total);
		else
		{
			total+=b;
			return valor(con+m);
		}
	}
	else
		return a*n;
}
int main()
{
	cin>>n>>m>>a>>b;
	cout<<valor(0);
	return 0;   
}




