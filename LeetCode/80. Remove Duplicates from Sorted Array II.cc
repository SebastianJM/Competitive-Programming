class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = INT_MIN, ind = 0, q = 0;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] != prev) {
                nums[ind++] = nums[i];
                prev = nums[i];
                q = 1;
            }
            else if(q < 2) {
                nums[ind++] = nums[i];
                prev = nums[i];
                q++;
            }
        }
        return ind;
    }
};