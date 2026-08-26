class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=k;
        while(has(nums,k))
        {
            k+=n;
        }
        return k;
    }
    bool has(vector<int>nums,int k)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==k)return true;
        }
        return false;
    }
};