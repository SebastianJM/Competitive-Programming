#include <bits/stdc++.h>
using namespace std;

#define MAX 52
typedef vector<int> vi;
typedef vector<double> vd;

struct circ
{
	double x,y;
	circ(){}
};
int main() 
{
	int n;
	double r,x,y;
	cin>>n>>r;
	vd v(n);
	vd ans(n);
	vector<circ > col(n);

	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		x=v[i];
		y=r;
		for(int j=i-1;j>=0;j--)
		{
			//cout<<i<<" con j: "<<j<<" = "<<col[j].x<<" "<<col[j].y<<endl;
			if(((x-r)>=(col[j].x-r) && (x-r)<=(col[j].x+r))||((x+r)>=(col[j].x-r) && (x+r)<=(col[j].x+r)))
			{
				//cout<<"IN "<<i<<" "<<j<<endl;
				y=max(y,col[j].y+sqrt(pow(2*r,2)-pow(fabs(x-col[j].x),2)));
			}
				
		}
		col[i].x=x;
		col[i].y=y;
		ans[i]=y;
		//cout<<"PARA i:"<<i<<"="<<col[i].x<<" "<<col[i].y<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%.10lf ",ans[i]);
	}
		
	return 0;
}