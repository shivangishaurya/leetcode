class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        nums3=nums1+nums2
        nums3.sort()
        l=len(nums3)
        if l%2==1:
            median=nums3[l//2]
        else:
            median=(nums3[l//2]+nums3[l//2-1])/2.0
        return median    