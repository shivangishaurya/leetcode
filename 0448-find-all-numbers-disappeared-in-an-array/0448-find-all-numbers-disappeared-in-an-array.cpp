class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>map;
        for(int val:nums){
            map[val]++;
        }
        for(int i=1;i<=n;i++){
        if(map.find(i)==map.end())
        ans.push_back(i);
        }
        return ans;
    }
};