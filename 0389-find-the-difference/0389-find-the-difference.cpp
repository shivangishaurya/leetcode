class Solution {
public:
    char findTheDifference(string s, string t) 
    {
       int ans=0;
       for(char c:s){
        ans^=c;
       }
       for(char a:t){
        ans^=a;
       }
       return ans;
    }
};