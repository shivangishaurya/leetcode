class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        int avg_gap = ceil((double)(mx - mn) / (n - 1));

        vector<int> min_b(n - 1, INT_MAX);
        vector<int> max_b(n - 1, INT_MIN);

        for (int val : nums) {

            if (val == mn || val == mx)
                continue;

            int id = (val - mn) / avg_gap;

            min_b[id] = min(min_b[id], val);
            max_b[id] = max(max_b[id], val);
        }

        int ans = 0;
        int prev = mn;

        for (int i = 0; i < n - 1; i++) {

            if (min_b[i] == INT_MAX)
                continue;

            int gap = min_b[i] - prev;

            ans = max(ans, gap);

            prev = max_b[i];
        }

        ans = max(ans, mx - prev);

        return ans;
    }
};