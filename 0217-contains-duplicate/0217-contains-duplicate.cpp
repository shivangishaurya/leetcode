class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int val : nums) {
            map[val]++;
            auto it=map.find(val);
            if(it!=map.end() && it->second>1)
            return true;
        }
        return false;
    }
};