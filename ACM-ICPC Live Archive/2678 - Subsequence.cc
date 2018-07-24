#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int b[100005];
int main()
{
    int n, s;
    while (scanf("%d %d", &n, &s) != EOF)
    {
        b[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            b[i] += b[i-1];
        }
        int ans = n+1, i = 1;
        for (int j = 1; j <= n; j++)
        {
            if (b[i-1] > b[j]-s)
                continue;
            while (b[i] <= b[j]-s)
                i++;
            ans = min(ans, j-i+1);
        }
        printf("%d\n", ans == n+1?0:ans);
    }
    return 0;
}