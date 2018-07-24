#include <iostream>
#include <bitset>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAXPRIME 60
bitset< MAXPRIME > criba;
vector< int > primo;
void sieve()
{
    criba.set();
    criba[0] = 0;
    criba[1] = 0;
    for (int i=2; i<MAXPRIME; i++)
    {
        if ( criba[i] )
        {
            primo.push_back( i );
            for (int j=i<<1; j<MAXPRIME; j+=i)
                criba[j] = 0;
        }
    }
}

int main()
{
    int a,b;
    
    primo.push_back( 0 );
    sieve();
    cin>>a>>b;
    for(int i=0;i<primo.size();i++)
    {
        if(primo[i]==a)
        {
            if(primo[i+1]==b)
                cout<<"YES";
            else
                cout<<"NO";
            return 0;
        }
    }
    return 0;
}