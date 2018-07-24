#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	vector<int> vec1=vector<int>(t);
	vector<int> vec2=vector<int>(t);
	for(int i=0;i<t;i++)
		scanf("%d %d",&vec1[i],&vec2[i]);
	int max=0;
	int it=0;
	for(int i=0;i<t;i++)
	{
		it=it-vec1[i] + vec2[i];
		if(it > max)
			max=it;
	}
	printf("%d",max);
	return 0;
}