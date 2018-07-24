#include <bits/stdc++.h>
using namespace std;

struct punto
{
	int x,y,v;
	punto(int xx,int yy):x(xx),y(yy){}
	bool operator<(const punto &a) const {
        if (x != a.x)
            return x < a.x;
        if (y != a.y)
            return y < a.y;
        return false;
    }
};
struct segm
{
	int x1,y1,x2,y2;
	segm(int px1,int py1,int px2,int py2):x1(px1),y1(py1),x2(px2),y2(py2){}
	bool operator < (const segm &seg) const
	{
		return x1<seg.x1;
	}
};
typedef vector<int> vi;
typedef vector<punto> vp;
typedef vector<segm> vs;
vp p,s;
int n,m,top;
vi t;

void inc(int i, int val) // Increases v[i] by "val"
{
	 while (i <= top){
        t[i] += val;
        i += (i & -i);
    }
}

void inc_segm(int a,int b)
{
	inc(a,1);
	inc(b+1,-1);
}
int rsq(int i) // Range Sum Query in range [0, x]
{
	int sum = 0;
    while (i > 0){
        sum += t[i];
        i -= (i & -i);
    }
    return sum;
}

vs build_segm()
{
	vs segmentos;
	int x1,y1,x2,y2;

	for(int i=1;i<m;i++)
	{
		if(s[i-1].x==s[i].x)
		{
			if(s[i-1].y<s[i].y)
			{
				x1=s[i-1].x; y1=s[i-1].y;
				x2=s[i].x; y2=s[i].y;
			}
			else
			{
				x1=s[i].x; y1=s[i].y;
				x2=s[i-1].x; y2=s[i-1].y;
			}
			segmentos.push_back(segm(x1,y1,x2,y2));
		}				
	}
	if(s[m-1].x==s[0].x)
	{
		if(s[m-1].y<s[0].y)
		{
			x1=s[m-1].x; y1=s[m-1].y;
			x2=s[0].x; y2=s[0].y;
		}
		else
		{
			x1=s[0].x; y1=s[0].y;
			x2=s[m-1].x; y2=s[m-1].y;
		}
		segmentos.push_back(segm(x1,y1,x2,y2));
	}
	
	return segmentos;
}

long long solve()
{
	map<int,int> cx,cy;
	for(int i=0;i<n;i++)
		cx[p[i].x]=cy[p[i].y]=0;
	for(int i=0;i<m;i++)
		cx[s[i].x]=cy[s[i].y]=0;
	int xx_val=0,yy_val=1;
	for(auto &xx : cx)
		xx.second=++xx_val;
	for(auto &yy : cy)
		yy.second=yy_val+=2;
	top=yy_val;
	t=vi(yy_val+1,0);
	for(int i=0;i<n;i++)
		p[i].x=cx[p[i].x],p[i].y=cy[p[i].y]+1;
	for(int i=0;i<m;i++)
		s[i].x=cx[s[i].x],s[i].y=cy[s[i].y];
		
	sort(p.begin(),p.end());
	
	vs segmentos=build_segm();
	sort(segmentos.begin(),segmentos.end());
	
	long long ans=0;
	int it_s=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].y>=yy_val)
		{
			ans+=p[i].v;
			continue;
		}
		while(it_s<segmentos.size() && segmentos[it_s].x1<=p[i].x)
		{
			inc_segm(segmentos[it_s].y1,segmentos[it_s].y2);
			it_s++;
		}
		if(!(rsq(p[i].y) & 1))
			ans+=p[i].v;
	}
	
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m)
	{
		p=vp(n,punto(0,0));
		s=vp(m,punto(0,0));
		
		for(int i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
			p[i].v=i+1;
		}
		for(int i=0;i<m;i++)
			cin>>s[i].x>>s[i].y;
		
		cout<<solve()<<endl;
	}
	return 0;
}