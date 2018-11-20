class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1])
                candies[i] = candies[i + 1] + 1;
        }
        for(int i = 1; i < n - 1; i++)
            if(ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i - 1], candies[i + 1]) + 1;
        for(int i = 0; i < n; i++)
            ans += candies[i];
        return ans;
    }
};