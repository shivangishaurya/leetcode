class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int half=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        half=n/2;
        for(int i=0;i<half;i++){
            ans-=nums[i];
        }
        for(int i=half;i<n;i++){
            ans+=nums[i];
        }
        return ans;
    }
};