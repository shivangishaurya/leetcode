class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxVol=0,i=0,j=n-1;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            maxVol=max(maxVol,w*h);
            height[i]<height[j]?i++:j--;  
        }
        return maxVol;
    }
};