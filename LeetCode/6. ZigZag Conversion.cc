class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vs = vector<string>(numRows, "");
        int h = 0, dir = 1, n = s.size();
        for(int pos = 0; pos < n; pos++) {
            vs[h].push_back(s[pos]);
            h += dir;
            if(h >= numRows) {
                dir *= -1;
                if(numRows > 1)
                    h -= 2;
                else
                    h--;
            }
            else if(h < 0) {
                dir *= -1;
                if(numRows > 1)
                    h += 2;
                else
                    h++;
            }
        }
        string ans = "";
        for(int i = 0; i < numRows; i++)
            ans += vs[i];
        return ans;
    }
};