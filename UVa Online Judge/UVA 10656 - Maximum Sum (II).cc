#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<int> Vi;

Vi p;
Vi aux;

int main()
{
	int num;
	bool ceros;
	while(true)
	{
		scanf("%d",&num);
		if(num==0)
			break;
		p=Vi(num);
		aux.clear();
		ceros=true;
		for(int i=0;i<num;i++)
		{
			scanf("%d",&p[i]);
			if(p[i]!=0)
			{
				aux.push_back(p[i]);
				ceros=false;
			}
		}	
		if(ceros)
			printf("0");
		else
		{
			for(int i=0;i<aux.size();i++)
			{
				if(i==aux.size()-1)
					printf("%d",aux[i]);
				else
					printf("%d ",aux[i]);
			}
		}
		printf("\n");
	}

	return 0;
}