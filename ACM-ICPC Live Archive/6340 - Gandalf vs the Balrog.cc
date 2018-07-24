#include <stdio.h>
#include <string.h>

#define Max 1000005

using namespace std;

int a[Max];

int main(){
	int n,i,j,t,m,x,y;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		if(m==0)
			printf("2 %d\n",n);
		else
		{
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&x,&y);
				a[y]=x;
			}
			for(i=n;i>0;i++)
			{
				if(!a[i])
					break;
			}
			if(i==n)
				printf("2 %d\n",n);
			else
				printf("1\n");
		}
	}
	return 0;
}