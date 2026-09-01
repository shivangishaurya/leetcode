class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int val : nums) {
            map[val]++;
        }
        int m=*max_element(nums.begin(),nums.end());
        if(m<0)
        return 1;
        for (int i = 1; i <= m; i++) {
            if (map.find(i) == map.end())
                return i;
        }
        return m+1;
    }
};