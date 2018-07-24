#include <bits/stdc++.h>
using namespace std;
#define PORC 0.0000001
struct polygon
{
	char tipo;
	double x0,y0,x1,y1,x2,y2,r;
	//Circle and Square 
	polygon(char ptipo,double px0,double py0,double pr):tipo(ptipo),x0(px0),y0(py0),r(pr){}
	//Triangle 
	polygon(char ptipo,double px0,double py0,double px1,double py1,double px2,double py2):tipo(ptipo),x0(px0),y0(py0),x1(px1),y1(py1),x2(px2),y2(py2){}
};
vector<polygon> vp;
int t,n,a,maxx,minx,maxy,miny;
char c;


double side(double x0,double y0,double x1,double y1)
{
	return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}
double t_area(double x0,double y0,double x1,double y1,double x2,double y2)
{
	double area,l1,l2,l3;
	l1=side(x0,y0,x1,y1); 
	l2=side(x1,y1,x2,y2); 
	l3=side(x2,y2,x0,y0); 
	//cout<<l1<<" "<<l2<<" "<<l3<<endl;
	area=(l1+l2+l3)/2;
	//cout<<"ARR " <<area<<endl;
	return sqrt(area*(area-l1)*(area-l2)*(area-l3));
}
int solve()
{
	int ans=0;
	for(int i=minx;i<=maxx;i++)
		for(int e=miny;e<=maxy;e++)
		{
			for(int k=0;k<n;k++)
			{
				if(vp[k].tipo=='T')
				{
					//cout<<vp[k].x1<<" "<<vp[k].y1<<" "<<vp[k].x2<<" "<<vp[k].y2<<" "<<i<<" "<<e<<endl;
					//cout<<"--------"<<t_area(vp[k].x0,vp[k].y0,vp[k].x1,vp[k].y1,vp[k].x2,vp[k].y2)<<" = "<<t_area(vp[k].x0,vp[k].y0,vp[k].x1,vp[k].y1,(double)i,(double)e)<<"+"<<(int)t_area(vp[k].x1,vp[k].y1,vp[k].x2,vp[k].y2,(double)i,(double)e)<<"+ "<<t_area(vp[k].x2,vp[k].y2,vp[k].x0,vp[k].y0,(double)i,(double)e)<<endl;
					double area=t_area(vp[k].x0,vp[k].y0,vp[k].x1,vp[k].y1,vp[k].x2,vp[k].y2);
					double l1=t_area(vp[k].x0,vp[k].y0,vp[k].x1,vp[k].y1,(double)i,(double)e);
					double l2=t_area(vp[k].x1,vp[k].y1,vp[k].x2,vp[k].y2,(double)i,(double)e);
					double l3=t_area(vp[k].x2,vp[k].y2,vp[k].x0,vp[k].y0,(double)i,(double)e);
					//l1+=l2+l3;
					area-=l1+l2+l3;
					//cout<<area<<endl;
					if(area>=-PORC && area<=PORC)
					{
						//cout<<"IN"<<endl;
						ans++;
						break;
					}
				}                         
				else if(vp[k].tipo=='C')
				{
					if(side(vp[k].x0,vp[k].y0,i,e)<=vp[k].r)
					{
						ans++;
						break;
					}
				}
				else
				{
					if(vp[k].x0<=i && vp[k].x0+vp[k].r>=i && vp[k].y0<=e && vp[k].y0+vp[k].r>=e)
					{
						ans++;
						break;
					}
				}
			}
		}
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		vp=vector<polygon>();
		minx=miny=INT_MAX;
		maxx=maxy=INT_MIN;
		for(int i=0;i<n;i++)
		{
			cin>>c;
			if(c=='C')
			{
				vp.push_back(polygon(c,0,0,0));
				a=vp.size()-1;
				cin>>vp[a].x0>>vp[a].y0>>vp[a].r;
				
				minx=min(minx,(int)(vp[a].x0-vp[a].r));
				maxx=max(maxx,(int)(vp[a].x0+vp[a].r));
				miny=min(miny,(int)(vp[a].y0-vp[a].r));
				maxy=max(maxy,(int)(vp[a].y0+vp[a].r));
			}
			else if(c=='S')
			{
				vp.push_back(polygon(c,0,0,0));
				a=vp.size()-1;
				cin>>vp[a].x0>>vp[a].y0>>vp[a].r;
				
				minx=min(minx,(int)vp[a].x0);
				maxx=max(maxx,(int)(vp[a].x0+vp[a].r));
				miny=min(miny,(int)vp[a].y0);
				maxy=max(maxy,(int)(vp[a].y0+vp[a].r));
			}
			else if(c=='T')
			{
				vp.push_back(polygon(c,0,0,0,0,0,0));
				a=vp.size()-1;
				cin>>vp[a].x0>>vp[a].y0>>vp[a].x1>>vp[a].y1>>vp[a].x2>>vp[a].y2;
				
				minx=min(minx,(int)(min(vp[a].x0,min(vp[a].x1,vp[a].x2))));
				maxx=max(maxx,(int)(max(vp[a].x0,max(vp[a].x1,vp[a].x2))));
				miny=min(miny,(int)(min(vp[a].y0,min(vp[a].y1,vp[a].y2))));
				maxy=max(maxy,(int)(max(vp[a].y0,max(vp[a].y1,vp[a].y2))));
				//cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
			}
		}
		cout<<solve()<<endl;
	}
	return 0;
}