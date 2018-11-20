class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> ban;
        map<string,int> words;
        for(int i = 0; i < banned.size(); i++)
            ban.insert(banned[i]);
        string s = "";
        int ans = 0;
        //cout<<paragraph;
        for(int i = 0; i < paragraph.size(); i++) {
            cout << paragraph[i];
            if(paragraph[i] == ' ') {
                words[s]++;
                s = "";
            }
            else if(isalpha(paragraph[i])) {
                s += tolower(paragraph[i]);
            }
        }
        
        if(s.size() > 0)
            words[s]++;
        
        for(map<string,int>::iterator it = words.begin(); it != words.end(); it++)
            if(ban.find((*it).first) == ban.end() && (*it).second > ans) {
                s = (*it).first;
                ans = (*it).second;
            }
        return s;
    }
};