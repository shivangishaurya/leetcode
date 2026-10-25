class Solution {
public:
    int houserob(vector<int> &nums,int st,int end){
        int prev1=0,prev2=0;
        for(int i=st;i<=end;i++){
            int res=max(prev2,prev1+nums[i]);
            prev1=prev2;
            prev2=res;
        }
        return prev2;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(houserob(nums,0,n-2),houserob(nums,1,n-1));
    }
};