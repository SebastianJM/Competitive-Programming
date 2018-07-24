#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int n;
    int arr [25];
 
	cin>>n;
    for ( int i = 0; i < n; i++ ) 
		cin>>arr[i]; 
	int min = INT_MAX;
 
    for(int lim=0;lim<(1<<n);lim++)
	{
        int sum = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( lim & (1 << i) ) 
				sum += arr [i];
            else 
				sum -= arr [i];
        }
        if ( sum >= 0 && min > sum ) 
			min = sum;

    }
    cout<<min;
    return 0;
}