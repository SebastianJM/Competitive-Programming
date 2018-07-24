#include <stdio.h>
#include <string.h>

int main()
{
	char cad[100];
	int test, lon, total;
	scanf("%d",&test);
	int contador=1;
	getchar();
	while(test--)
	{
		total=0;
		gets(cad);
		lon=strlen(cad);
		for(int i=0;i<lon;i++)
		{
			if(cad[i]=='a'||cad[i]=='d'||cad[i]=='g'||cad[i]=='j'||cad[i]=='m'||cad[i]=='p'||cad[i]=='t'||cad[i]=='w'||cad[i]==' ')
			{
				total+=1;
				continue;
			}
			if(cad[i]=='b'||cad[i]=='e'||cad[i]=='h'||cad[i]=='k'||cad[i]=='n'||cad[i]=='q'||cad[i]=='u'||cad[i]=='x')
			{
				total+=2;
				continue;
			}
			if(cad[i]=='c'||cad[i]=='f'||cad[i]=='i'||cad[i]=='l'||cad[i]=='o'||cad[i]=='r'||cad[i]=='v'||cad[i]=='y')
			{
				total+=3;
				continue;
			}
			if(cad[i]=='s'||cad[i]=='z')
			{
				total+=4;
				continue;
			}
		}
		printf("Case #%d: %d\n",contador,total);
		contador++;
	}
	return 0;
}