class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<long long> pos;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                pos.push_back(i);
        }

        int m = pos.size();

        vector<long long> adjusted(m);
        for (int i = 0; i < m; i++)
            adjusted[i] = pos[i] - i;

        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefix[i + 1] = prefix[i] + adjusted[i];

        long long ans = LLONG_MAX;

        for (int l = 0; l + k - 1 < m; l++) {
            int r = l + k - 1;
            int mid = (l + r) / 2;

            long long median = adjusted[mid];

            long long leftCost =
                median * (mid - l) - (prefix[mid] - prefix[l]);

            long long rightCost =
                (prefix[r + 1] - prefix[mid + 1]) -
                median * (r - mid);

            ans = min(ans, leftCost + rightCost);
        }

        return (int)ans;
    }
};