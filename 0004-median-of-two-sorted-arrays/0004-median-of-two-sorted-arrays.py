class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        n=len(nums1)
        m=len(nums2)
        nums3=[]
        for i in range(n):
            nums3.append(nums1[i])
        for j in range (m):
            nums3.append(nums2[j])    
        nums3.sort()
        l=len(nums3)
        if l%2==1:
            median=nums3[l//2] 
        else:
            median=(nums3[l//2]+nums3[l//2-1])/2.0
        return median                    