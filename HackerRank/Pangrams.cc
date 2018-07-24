#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
	char cadena[10000];
	vector<int> vec=vector<int>(25,0);
	gets(cadena);
	for(int i=0;cadena[i]!='\0';i++)
	{
		if(cadena[i]==' ')
			continue;
		if(cadena[i]>90)
			vec[cadena[i]-65-32]++;
		else
			vec[cadena[i]-65]++;
	}
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]==0)
		{
			printf("not pangram");
			return 0;
		}
	}
	printf("pangram");	

	return 0;
}