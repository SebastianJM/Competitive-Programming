#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tamVec(char vec[])
{
	int i=0;
	while(vec[i]!=0)
		i++;
	return i;
}

int main()
{   	
	char vec[101];
	std::string resultado="";
	gets(vec);
	int tam=tamVec(vec);
	for(int i=0;i<tam;i++)
	{
		if(vec[i]=='A'||vec[i]=='O'||vec[i]=='Y'||vec[i]=='E'||vec[i]=='U'||vec[i]=='I'||vec[i]=='a'||vec[i]=='o'
			||vec[i]=='y'||vec[i]=='e'||vec[i]=='u'||vec[i]=='i')
			continue;
		else if(vec[i]<95)
		{
			resultado.push_back('.');
			resultado.push_back(vec[i]+32);
		}
		else
		{
			resultado.push_back('.');
			resultado.push_back(vec[i]);
		}
	}
	//printf("%s",resultado.c_str());
	cout << resultado;
    return 0;
}
