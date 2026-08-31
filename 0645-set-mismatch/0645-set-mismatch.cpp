class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> ans;
        int n = nums.size();
        for (int val : nums){
            map[val]++;
    }
    for(auto it:map){
        if(it.second>1)
        ans.push_back(it.first);
    }
        for (int i = 1; i <= n; i++) {
            if (map.find(i) == map.end())
                ans.push_back(i);
        }
        return ans;
    }
};