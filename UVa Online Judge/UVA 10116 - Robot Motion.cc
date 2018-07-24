#include <bits/stdc++.h>
using namespace std;

char matriz[13][13];
int rec[13][13];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c, f,z;
	while (1)
	{
		cin >> c >> f >> z;
		if (!c && !f && !z)
			return 0;
		memset(rec, 0, sizeof rec);
		for (int i = 0; i < c; i++)
			for (int e = 0; e < f; e++)
				cin >> matriz[i][e];
		int ac=0, af=z-1,step=0,uni,loop=0;
		while (ac >= 0 && ac < c && af >= 0 && af < f)
		{
			step++;
			if (rec[ac][af] > 0)
			{
				uni = rec[ac][af] - 1;
				loop = step - rec[ac][af] - 1;
				break;
			}
			else
				rec[ac][af] = step;
			if (matriz[ac][af] == 'N')
				ac--;
			else if (matriz[ac][af] == 'S')
				ac++;
			else if (matriz[ac][af] == 'W')
				af--;
			else if (matriz[ac][af] == 'E')
				af++;
		}
		if (loop>0)
			cout << uni << " step(s) before a loop of " << loop +1<< " step(s)" << endl;
		else
			cout << step << " step(s) to exit" << endl;
	}
	

	return 0;
}