#include <bits/stdc++.h>

using namespace std;

string preProcess(string s)
{
    if(s.length() == 0) return "^$";
    string ret = "^";
    for(int i = 0; i < s.length(); i++) 
    	ret += "#" + s.substr(i, 1);
    ret += "#$";
    return ret;
}
string longestPalindrome(string s)
{
    string T = preProcess(s);
    int n = T.length(), C = 0, R = 0; 
    int *P = new int[n];
    for(int i = 1; i < n - 1; i++)
    {
	    int i_mirror = 2 * C - i; // equals to i' = C - (i - C)
	    P[i] = (R > i)? min(R - i, P[i_mirror]) : 0;
	    // Attempt to expand palindrome centered at i
	    while(T[i + 1 + P[i]] == T[i - 1 - P[i]]) 
	    	P[i]++;
	    // If palindrome centered at i expand past R,
	    // adjust center based on expanded palindrome.
	    if(i + P[i] > R) 
	    { 
	    	C = i;
	    	R = i + P[i]; 
	    }
    }
    int maxLen = 0, centerIndex = 0;
    for(int i = 1; i < n - 1; i++)
    if(P[i] > maxLen) 
    { 
    	maxLen = P[i]; 
    	centerIndex = i; 
    }
    delete[] P;
    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}
int main()
{
	string s;
	cin>>s;
	cout<<longestPalindrome(s).size()<<endl;
	return 0;
}