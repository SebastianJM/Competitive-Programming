class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
                q.push(s[i]);
            else {
                if(q.empty() || (s[i] == '}' && q.top() != '{') || (s[i] == ')' && q.top() != '(') || (s[i] == ']' && q.top() != '['))
                    return false;
                q.pop();
            }
            
        }
        if(!q.empty())
            return false;
        return true;
    }
};