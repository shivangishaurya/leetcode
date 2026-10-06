class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        int j=0;
        for(int i=m;i<nums1.size();i++){
            swap(nums1[i],nums2[j]);
            j++;
        }
        vector<int>arr;
        int left=0,right=m;
        while(left<m&&right<nums1.size()){
            if(nums1[left]<=nums1[right]){
                arr.push_back(nums1[left]);
                left++;
            }
            else {
            arr.push_back(nums1[right]);
            right++;
            }
        }
        while(right<nums1.size()){
            arr.push_back(nums1[right]);
            right++;
        }
        while(left<m){
            arr.push_back(nums1[left]);
            left++;
        }
        nums1.swap(arr);
    }
};