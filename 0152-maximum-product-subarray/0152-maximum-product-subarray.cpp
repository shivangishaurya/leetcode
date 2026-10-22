
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxprod = nums[0];
        int prefix = nums[0];
        int suffix = nums[0];

        for (int i = 1; i < n; i++) {
            int newprefix = max({nums[i], nums[i] * prefix, nums[i] * suffix});

            int newsuffix = min({nums[i], nums[i] * prefix, nums[i] * suffix});

            prefix = newprefix;
            suffix = newsuffix;

            maxprod = max(maxprod, prefix);
        }

        return maxprod;
    }
};
