class Solution {
public:
    int romanToInt(string s) {
        int data[26];
        data['I' - 'A'] = 1; data['V' - 'A'] = 5;
        data['X' - 'A'] = 10; data['L' - 'A'] = 50;
        data['C' - 'A'] = 100; data['D' - 'A'] = 500; data['M' - 'A'] = 1000;
        int result = 0;
        for(int i = 0; s[i]; i++)
        if(s[i + 1] && data[s[i] - 'A'] < data[s[i + 1] - 'A'])
        {
            result += data[s[i + 1] - 'A'] - data[s[i] - 'A'];
            i++;
        }
        else result += data[s[i] - 'A'];
        return result;

    }
};