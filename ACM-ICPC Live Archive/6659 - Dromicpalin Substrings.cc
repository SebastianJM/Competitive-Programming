#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,t=0;
	cin>>n;
	while(t<n)
	{
		int pun=0;
		string s;
		cin>>s;
		pun+=s.length();
		for(int i=0;i<s.length()-1;i++)
		{
			vector<int> abc(26,0);
			abc[s[i]-'a']++;
			for(int e=i+1;e<s.length();e++)
			{
				abc[s[e]-'a']++;
				int k=0;
				if((e-i)%2==1)
				{
					for(k=0;k<26;k++)
						if(abc[k]>0 && abc[k]%2==1)
							break;
					if(k==26)
						pun++;
				}
				else
				{
					int con=0;
					for(k=0;k<26;k++)
						if(abc[k]>0 && abc[k]%2==1)
						{
							if(con==0)		
								con++;
							else 
								break;
						}
					if(k==26)
						pun++;
				}
			}
		}
		cout<<"Case "<<t+1<<": "<<pun<<endl;
		t++;
	}
	return 0;
}