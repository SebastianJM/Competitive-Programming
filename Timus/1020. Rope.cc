#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

int main()
{
	int n;
	double radio;
	double suma=0;
	cin>>n>>radio;
	vector<pair<double,double>> vec=vector<pair<double,double>>(n);
	for(int i=0;i<n;i++)
		cin>>vec[i].first>>vec[i].second;
	for(int i=0;i<n-1;i++)
		suma+=sqrt(pow(vec[i].first-vec[i+1].first,2)+pow(vec[i].second-vec[i+1].second,2));
	suma+=sqrt(pow(vec[0].first-vec[n-1].first,2)+pow(vec[0].second-vec[n-1].second,2));
	suma+=2*(3.14159265)*radio;
	printf("%.2lf",suma);	
	return 0;
}