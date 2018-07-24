#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int num,max,total=0;
	scanf("%d %d",&num,&max);
	vector<int> vec=vector<int>(num);
	for(int i=0;i<num;i++)
		scanf("%d",&vec[i]);
	for(int i=0;i<max;i++)
	{
		if(vec[i]>0)
			total++;
		else
			break;
		if(i==max-1)
		{
			int aux=vec[i];
			i++;
			while(i<num)
			{
				
				if(vec[i]==aux)
					total++;
				else
					break;
				i++;
			}
		}
	}
	printf("%d",total);
    return 0;
}