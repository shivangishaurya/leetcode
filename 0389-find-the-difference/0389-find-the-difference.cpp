class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char,int>map;
        for(char c:s){
            map[c]++;
        }
        for(char a:t){
            if(map[a]==0)
            return a;
            map[a]--;
        }
        return 'y';
    }
};