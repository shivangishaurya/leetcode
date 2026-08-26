class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        n=k
        while(self.has(nums,k)):
            k+=n
        return k
    def has(self,nums,k):
        for i in nums:
            if i==k:
                return True
        return False
