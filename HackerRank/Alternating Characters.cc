#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
	string vec;
	
	int T,tam;
	scanf("%d", &T);
	getchar();
	for (int e = 0; e < T; e++)
	{		
		getline(cin, vec);
		vector<char> vc(vec.begin(),vec.end());
		tam = vec.size();
		for (int i = 0; i<vc.size()-1;)
		{
			while (vc.size()>i+1 && vc[i] == vc[i + 1])
				vc.erase(vc.begin()+i+1);
			i++;
		}
		
		printf("%d\n", tam - vc.size());
		
	}
	return 0;
}