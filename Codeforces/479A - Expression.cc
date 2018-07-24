#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(3);
    int m,n;
    cin>>vec[0]>>vec[1]>>vec[2];
    m=max(vec[0]+vec[1]+vec[2],vec[0]*vec[1]*vec[2]);
    n=max((vec[0]+vec[1])*vec[2],vec[0]*(vec[1]+vec[2]));
    cout<<max(m,n);
    return 0;
}