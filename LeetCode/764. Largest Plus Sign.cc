class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int m[N + 3][N + 3], x, y;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                m[i][j] = min(i + 1, min(j + 1, min(N - i, N - j)));
        for(int i = 0; i < mines.size(); i++) {
            x = mines[i][1];
            while(x >= 0) {
                m[mines[i][0]][x] = min(m[mines[i][0]][x], mines[i][1] - x);
                x--;
            }                
            x = mines[i][1];
            while(x < N) {
                m[mines[i][0]][x] = min(m[mines[i][0]][x], x - mines[i][1]);
                x++;
            }         
            y = mines[i][0];
            while(y >= 0) {
                m[y][mines[i][1]] = min(m[y][mines[i][1]], mines[i][0] - y);
                y--;
            }            
            y = mines[i][0];
            while(y < N) {
                m[y][mines[i][1]] = min(m[y][mines[i][1]], y - mines[i][0]);
                y++;
            }   
        }
        int ans = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                ans = max(ans, m[i][j]);
        return ans;
    }
};