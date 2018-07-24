#include <bits/stdc++.h>
using namespace std;

int main() 
{
	vector<double> cost;
	double prom;
	int n;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		cost=vector<double>(n);
		prom=0.0;
		for(int i=0;i<n;i++)
		{
			cin>>cost[i];
			prom+=cost[i];
		}
		prom/=n;
		double ans_p=0.0,ans_n=0.0;
		for(int i=0;i<n;i++)
		{
			if(cost[i]>prom)
				ans_p+=(long long)((cost[i]-prom)*100.0)/100.0;
			else if(cost[i]<prom)
				ans_n+=(long long)((cost[i]-prom)*-100.0)/100.0;
		}
		double ans=(ans_n<ans_p)?ans_p:ans_n;
		printf("$%.2lf\n",ans);
	}
	return 0;
}