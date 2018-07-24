//https://www.hackerrank.com/challenges/is-fibo/submissions/code/11580399

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<long long int> Vi;

Vi fibonacci;

void LlenarFibonacci()
{
	for(int i=2;i<fibonacci.size();i++)
	{
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	}
}
int EsFibonacci(long long int n)
{
	for(int i=0;i<fibonacci.size();i++)
	{
		if(fibonacci[i]==n)
			return 1;
		if(fibonacci[i]>n)
			return 0;
	}
    return 0;
}
int main() 
{
    int T;
	long long int num;
	fibonacci=vector<long long int>(55);
	scanf("%d",&T);
	fibonacci[0]=0;
	fibonacci[1]=1;
	LlenarFibonacci();
	for(int i=0;i<T;i++)
	{
		scanf("%lld",&num);
		if(EsFibonacci(num))
			printf("IsFibo\n");
		else
			printf("IsNotFibo\n");
	}

    return 0;
}
