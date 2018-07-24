#include <iostream>

using namespace std;

int main()
{
	int t,a;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=0;
		while(1<<a < n)
			a++;
		n=1<<(a-1);
		cout<<n<<endl;
	}

	return 0;
}