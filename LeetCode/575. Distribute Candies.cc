class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        for(int i = 0; i < candies.size(); i++)
            s.insert(candies[i]);
        return min(candies.size() / 2, s.size());
    }
};