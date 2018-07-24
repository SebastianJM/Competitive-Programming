#include <bits/stdc++.h>

using namespace std;

#define INF (-1)*(INT_MIN-2)

int Tc;
int magrid[502][502];
int ans[502][502];
int f,c;

bool cumple(int n)
{
    ans[0][0]=n;
    for(int i=0;i<f;i++)
    {
        for(int e=0;e<c;e++)
        {
            if(i>0 && e>0)
            {
            	if(ans[i-1][e]<=0 && ans[i][e-1]<=0)
            		ans[i][e]=INF;
            	else if(ans[i-1][e]<=0)
            		ans[i][e]=magrid[i][e]+ans[i][e-1];
            	else if(ans[i][e-1]<=0)
            		ans[i][e]=magrid[i][e]+ans[i-1][e];
            	else
                	ans[i][e]=max(magrid[i][e]+ans[i-1][e],magrid[i][e]+ans[i][e-1]);
            }
            else if(i>0)
                ans[i][e]=ans[i-1][e]<=0?INF:ans[i-1][e]+magrid[i][e];
            else if(e>0)
                ans[i][e]=ans[i][e-1]<=0?INF:ans[i][e-1]+magrid[i][e];
        }
 
    }

    if(ans[f-1][c-1]>0)
        return true;
    else 
        return false;
}
int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Tc ;
    
    
    while(Tc--)
    {
        cin>>f>>c;
        
        for(int i=0;i<f;i++)
            for(int e=0;e<c;e++)
                cin>>magrid[i][e];
            
        int lo = 1, hi = INT_MAX;
        while(lo < hi) 
        {
            int mid = lo + (hi-lo)/2;
            if(cumple(mid) == true)
                hi = mid;  
            else
                lo = mid + 1;
              
            
        }
        cout<<lo<<endl;
       
    }
    
	return 0;
}