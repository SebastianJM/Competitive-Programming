#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
vector<double> lint;
 
int main() {
	int n,calle,aux;
	double mini=0;
	cin>>n>>calle;
	lint=vector<double>(n);
	for(int i=0;i<n;i++)
		cin>>lint[i];
	sort(lint.begin(),lint.end());
	mini=lint[0];
	for(int i=1;i<n;i++)
	{
		if((lint[i]-lint[i-1])/2>mini)
			mini=(lint[i]-lint[i-1])/2;
	}
	if(calle-lint[n-1]>mini)
		mini=calle-lint[n-1];
	printf("%.10lf\n",mini);
 
	return 0;
}