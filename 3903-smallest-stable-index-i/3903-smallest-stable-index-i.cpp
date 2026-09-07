class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>maxarray;
        vector<int>minarray;
        int max=nums[0];
        maxarray.push_back(max);
        for(int i=1;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
            }
            maxarray.push_back(max);
        }
        int min=nums[n-1];
        minarray.push_back(min);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<min){
                min=nums[i];
            }
            minarray.push_back(min);
        }
        reverse(minarray.begin(),minarray.end());
        for(int i=0;i<n;i++){
            if(maxarray[i]-minarray[i]<=k)
            return i;
        }
        return -1;
    }
};