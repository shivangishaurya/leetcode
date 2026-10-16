class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int idx=0;
        for(int num:nums){
            if(map.find(num)!=map.end() && abs(map[num]-idx)<=k)
            return true;
            map[num]=idx;
            idx++;
        }
        return false;
    }
};