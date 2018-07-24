#include <bits/stdc++.h>
using namespace std;

int minMaxSubarray(const vector<int>& v) {
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        mini=min(mini,v[i]);
        maxi=max(maxi,v[i]);
    }
    bool open=false;
    int ans=v.size(),con;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==mini)
        {
            con=0;
            open=true;
        }
        if(open)
            con++;
        if(v[i]==maxi && open)
        {
            ans=min(ans,con);
            open=false;
        }
    }
    open=false;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]==mini)
        {
            con=0;
            open=true;
        }
        if(open)
            con++;
        if(v[i]==maxi && open)
        {
            ans=min(ans,con);
            open=false;
        }
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    cout << minMaxSubarray(v) << "\n";
    return 0;
}
