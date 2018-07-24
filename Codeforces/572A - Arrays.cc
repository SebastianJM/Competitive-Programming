#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a,b,n,m;
	cin>>a>>b;
	vector<int> va(a);
	vector<int> vb(b);
	cin>>n>>m;
	for(int i=0;i<a;i++)
		cin>>va[i];
	for(int i=0;i<b;i++)
		cin>>vb[i];
	if(va[n-1]<vb[b-m])
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}