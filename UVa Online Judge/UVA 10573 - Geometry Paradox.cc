#include <bits/stdc++.h>
 
using namespace std;
 
#define PI (2*acos(0.0))
 
double area(double r)
{
	return PI*r*r;
}
int main() {
	int n;
	double r1,r2;
	string s;
	stringstream st;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
 
		getline(cin,s);
 
		if(s.find(" ")!=string::npos)
		{
			st.clear();
			st<<s;
			//cout<<s<<endl;
			st>>r1>>r2;
			printf("%.4lf\n",(area((2*r1+2*r2)/2)-area(r1)-area(r2)));
		}
		else
		{
			st.clear();
			st<<s;
			//cout<<s<<endl;
			st>>r1;
			printf("%.4lf\n",area(r1)/8);
		}
 
	}
	return 0;
}