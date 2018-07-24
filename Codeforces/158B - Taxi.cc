#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction (int i,int j) 
{ 
	return (i>j); 
}

int main()
{
	int t;
	scanf("%d",&t);
	
	vector<int> vec = vector<int>(t);
	
	for (int e = 0; e < t; e++)
		scanf("%d", &vec[e]);

	std::sort(vec.begin(),vec.end(),myfunction);
	
	int i=0;
	int it=t-1;
	for (i = 0; i < t;)
	{
		if(vec[i]==4)
		{
			i++;
			continue;
		}
		else if(vec[i]+vec[it]<=4 && i!=it)
		{
			vec[i]+=vec[it];
			vec[it]-=vec[it];
			it--;
		}
		else if(i>=it)		
			break;
		
		else
			i++;
	}
	printf("%d",t-std::count(vec.begin(),vec.end(),0));

	return 0;
}