#include <bits/stdc++.h>

using namespace std;

int main()
{	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a;
	string s;
	map<string,int> cod;
	cin>>n;
	while(n--)
	{
		cin>>a>>s;
		cod["TTT"]=0;
		cod["TTH"]=0;
		cod["THT"]=0;
		cod["THH"]=0;
		cod["HTT"]=0;
		cod["HTH"]=0;
		cod["HHT"]=0;
		cod["HHH"]=0;
		for(int i=0;i<=s.length()-3;i++)
		{
			string t(s.begin()+i,s.begin()+i+3);
			cod[t]++;
		}
		cout<<a<<" "<<cod["TTT"]<<" "<<
		cod["TTH"]<<" "<<
		cod["THT"]<<" "<<
		cod["THH"]<<" "<<
		cod["HTT"]<<" "<<
		cod["HTH"]<<" "<<
		cod["HHT"]<<" "<<
		cod["HHH"]<<endl;
	}

	return 0;
}