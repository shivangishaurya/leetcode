class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if (s.length() != t.length())
            return false;
        for (int ch : s) {
            mp[ch]++;
        }
        for (int ch : t) {
            if (mp.find(ch) == mp.end())
                return false;
            mp[ch]--;
            if (mp[ch] < 0)
                return false;
        }
        return true;
    }
};