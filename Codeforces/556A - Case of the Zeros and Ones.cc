#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    cout<<n- std::min(count(s.begin(),s.end(),'0'),count(s.begin(),s.end(),'1'))*2;
    return 0;
}