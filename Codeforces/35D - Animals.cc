#include <bits/stdc++.h>
using namespace std;

int N,M;
int C[103][10003];
int W[103],V[103];
int knap()
{
	for(int i = 0; i <= N; i++) C[i][0] = 0,V[i]=1;
	for(int w = 0; w <= M; w++) C[0][w] = 0;
		// DP
	for(int i = 1; i <= N; i++) // Para cada item i
		for(int w = 1; w <= M; w++) // Para cada mochila de capacidad w
			if(W[i] > w) C[i][w] = C[i - 1][w]; // Este item no entra en la mochila
			else C[i][w] = max(C[i - 1][w] , C[i - 1][w - W[i]] + V[i]);
	return C[N][M];
}
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a;
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		cin>>a;
		W[i]=(N-i+1)*a;
	}
	cout<<knap()<<endl;
	return 0;
}