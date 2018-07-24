#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string a,b,s;
	cin>>a>>b>>s;
	a+=b;
	sort(a.begin(),a.end());
	sort(s.begin(),s.end());
	if(a==s)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
