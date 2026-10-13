class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
                idx++;
            }
        }
        while (idx < n) {
            ans.push_back(0);
            idx++;
        }
        nums = ans;
    }
};