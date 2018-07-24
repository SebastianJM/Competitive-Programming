#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{ 
	int vec[2001];
	int t;
	vector<int> num;
	while(true)
	{
		cin>>t;
		memset(vec,0,sizeof vec);
		if(t==0)
			return 0;
		num=vector<int>(t);
		for(int i=0;i<t;i++)
		{
			cin>>num[i];
			vec[num[i]]++;
		}
		sort(num.begin(),num.end());
		for(int i=1;i<t;i++)
		{
			if(num[i]!=num[i-1])
			{
				
				if(vec[num[i-1]]==1)
					cout<<num[i-1]<<" aparece 1 vez"<<endl;
				else
					cout<<num[i-1]<<" aparece "<<vec[num[i-1]]<<" veces"<<endl;
			}
		}
		if(vec[num[t-1]]==1)
			cout<<num[t-1]<<" aparece 1 vez"<<endl;
		else
			cout<<num[t-1]<<" aparece "<<vec[num[t-1]]<<" veces"<<endl;
	}
    return 0;
}
