#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m[503][503];

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	int f, c,q,u,v,low,hig,midd,lo,hi,mid;
	while (1)
	{
		cin >> f >> c;
		if (f == 0 && c == 0)
			return 0;
		for (int i = 0; i < f; i++)
			for (int e = 0; e < c; e++)
				cin >> m[i][e];
		cin >> q;
		for (int s = 0; s < q; s++)
		{
			cin >> u >> v;
			int res=0;
			for (int i = 0; i < f; i++)
			{
				low = 0; hig = c-1;
				while(low < hig) 
				{
				  midd = low + (hig-low)/2;
				  if(m[i][midd]>=u)
					hig = midd;  
				  else
					low = midd + 1;
				}
				if(m[i][low]>=u && m[i][low]<=v)
				{
					int mini = min(f - i - 1, c - low - 1);
					lo = 0; hi = mini;
					while (lo < hi) {
						mid = lo + (hi - lo + 1) / 2; 
						if (m[i+mid][low+mid] >v)
							hi = mid - 1;
						else
							lo = mid;
					}
					lo++;
					res = max(lo, res);
					
				}
			}
			cout << res << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}