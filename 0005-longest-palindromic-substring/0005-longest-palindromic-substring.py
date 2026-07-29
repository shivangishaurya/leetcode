class Solution(object):
    def longestPalindrome(self, s):
        result=""

        for i in range(len(s)):
            left=i
            right=i
            while left>=0 and right<len(s) and s[left]==s[right]:
                sub=s[left:right+1]
                left-=1
                right+=1
                if(len(sub)>len(result)):
                    result=sub
            left=i
            right=i+1
            while left>=0 and right<len(s) and s[left]==s[right]:
                sub=s[left:right+1]
                left-=1
                right+=1
                if(len(sub)>len(result)):
                    result=sub       
        return result           