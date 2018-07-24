#include <bits/stdc++.h>

using namespace std;

map<string,int> mes;
map<string,int> dia;

void ini()
{
	mes["JAN"]=31;
	mes["FEB"]=28;
	mes["MAR"]=31;
	mes["APR"]=30;
	mes["MAY"]=31;
	mes["JUN"]=30;
	mes["JUL"]=31;
	mes["AUG"]=31;
	mes["SEP"]=30;
	mes["OCT"]=31;
	mes["NOV"]=30;
	mes["DEC"]=31;
	dia["SUN"]=0;
	dia["MON"]=1;
	dia["TUE"]=2;
	dia["WED"]=3;
	dia["THU"]=4;
	dia["FRI"]=5;
	dia["SAT"]=6;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ini();
	int t;
	cin>>t;
	string d,m;
	while(t--)
	{
		cin>>m>>d;
		int lim=mes[m];
		int itt=dia[d];
		int suma=0;
		for(int i=0;i<lim;i++)
		{
			if(itt==5||itt==6)
				suma++;
			itt++;
			itt%=7;
		}
		cout<<suma<<endl;
	}
	return 0;
}