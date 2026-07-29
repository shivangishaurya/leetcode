class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a;
       double n=nums1.size();
       double m=nums2.size();
       for (int i=0;i<n;i++){
        a.push_back(nums1[i]);
       }
       for(int j=0;j<m;j++){
        a.push_back(nums2[j]);
       }
       sort(a.begin(),a.end());
       int count=a.size();
       if(count%2==0){
        int mid1=a[(count/2)-1];
        int mid2=a[count/2];
        return double (mid1+mid2)/2.0;
       }
       else{
        return double (a[count/2]);
       }
    }
};