class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        int val=0,res=0;
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        for(int i=0;i<n;i++){
            val+=satisfaction[i]; 
            if(val<0)break;
            res+=val;
        }
        return res;
    }
};