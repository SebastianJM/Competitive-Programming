class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = LLONG_MAX - INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            long long x = target-nums[i];
            int l = 0, r = nums.size() - 1;
            while(l < r)
            {
                if(i != l && i != r && labs(nums[i] + nums[l] + nums[r] - target) < labs(ans - target)) { 
                    ans=nums[i]+nums[l]+nums[r];
                }    
                if(nums[l] + nums[r] >= x)
                    r--;
                else
                    l++;              
            }
        }
        return ans;
    }
};