#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char cad[100000];
	int i,l,cond;
	cond=0;
	while(gets(cad))
	{
		l=strlen(cad);
		
		for(i=0;i<l;i++)
		{
			if(cad[i]=='"')
			{
				if(cond==0)
				{
					printf("``");
					cond=1;
				}
				else
				{
					printf("''");
					cond=0;
				}
			}
			else
				printf("%c",cad[i]);
		}
		printf("\n");
	}
	return 0;
}