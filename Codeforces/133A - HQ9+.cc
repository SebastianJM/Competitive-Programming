#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string cad;
	cin>>cad;
	for(int i=0;i<cad.length();i++)
	{
		if(cad[i]=='H'||cad[i]=='Q'||cad[i]=='9')
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}