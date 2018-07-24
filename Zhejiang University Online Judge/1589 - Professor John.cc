#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 30
char Rel[MAX][MAX];
bool m[MAX][MAX];

void init(){
	memset(Rel, '#', sizeof Rel);
	memset(m, false, sizeof m);
}
void floyd(){
	for (int k = 0; k < MAX; k++)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				m[i][j] = m[i][j] | (m[i][k] & m[k][j]);
			}
		}
	}
}
int main(){
	int T;
	scanf("%d", &T);
	vector<int> vec = vector<int>(27,0);
	for (int k = 0; k < T; k++)
	{
		int R;
		init();
		scanf("%d", &R);
		for (int j = 0; j < R; j++)
		{
			string a;
			cin >> a;
			char S = a[0]-'A';
			char signo = a[1];
			char F = a[2] - 'A';
			Rel[S][F] = signo;
			Rel[F][S] = signo;
			if (signo == '<')
				m[S][F] = true;
			else
				m[F][S] = true;
			if (signo == '<')
				vec[F]++;
			else
				vec[S]++;
		}
		
		floyd();
		cout << "Case " << k + 1 << ":"<<endl;
		bool Hay = false;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
			{
				if (Rel[i][j] == '#' && i!=j && m[i][j])
				{
					
					
					cout << char(65 + i) << "<" << char(65 + j);
					cout << endl;
					Hay = true;
				}
			}
		
		
		
		if (Hay == false) cout << "NONE\n";
	}
	return 0;
}