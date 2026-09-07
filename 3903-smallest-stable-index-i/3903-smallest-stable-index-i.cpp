class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int min=INT_MAX;
            int max=INT_MIN;
            for(int j=0;j<=i;j++){
                if(nums[j]>max){
                    max=nums[j];
                }
            }
            for(int j=i;j<=n-1;j++){
                if(nums[j]<min){
                    min=nums[j];
                }
            }
            if(max-min<=k)
            return i;
        }
        return -1;
    }
};