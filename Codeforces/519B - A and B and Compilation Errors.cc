#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;	
	vector<int> vec1=vector<int>(t);
	vector<int> vec2=vector<int>(t-1);
	vector<int> vec3=vector<int>(t-2);

	for(int i=0;i<t;i++)
		cin>>vec1[i];
	for(int i=0;i<t-1;i++)
		cin>>vec2[i];
	for(int i=0;i<t-2;i++)
		cin>>vec3[i];

	std::sort(vec1.begin(),vec1.end());
	std::sort(vec2.begin(),vec2.end());
	std::sort(vec3.begin(),vec3.end());
	int s=0;
	for(int i=0;i<t-1;i++)
		if(vec1[i]!=vec2[i])
		{
			s=1;
			cout<<vec1[i]<<endl;
			break;
		}
	if(s==0)
		cout<<vec1[t-1]<<endl;
	s=0;
	for(int i=0;i<t-2;i++)
		if(vec2[i]!=vec3[i])
		{
			s=1;
			cout<<vec2[i]<<endl;
			break;
		}
	if(s==0)
		cout<<vec2[t-2]<<endl;
	return 0;
}
