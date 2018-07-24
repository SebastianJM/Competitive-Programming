#include <bits/stdc++.h>

using namespace std;

int main()
{
	int v_kang[30],v_kiwi[30],ans_kang,ans_kiwi;
	memset(v_kang,0,sizeof v_kang);
	memset(v_kiwi,0,sizeof v_kiwi);
	v_kang['K'-'A']=1;
	v_kang['A'-'A']=2;
	v_kang['N'-'A']=1;
	v_kang['G'-'A']=1;
	v_kang['R'-'A']=1;
	v_kang['O'-'A']=2;
	v_kiwi['K'-'A']=1;
	v_kiwi['I'-'A']=3;
	v_kiwi['W'-'A']=1;
	v_kiwi['B'-'A']=1;
	v_kiwi['R'-'A']=1;
	v_kiwi['D'-'A']=1;
	string s;
	ans_kang=ans_kiwi=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		ans_kang+=v_kang[toupper(s[i])-'A'];
		ans_kiwi+=v_kiwi[toupper(s[i])-'A'];
	}
	if(ans_kang>ans_kiwi)
		cout<<"Kangaroos"<<endl;
	else if(ans_kiwi>ans_kang)
		cout<<"Kiwis"<<endl;
	else
		cout<<"Feud continues"<<endl;

	return 0;
}