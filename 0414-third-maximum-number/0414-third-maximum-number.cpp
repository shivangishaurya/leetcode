class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int>mp;int max=0;
        for(int num:nums){
            mp[num]++;
            if(max<num)max=num;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        int c=0;
        for(int i=0;i<2;i++){
            c++;
            pq.pop();
        }
        if(c>=2&&(!pq.empty()))return pq.top().first;
        return max;
    }
};