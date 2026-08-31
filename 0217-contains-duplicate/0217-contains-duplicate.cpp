class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int val : nums) {
            if(map.find(val)!=map.end())return true;
            else map[val]++;
        }
        return false;
    }
};