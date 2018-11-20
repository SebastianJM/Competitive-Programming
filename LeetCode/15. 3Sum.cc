class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size(); i++) {
            int x = -nums[i];
            int l = 0,r = nums.size() - 1;
            while(l < r) {
                if(i != l && i != r && nums[l] + nums[r] == x) {
                    vector<int> ans(3);
                    ans[0] = nums[l];
                    ans[1] = nums[r];
                    ans[2] = -x;
                    sort(ans.begin(), ans.end());
                    res.insert(ans);
                    r--;
                }
                else if(nums[l] + nums[r] > x)
                    r--;
                else
                    l++;              
            }
        }
        vector<vector<int>> ans;
        for(set<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};