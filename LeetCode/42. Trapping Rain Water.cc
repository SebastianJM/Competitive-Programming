class Solution {
public:
    int trap(vector<int>& height) {
        int n, maxi, ans, ac, from;
        n = height.size();
        ans = 0;
        ac = 0;
        maxi = 0;
        from = 0;
        for(int i = 0;i < n; i++) {
            if(height[i] >= maxi) {
                ans += ac;
                for(int k = 0;k < i; k++)
                    height[k] = maxi;
                maxi = height[i];
                from = i;
                ac = 0;
            }
            else {
                ac += maxi - height[i];
            }
        }
        ac = 0;
        maxi = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(height[i] >= maxi) {
                ans += ac;
                maxi = height[i];
                ac = 0;
            }
            else {
                ac += maxi - height[i];
            }
        }
        return ans;
    }
};