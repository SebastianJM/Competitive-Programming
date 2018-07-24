#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int phi(int n) {
    int result = n;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    if(n > 1)
        result -= result / n;
    return result;
}
int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
int main() 
{
	ll n;
	
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		if(n==1)
			cout<<"0/1\n";
		else
		{
			ll con=0;
			n--;
			int i;
			for(i=1;;i++)
			{
				con+=phi(i);
				if(con>=n)
					break;
			}
			
			con-=phi(i);
			
			//cout<<con<<" "<<i<<endl;
			for(int e=1;e<=i;e++)
				if(gcd(e,i)==1)
				{
	//					cout<<e<<" "<<i<<" "<<con<<endl;
					con++;
					if(con==n)
					{
						cout<<e<<"/"<<i<<"\n";
						break;
					}
				}
		}
	}
	return 0;
}