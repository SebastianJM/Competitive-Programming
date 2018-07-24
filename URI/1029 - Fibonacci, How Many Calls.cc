#include <iostream>
using namespace std;

int rec[40];
int fibo[40];

int main() 
{
	fibo[0]=rec[0]=rec[1]=0;
	fibo[1]=1;
	for(int i=2;i<40;i++)
		rec[i]=(rec[i-1]+rec[i-2]+2),fibo[i]=(fibo[i-1]+fibo[i-2]);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<"fib("<<n<<") = "<<rec[n]<<" calls = "<<fibo[n]<<endl;
	}
	return 0;
}