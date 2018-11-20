class Solution { 
public:
    void go(string s, int op, int cl, int n, vector<string> &res) {
        if(s.size() == n) {
            res.push_back(s);
            return;
        }
        if(op < n / 2) {
            go(s + "(", op + 1, cl, n, res);
        }
        if(cl < op) {
            go(s + ")", op, cl + 1, n, res);
        }
    } 
    vector<string> generateParenthesis (int n) {
        
        vector<string> v;
        go("", 0, 0, n * 2, v);
        return v;
    }
};